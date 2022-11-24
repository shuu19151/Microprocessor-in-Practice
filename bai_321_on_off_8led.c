#include <tv_kit_vdk_18f6722_all.c> 
void main() 
{ 
 set_up_port(); 
 while(true) 
 { 
 while(input(ON));
 xuat_32led_don_4byte(0,0,0,0xff);
 while(input(Off));
 xuat_32led_don_4byte(0,0,0,0);
 } 
} 
