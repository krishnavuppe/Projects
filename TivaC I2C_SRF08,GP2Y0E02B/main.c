/*
 * assignment.c
 *
 *  Created on: 15.02.2016
 *      Author: Krishna Vuppe
 *
 *
 * Test project in order to set up I2C communication with SHARP GP2Y0E02B IR sensor
 * and SRF08 Ultrasonic sensor through I2C peripheral of Tiva C Launchpad
 */

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/i2c.h"
#include "sensorlib/i2cm_drv.h"


tI2CMInstance g_sI2CInst;
double US, IR;

void USI2CIntHandler(void)
{
    //
    // Pass through to the I2CM interrupt handler provided by sensor library.
    // This is required to be at application level so that I2CMIntHandler can
    // receive the instance structure pointer as an argument.
    //
    I2CMIntHandler(&g_sI2CInst);
}

// I2C read function for reading SRF08 and GP2Y0E02B sensors
uint32_t readI2C0byte(uint8_t device_address, uint8_t device_register)
{
	    while(I2CMasterBusy(I2C0_BASE)){	}
		I2CMasterSlaveAddrSet(I2C0_BASE, device_address, false);	// sets slave address that master puts on the bus
																	// to initiate a read f the slave; flag set to write, i.e. 'false'

		while(I2CMasterBusy(I2C0_BASE)){	}						// wait until transaction finished (Slave ACK)

		I2CMasterDataPut(I2C0_BASE, device_register);				// store address of slave register which is to be read
		I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);	// send single address byte, i.e. device_register

		while(I2CMasterBusy(I2C0_BASE)){	}						// wait until transaction finished (Slave ACK)

		I2CMasterSlaveAddrSet(I2C0_BASE, device_address, true);		// sets slave address that master puts on the bus
																	// to a read f the slave; flag set to read, i.e. 'true'
		I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);	// receive single data word, i.e. register content

		while(I2CMasterBusy(I2C0_BASE)){	}						// wait until transaction finished (Slave ACK and DATA)

		return I2CMasterDataGet(I2C0_BASE);							// return data
}

// I2C write function for writing SRF08 and GP2Y0E02B sensors
void writeI2C0byte(uint8_t device_address, uint8_t device_register, uint8_t register_data)
{
	    while(I2CMasterBusy(I2C0_BASE)){	}
		I2CMasterSlaveAddrSet(I2C0_BASE, device_address, false);	// sets slave address that master puts on the bus
																	// to initiate a write to the slave; flag set to write, i.e. 'false'
		while(I2CMasterBusy(I2C0_BASE)){	}						// wait until transaction finished (Slave ACK)

		I2CMasterDataPut(I2C0_BASE, device_register);				// store address of slave register which is to be written
		I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

		while(I2CMasterBusy(I2C0_BASE)){	}						// wait until transaction finished (Slave ACK)

		I2CMasterDataPut(I2C0_BASE, register_data);					// store data which is to be written to the designated register
		I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);

		while(I2CMasterBusy(I2C0_BASE)){	}						// wait until transaction finished (Slave ACK)
		I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
		while(I2CMasterBusy(I2C0_BASE)){	}
}

