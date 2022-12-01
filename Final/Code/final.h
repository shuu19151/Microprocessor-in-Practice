#include <16F877A.h>

#device ADC=10

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

unsigned int16 so_ng, so_tp, lm35a_ng, lm35a_tp, lm35a_ngt=0, lm35;
unsigned int gtmin = 30, gtmax = 32;
int1 alarm = 1;

void float_to_ng_2so_tp(float st)                      
{
   so_ng = st/1;       //nguyen
   st = st-so_ng;      //tphan
   st = st*100;
   so_tp = st/1;
} 

float main_adc_read()                      
{
   float kq_adc;  unsigned int8 i;
   set_adc_channel(0);
   delay_us(20);
   kq_adc = 0;
   for(i=0;i<100;i++)
   {
      kq_adc = kq_adc + read_adc();   
   }                                    
   kq_adc = kq_adc/100;
   return kq_adc;
}

void doc_value_lm35() 
{
   float lm35a;
   lm35a = main_adc_read();
   lm35a = lm35a/2.046;
   lm35 = lm35a;
   float_to_ng_2so_tp(lm35a);
   lm35a_ng = so_ng;
   lm35a_tp = so_tp;
}

void xuly_alarm(){
   if(alarm == 1){
      if(lm35 >= gtmax){
         output_high(BUZ);
      }
      else if(lm35 <= gtmin){
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

void hienthi_lcd(int1 ht_ng, ht_tp){
   lcd_gotoxy(1,1);
   lcd_putc("Temp: ");
   if(lm35a_ngt!=lm35a_ng)
   {
      lm35a_ngt=lm35a_ng;
      lcd_gotoxy(9, 1);
      lcd_putc(".");
      if(ht_ng){
         lcd_gotoxy(7,1);
         lcd_putc(lm35a_ng/10 + 0x30);
         lcd_putc(lm35a_ng%10 + 0x30);
      }
      if(ht_tp){
         lcd_gotoxy(10,1);
         lcd_putc(lm35a_tp/10 + 0x30);
         lcd_putc(lm35a_tp%10 + 0x30);
     }
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
void ktra_up(){
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
    hienthi_gioihan();
}

void ktra_dw(){
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
    hienthi_gioihan();
}

void ktra_ok()
{
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

void ktra_nutnhan(){
    ktra_up();
    ktra_dw();
    ktra_ok();
}
void start(){
    output_low(BUZ);
    output_high(BUZ);
    delay_ms(500);
    output_low(BUZ);
}

