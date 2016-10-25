#include<reg51.h>
#include<stdio.h>
sbit rs=P1^0; 	
sbit rw=P1^1; 	
sbit e=P1^2; 		
sbit quat=P3^0; // Quad water level 
sbit half=P3^1; // half level of tank
sbit quat_3=P3^2; // three -fourth level of tank
sbit full=P3^3; 	//full level of tank
sbit motor=P3^4;  //pin connected to motor

void delay(int k) //delay function
{
int i,j;
for(i=0;i<k;i++)
  for(j=0;j<1275;j++);
}

void write(int j) 
{
rs=1;  //selecting rs pin to data mode
rw=0;  //selecting rw pin to write mode
P2=j;  //putting value on the pins
e=1;  //high pulse 
delay(1);
e=0;	// low pulse
return;
}

void cmd(int j)  //command function
{
P2=j;  //put the data on pins
rs=0;  //selecting rw pin to command mode
rw=0;  //selecting to write
e=1;  
delay(1);
e=0;
return;
}

void put(char *a) // function to display string on LCD'
{
unsigned int p=0;
for(;a[p]!=0;p++)
write(a[p]);
}

void lcd_init(void) // function to initialise the LCD
{
cmd(0x38); 
delay(1);
cmd(0x0c); //LCD turning on cmd
delay(1);     
cmd(0x01); //clear lcd cmd 
cmd(0x80); // starting point of LCD
}

void main()
{
lcd_init();  	//LCD intialization
quat=half=quat_3=full=1; //configuring as input pins
quat=half=quat_3=full=0; //lowering input pins
motor = 0;
while(1)
{
  if(quat==0&&half==0&&quat_3==0&&full==0)   //when tank is empty
  {
   cmd(0x80);   		// to move the cursor to starting point of LCD
   put("EMPTY   ");      // dispalys empty on lcd 
		motor=1;							// start motor
  }
  else if(quat==1&&half==0&&quat_3==0&&full==0)	// when tank is quater
  {
   cmd(0x80); 
   put("QUATER   ");     // dispalys Quarter on lcd
  }
  else if(quat==1&&half==1&&quat_3==0&&full==0)	// when tank is half
  {
    cmd(0x80); 
   put("HALF    ");      // dispalys half on lcd
  }
  else if(quat==1&&half==1&&quat_3==1&&full==0)	// when tank is three-fourth
  {
   cmd(0x80); 
   put("3/4 FULL   ");     // dispalys 3/4 full on lcd
  }
  else if(quat==1&&half==1&&quat_3==1&&full==1)	// when tank is full
  {
   cmd(0x80); 
   put("FULL    ");    // dispalys full on lcd
   motor=0;            // to stop the motor 
  }
 
}
}