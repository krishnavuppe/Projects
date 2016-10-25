#include<reg51.h>
#include"lcd.h"
#include"keypad.h"

sbit Dmotor=P3^0;
void main()
{
	
	unsigned char i,read_pwd[5],count;
	unsigned char password[5]="12345";
	Dmotor=0;
	init_lcd();
	str_lcd("pwd door lock");
	delay_ms(500);
	cmd_lcd(0x80);
	str_lcd("enter password");
	
	while(1)
	{
		cmd_lcd(0x80);
	str_lcd("enter password");
		cmd_lcd(0xc0);
	str_lcd("          ");
		count=0;
		cmd_lcd(0xc0);
		for(i=0;i<5;i++)
		{
			read_pwd[i]=0x30+keyscan();
			disp_lcd('*');
			//delay_ms(10);
		}	
		//str_lcd(read_pwd);
		for(i=0;i<5;i++)
		{
			if(read_pwd[i]==password[i])
			count++;
		}
		cmd_lcd(0x80);
		if(count==5)
		{
			
			str_lcd("pwd is correct");
			cmd_lcd(0xc0);
			str_lcd("opening.....");
			Dmotor=1;
			delay_ms(3000);
			Dmotor=0;
			cmd_lcd(0xc0);
			str_lcd("opened       ");
		}
		else
		{
			str_lcd("pwd is wrong  ");
				Dmotor=0;
			
		}
		delay_ms(500);
			
	}
}