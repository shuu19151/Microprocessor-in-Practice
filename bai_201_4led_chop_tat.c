#include <tv_kit_vdk_18f6722_all.c>  
void h201_8led_chop_tat(usi16 dl)          
{ 
   xuat_32led_don_4byte(0,0,0,0);     
   delay_ms(dl);                                        
   xuat_32led_don_4byte(0,0,0,0x0f);
   delay_ms(dl);
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      h201_8led_chop_tat(100);                                        
   }      
}  

