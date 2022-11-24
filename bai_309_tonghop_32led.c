#include <tv_kit_vdk_18f6722_all.c>

unsigned int8 i, j;
unsigned int32 y;

void sang_tat_32led_5lan(){
   for(j = 0; j < 5; j++){
      xuat_32led_don_4byte(0,0,0,0);
      delay_ms(100);
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      delay_ms(100);
   }
}
void sang_tat_dan_pst_32led_2lan(){
   for(j = 0; j < 2; j++){
      for(i = 0; i < 32; i++){
         xuat_32led_don_1dw(y);
         delay_ms(50);
         y = (y << 1) | 0x01;
      }
      for(i = 0; i < 32; i++){
         xuat_32led_don_1dw(y);
         delay_ms(50);
         y = y << 1;
      }
   }
}

void sang_tat_dan_tsp_32led_2lan(){
   for(j = 0; j < 2; j++){
      for(i = 0; i < 32; i++){
         xuat_32led_don_1dw(y);
         delay_ms(50);
         y = (y >> 1) | 0x80000000;
      }
      for(i = 0; i < 32; i++){
         xuat_32led_don_1dw(y);
         delay_ms(50);
         y = y>> 1;
      }
   }
}

void main(){
   set_up_port();
   y = 0;
   while(true){
      sang_tat_32led_5lan();
      sang_tat_dan_pst_32led_2lan();
      sang_tat_32led_5lan();
      sang_tat_dan_tsp_32led_2lan();
   }
}
