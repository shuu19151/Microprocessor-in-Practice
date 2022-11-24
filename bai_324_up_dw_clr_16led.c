#include <tv_kit_vdk_18f6722_all.c>
unsigned int32 y;
void up_bt(){
   if(input(up) == 0){
      delay_ms(10);
      if(input(up) == 1){
         y = (y << 1) + 1;
         xuat_32led_don_1dw(y);
      }
   }
}

void down_bt(){
   if(input(dw) == 0){
      delay_ms(10);
      if(input(dw) == 1){
         y = (y >> 1);
         xuat_32led_don_1dw(y);
      }
   }
}

void clr_bt(){
   if(input(clr) == 0){
      delay_ms(10);
      if(input(clr) == 1){
         y = 0;
         xuat_32led_don_1dw(y);
      }
   }
}

void main(){
   set_up_port();
   y = 0;
   xuat_32led_don_1dw(y);
   while(true){
      up_bt();
      down_bt();
      clr_bt();
   }
}
