#include <main.h>

unsigned char flag,i;
void Edit_baodong();
char Delay_va_kiem_tra_phim(unsigned int t);


void main()
{
   //khai bao bien cuc bo nay
   unsigned int GiaTriADC;
   unsigned int NhietDo;
   float Tam;
   output_low(BZ);
   
   lcd_init();		//Khoi tao LCD
   lcd_putc('\f');	//Xoa man hinh
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);   
	
	i=30;
	flag = 0;
   while(1)
   {
	  // lcd_gotoxy(1,1);
     // printf(lcd_putc,"HELLO WORLD!");
      /*
      theo ly thuyet ta co
      cu  5000mv      -->      1023 adc
      vay x           <--      GiaTriADC
      => x = (5000*GiaTriADC)/1023
      mat khac theo datasheet thi:
      cu  10mv                   -->      1 C
      vay (5000*GiaTriADC)/1023  -->      y
      => y = ((5000*GiaTriADC)/1023)/10 = (500*GiaTriADC)/1023
      */   
      
      set_adc_channel(0);
      GiaTriADC = read_adc();
      Tam = (500f*(float)GiaTriADC)/1023f;
      NhietDo = (unsigned int)Tam;
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Temp: %d",NhietDo);
      lcd_putc(0xdf);
      lcd_putc('C');
      
      Delay_va_kiem_tra_phim(1000);
      
      Edit_baodong();
      
      
      if(NhietDo>=i) output_high(BZ);
      else output_low(BZ);
    }
}


void Edit_baodong()
{
	if(OK==0)
    {
	    while(!OK);
     	if(flag==0)
    	{
   			flag = 1;
   		}
	    else
	   	{	
	   		flag = 0;
	   		lcd_putc('\f');	//Xoa man hinh	
	   	}      	
     }
     
     if(flag==1)
     {
     	 lcd_gotoxy(1,2);
	     printf(lcd_putc,"Alarm: %d",i);
	     lcd_putc(0xdf);
	     lcd_putc('C');
	     if(Plus==0) 
	     {
	     	while(!Plus);
	     	i++;
	     }
	     if(Minus==0) 
	     {
	     	while(!Minus);
	     	i--;
	     }
	}
}

char Delay_va_kiem_tra_phim(unsigned int t)
{
	while(t)
	{
		delay_ms(1);
		if(OK==0) break;
		if(Plus==0) break;
		if(Minus==0) break;
		t--;
	}	
}