// change I2C slave IDs of Sharp GP2Y0E02B IR sensors via I2C
void changeIRSlaveID(uint8_t oldAdress, uint8_t newAdress)
{
	writeI2C0byte(oldAdress, 0xEC, 0xFF);						// Stage 1: 	Set clock to manual

	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);		// set PA7 High (Vpp)
	SysCtlDelay(SysCtlClockGet() / (3*1000) );					// delay aprox. 1000us to finish pin toggle

    writeI2C0byte(oldAdress, 0xC8, 0x00);						// Stage 2: 	(E-Fuse map in order to change slave adress)
	writeI2C0byte(oldAdress, 0xC9, 0x45);						// Stage 3: 	Adress of E-Fuse register
	writeI2C0byte(oldAdress, 0xCD, newAdress);					// Stage 4: 	Write newAdress to 0xCD (E-Fuse Program Data Register)
	writeI2C0byte(oldAdress, 0xCA, 0x01);						// Stage 5: 	Set Enable Bit for E-Fuse programming

	SysCtlDelay(SysCtlClockGet() / (3*1000) );					// delay aprox. 1000us (> 500 us) to finish data programming

	writeI2C0byte(oldAdress, 0xCA, 0x00);						// Stage 6: 	Clear Enable Bit for E-Fuse programming

	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0x00);			// set PA7 Low (Vpp)

	SysCtlDelay(SysCtlClockGet() / (3*1000) );					// delay aprox. 1000us to finish PIN toggle

	writeI2C0byte(oldAdress, 0xEF, 0x00);			// Stage 7-1:	Select Bank0 (
	writeI2C0byte(oldAdress, 0xC8, 0x40);			// Stage 7-2:	Load E-Fuse Data to Register (Bank3)
	writeI2C0byte(oldAdress, 0xC8, 0x00);			// Stage 7-3:	Enable E-Fuse Bit
	writeI2C0byte(oldAdress, 0xEE, 0x06);			// Stage 8:		Perform Software Reset
	writeI2C0byte(oldAdress, 0xEC, 0xFF);			// Stage 9-1:	Select Manual Clock
	writeI2C0byte(oldAdress, 0xEF, 0x03);			// Stage 9-2:	Select Bank3 (E-Fuse)
	SlaveAdress = readI2C0byte(oldAdress, 0x27);	// Stage 9-3: 	Read Address from 0x27
	writeI2C0byte(oldAdress, 0xEF, 0x00);			// Stage 9-4:	Select Bank0
	writeI2C0byte(oldAdress, 0xEC, 0x7F);			// Stage 9-5:	Select auto clock
}

// change I2C slave IDs of SRF08 US sensors via I2C
void changeUSSlaveID(uint8_t oldAdress, uint8_t newAdress)
{
    writeI2C0byte(oldAddress,0,0xA0);
    writeI2C0byte(oldAddress,0,0xAA);
    writeI2C0byte(oldAddress,0,0xA5);
    writeI2C0byte(oldAddress,0,newAdress); // <- changing to new address
}


int main(void) {

    // Setup the system clock to run at 40 Mhz f PLL with crystal reference
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    //enable I2C module 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

    //reset module
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    //enable GPIO peripheral that contains I2C 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    //enable GPIO peripheral that enables 5v I2C
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

    // Configure the pin muxing for I2C0 functions on port B2 and B3.
    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);

    // Since SRF08 runs at 5V SDA and SCL and Tiva launchpad provides only
    // 3.3v a level shifter is connected to pin 7 of Tiva launchpad that
    // converts 3.3v to 5v and provide to SRF08 US sensor
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_7);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, GPIO_PIN_7);

    // Select the I2C function for these pins.
    GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
    GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);

    // Initialize I2C0 peripheral.
    I2CMInit(&g_sI2CInst, I2C0_BASE, INT_I2C0, 0xff, 0xff, SysCtlClockGet());

    // Wait for MCU to finish transaction
    while(I2CMasterBusy(I2C0_BASE));

    writeI2C0byte(0x70,2,14); // Reducing the ranging time of SRF08 sensor to run it fast approx 7ms

    while(1)
    {
	 writeI2C0byte(0x00,0,82); // for triggering ranging of SRF08 ultrasonic sensor
	 SysCtlDelay(7*SysCtlClockGet()/3000); // time required by SRF08  for ranging

	 US = (double)(256.0*readI2C0byte(0x70,2) + readI2C0byte(0x70,3))*0.0170145; // converting time to distance (Ultrasonic)
     IR = (double)(readI2C0byte(0x40, 0x5F) + readI2C0byte(0x40, 0x5E) * 16) / 6400; // collecting IR distance data
    }
}
