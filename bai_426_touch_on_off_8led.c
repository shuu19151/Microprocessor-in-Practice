#include <tv_kit_vdk_18f6722_all.c> 
unsigned int8 mp8, p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0,y = 0;
void phim_inv()
{
   if (!input(inv))
   {
      delay_ms(20);
      if (!input(inv))
      {
         y=~y;
         xuat_32led_don_4byte(0,0,0,y);
         while(!input(inv));
      } 
   }
}
void b426_kiemtra_phim() 
{
   mp8 = key_tip229_cdoi_c2(10); 
   if((mp8 > 0) && (mp8 <9)){
      p1 = ~p1;
      if(p1 == 0){
         xuat_32led_don_4byte(0,0,0,mp8);
      }
      else {
         xuat_32led_don_4byte(0,0,0,0);
      }
   }
}
void main()
{ 
    set_up_port();
   while(true)
   { 
      b426_kiemtra_phim();
   } 
}