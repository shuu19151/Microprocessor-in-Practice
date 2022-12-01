#include <16F877A.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

#include <lcd.h>
#include <string.h>
#include <math.h>

#define ok       input(PIN_C2)
#define up     input(PIN_C0)
#define dw    input(PIN_C1)

#define BUZ PIN_C3

#include "DS18B20_lib.c"

unsigned int16 nhietdo;
unsigned int gtmin = 30, gtmax = 32;
int1 alarm = 1;

void xuly_alarm(){
   if(alarm == 1){
      if(nhietdo >= gtmax){
         output_high(BUZ);
      }
      else if(nhietdo <= gtmin){
         output_high(BUZ);
      }
      else{
         output_low(BUZ);
      }
   }
   else if(alarm == 0){
      output_low(BUZ);
   }
}

void xuly_nhietdo(){
    if(DS18B20_read(&raw_temp)){
        temp = (float)raw_temp/16;
        nhietdo = temp;
        lcd_gotoxy(7,1);
        printf(lcd_putc, "Temp: %f", temp);
    }
    else {
        lcd_gotoxy(7,1);
        lcd_putc("Error");
    }
    xuly_alarm();
}

void hienthi_thongtin(void){
    char Tri[] = {"                LAM QUANG TRI-19151087                 "};
    char An[] = {"                NGUYEN DINH AN-19151068                 "};
    signed char i,j;
    
    for (j = 1; j <= strlen(Tri) - 16; j++)
    {
        for(i = 1; i <= 16; i++)
        {
            lcd_gotoxy(i,1);
            printf(lcd_putc,"%c",Tri[i + j - 1]);
            lcd_gotoxy(i,2);
            printf(lcd_putc,"%c",An[i + j - 1]);
        }
        delay_ms(300);
        if(!ok == 1){
            while(!ok == 1);
            lcd_putc("\f");
            break;
         }
    }
    delay_ms(1000);
}

void hienthi_gioihan(){
   lcd_gotoxy(1,2);
   printf(lcd_putc, "Max: %d", gtmax);
   lcd_gotoxy(9,2);
   printf(lcd_putc,"Min: %d",gtmin);
   if(alarm == 1){
      lcd_gotoxy(14,1);
      lcd_putc("AL");
   }
   else if(alarm == 0){
      lcd_gotoxy(14,1);
      lcd_putc("  ");
   }
}

void ktra_nutnhan(){
    if(!up == 1)
    {
        delay_ms(5);
        if(!up == 1)
        {
            while (!up == 1);
            if(gtmax > 40)
            {
                gtmax = 20;
            }
            else{
                gtmax++;
            }
        }
    }
    if(!dw == 1)
    {
        delay_ms(5);
        if(!dw == 1)
        {
            if(gtmin > 40)
            {
                gtmin = 20;
            }
            else{
                gtmin++;
            }
            while (!dw == 1);
        }
    }
    if(!ok == 1)
    {
        delay_ms(5);
        if(!ok == 1)
        {
            if(alarm == 0)
            {
                alarm = 1;
            }
            else{
                alarm = 0;
            }
            while (!ok == 1);
        }
    }
    hienthi_gioihan();
}
void start(){
    output_low(BUZ);
    output_high(BUZ);
    delay_ms(500);
    output_low(BUZ);
}

