#include <tv_kit_vdk_18f6722_all.c>

unsigned int8 i;
unsigned int32 y;

void main(){
   set_up_port();
   y = 0;
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
   for(i = 0; i < 32; i++){
      xuat_32led_don_1dw(y);
      delay_ms(50);
      y = (y >> 1) | 0x80000000;
   }
   for(i = 0; i < 32; i++){
      xuat_32led_don_1dw(y);
      delay_ms(50);
      y = y >> 1;
   }
   
}
