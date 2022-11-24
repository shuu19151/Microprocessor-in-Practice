#include <tv_kit_vdk_18f6722_all.c> 
//up bt0, dw bt2, mod bt1, clr bt3
unsigned int16 sochuky;
void chay_32led_nlan(int8 n,usi16 dl) 
{ 
   for(int8 j=0;j<n;j++)
   b308_32led_std_pst(dl);
}

void b308_32led_std_pst(usi16 dl) 
{ 
   usi8 i; usi32 x;
   x = 0;
   for(i = 0; i < 32; i++)
   {
      x = (x << 1) + 1;
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
   for(i = 0; i < 32; i++)
   {
      x = (x << 1);
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
}

void chay_32led_don(usi16 dl){
   usi8 i; usi32 x;
   x = 0;
   for(i=0;i<32;i++)
   {
      x = (x << 1)+1;
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
   for(i=0;i<32;i++)
   {
      x = (x << 1);
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
}

void kt_caidat_sochuky(){
   if (phim_up_c2(150) == co_nhan)
   {
      if(sochuky > 20){
         hienthi_led_7d();
         sochuky = 20;
      }
      else sochuky ++;
   }
   if (phim_dw_c2(150) == co_nhan)
   {
      if(sochuky < 0){
         hienthi_led_7d();
         sochuky = 0;
      }
      else sochuky --;
   }
}

void kt_run_pause(){
   unsigned int8 i, scktam = sochuky;
   if(phim_bt1_c2 == co_nhan){
      for(i = 0; i < scktam;i++){
         chay_32led_don(500);
         sochuky --;
         hienthi_led_7d();
      }
   }
}

void main()
{ 
   set_up_port();
   sochuky = 0;
   while(true)
   {
      hienthi_led_7d();
      kt_caidat_sochuky();
      kt_run_pause();
   } 
}
