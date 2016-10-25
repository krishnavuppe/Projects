/*
 * assignment.c
 *
 *  Created on: 01.08.2016
 *      Author: Krishna Vuppe
 */
 #include <stdio.h>
 #include <libs/i2c.h>


double read_temperature()
{
    static int count = 0;

    uint8_t bmp180_address = 0x77; // default i2c address of BMP180
    static int16_t ac1, ac2, ac3, b1, b2, mb, mc, md; // short variables for storing EEPROM data
    static uint16_t ac4, ac5, ac6; // unsigned short variables for storing EEPROM data
    uint8_t reg = 0xF4; // Control register
    uint8_t temp = 0x2E; // For triggering uncompensated temperature reading
    uint8_t buf1,buf2; // storing readI2C data
    uint16_t MSB,LSB; // MSB and LSB of uncompensated temperature data
    int32_t UT,X1,X2,B5; // Used for calculating temperature value
    double temperature;

// for reading calibration data from EEPROM only for 1st function call
    if(count==0)
    {
    i2c_read(bmp180_address,0xAA,&ac1,2);// I assume it stores the data of both registers AA and AB into ac1 if size = 2;
    i2c_read(bmp180_address,0xAC,&ac2,2);// I assume it stores the data of both registers into ac2;
    i2c_read(bmp180_address,0xAE,&ac3,2);// I assume it stores the data of both registers into ac3
    i2c_read(bmp180_address,0xB0,&ac4,2);// I assume it stores the data of both registers into ac4
    i2c_read(bmp180_address,0xB2,&ac5,2);// I assume it stores the data of both registers into ac5
    i2c_read(bmp180_address,0xB4,&ac6,2);// I assume it stores the data of both registers into ac6
    i2c_read(bmp180_address,0xB6,&b1,2);// I assume it stores the data of both registers into b1
    i2c_read(bmp180_address,0xB8,&b2,2);// I assume it stores the data of both registers into b2
    i2c_read(bmp180_address,0xBA,&mb,2);// I assume it stores the data of both registers into mb
    i2c_read(bmp180_address,0xBC,&mc,2);// I assume it stores the data of both registers into mc
    i2c_read(bmp180_address,0xBE,&md,2);// I assume it stores the data of both registers into md

    count = 1; // since count is static it stores its value between function calls
    }
/////////////////////////////////////////////////////////////

// for reading uncompensated temperature data
    i2c_write(bmp180_address,reg,&temp,1);
    delay(5); // Delay of 5ms (different delay functions for different libraries)
    i2c_read(bmp180_address,0xF6,&buf1,1); // buf1 will store the MSB of raw temp value
    i2c_read(bmp180_address,0xF7,&buf2,1); // buf2 will store the LSB of raw temp value
    MSB = (uint16_t)buf1;
    LSB = (uint16_t)buf2;
    UT = (int32_t)(MSB<<8+LSB);

// for doing temperature calc
    X1=(UT-(int32_t)(ac6))*((int32_t)(ac5))/pow(2,15);
    X2=((int32_t)mc*pow(2,11))/(X1+(int32_t)md);
    B5=X1 + X2;
    temperature = (double)((B5+8)/pow(2,4)); // confused if it is 2 pow 1 or 2 pow 4 please correct if it is wrong
    temperature = temperature/10; // given temperature in 0.1 degrees celsius so * 0.1 gives degrees celsius

    return temperature;
}


double read_pressure()
{
    static int count = 0;

    uint8_t bmp180_address = 0x77; // default i2c address of BMP180
    static int16_t ac1, ac2, ac3, b1, b2, mb, mc, md; // short variables for storing EEPROM data
    static uint16_t ac4, ac5, ac6; // unsigned short variables for storing EEPROM data
    uint8_t reg = 0xF4; // Control register
    uint8_t pres = 0x34; // For triggering uncompensated pressure reading, taking(oss=0)
    uint8_t buf1,buf2,buf3; // storing readI2C data
    uint32_t MSB,LSB,XLSB; // MSB LSB and XLSB of uncompensated pressure data
    int32_t UP,B6,X1,X2,X3,B3,p; // Used for calculating temperature value
    uint32_t B4,B7; // Used for calculating temperature value
    double Pressure;

// for reading calibration data from EEPROM only for 1st function call
    if(count==0){
    i2c_read(bmp180_address,0xAA,&ac1,2);// I assume it stores the data of both registers AA and AB into ac1 if size = 2;
    i2c_read(bmp180_address,0xAC,&ac2,2);// I assume it stores the data of both registers into ac2;
    i2c_read(bmp180_address,0xAE,&ac3,2);// I assume it stores the data of both registers into ac3
    i2c_read(bmp180_address,0xB0,&ac4,2);// I assume it stores the data of both registers into ac4
    i2c_read(bmp180_address,0xB2,&ac5,2);// I assume it stores the data of both registers into ac5
    i2c_read(bmp180_address,0xB4,&ac6,2);// I assume it stores the data of both registers into ac6
    i2c_read(bmp180_address,0xB6,&b1,2);// I assume it stores the data of both registers into b1
    i2c_read(bmp180_address,0xB8,&b2,2);// I assume it stores the data of both registers into b2
    i2c_read(bmp180_address,0xBA,&mb,2);// I assume it stores the data of both registers into mb
    i2c_read(bmp180_address,0xBC,&mc,2);// I assume it stores the data of both registers into mc
    i2c_read(bmp180_address,0xBE,&md,2);// I assume it stores the data of both registers into md
    }
/////////////////////////////////////////////////////////////

// for reading uncompensated Pressure data
    i2c_write(bmp180_address,reg,&pres,1);
    delay(5); // Delay of 5ms for oss = 0 (different delay functions for different libraries)
    i2c_read(bmp180_address,0xF6,&buf1,1); // buf1 will store the MSB of raw pres value
    i2c_read(bmp180_address,0xF7,&buf2,1); // buf2 will store the LSB of raw pres value
    i2c_read(bmp180_address,0xF8,&buf3,1); // buf3 will store the XLSB of raw pres value
    MSB = (uint32_t)buf1;
    LSB = (uint32_t)buf2;
    XLSB = (uint32_t)buf3;
    UP = (int32_t)((MSB<<16+LSB<<8+XLSB)>>8); // since oss = 0 in our case


// for doing pressure calc
    B6 = B5 - 4000;
    X1 = ((int32_t)b2*((B6 * B6)/pow(2,15)))/pow(2,15);
    X2 = ((int32_t)ac2 * B6)/pow(2,11);
    X3 = X1 + X2;
    B3 = (((int32_t)ac1*4 + X3) + 2) / 4;
    X1 = ((int32_t)ac3 * B6)/pow(2,13);
    X2 = ((int32_t)b1 * ((B6 * B6)/pow(2,12)))/pow(2,16);
    X3 = ((X1 + X2) + 2)/pow(2,2);
    B4 = ((uint32_t)ac4 * (uint32_t)(X3 + 32768))/pow(2,15);
    B7 = ((uint32_t)UP - B3) * (uint32_t)( 50000UL );

    if (B7 < 0x80000000) { p = (B7 * 2) / B4;}
    else { p = (B7 / B4) * 2;}

    X1 = (p/pow(2,8))*(p/pow(2,8));
    X1 = (X1*3038)/pow(2,16);
    X2 = (-7357*p)/pow(2,16);

    pressure = (double)(p + ((X1 + X2 + (int32_t)3791)/pow(2,4)));


    return pressure;
}
