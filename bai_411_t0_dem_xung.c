#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 t0, t0_tam,g_han; 
void b411_hienthi_4led7doan()
{ 
 giaima_bin_2so_vitri_vn(t0,0,kx_vn);
 giaima_bin_2so_vitri_vn(g_han,6,kx_vn);
 xuat_8led_7doan();
}
void b411_dem_sp_t0()
{ 
 t0 = get_timer0(); 
 if(t0_tam!=t0)
 {
 t0_tam = t0;
 b411_hienthi_4led7doan(); 
 if (t0>=g_han) 
 {
 set_timer0(0);
 buzzer_on_off(300); 
 }
 } 
}

void main() 
{ 
 set_up_port(); 
 setup_timer_0(t0_ext_l_to_h|t0_div_1); 
 set_timer0(0); t0_tam = 1; g_han=50; 
 while(true) 
 { 
 b411_dem_sp_t0(); 
 } 
}
