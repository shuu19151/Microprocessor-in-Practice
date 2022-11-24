#include <tv_kit_vdk_18f6722_all.c> 
#include <bai_327_tv.c> 
 
void b328_32led_std_pst_tsp_tat_3bt_if() 
{ 
   if(phim_bt0_c2(2)==co_nhan) 
   { 
      if(tt_ct<2)
      {
         tt_ct++;
         h327_reset_tang_tcttd_if();
      }
   } 
   if(phim_bt1_c2(2)==co_nhan)
   { 
      if(tt_ct>0)
      {
         tt_ct--;
         h327_reset_tang_tcttd_if();
      }
   } 
} 
void main()
{
   set_up_port();
   tt_ct=0;
   h327_reset_tang_tcttd_if();
   while(true)
   {
      b328_32led_std_pst_tsp_tat_3bt_if();
      if(tt_ct==0) xuat_32led_don_1dw(0);
      if(tt_ct==1) h327_32led_std_pst_if();
      if(tt_ct==2) h327_32led_std_tsp_if();
      delay_ms(200);
   }
}
