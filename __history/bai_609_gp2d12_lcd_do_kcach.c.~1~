#include <tv_kit_vdk_18f6722_all.c>

unsigned int16 vrx,vry,vrx_t=0,vry_t=0; 
void b605_adc_joystick() 
{
    float jx,jy;
    jx = h601_adc_read(20,1); 
    float_to_ng_2so_tp(jx); 
    vrx = so_ng; 
 
    jy = h601_adc_read(20,2);
    float_to_ng_2so_tp(jy); 
    vry = so_ng; 
}
void b605_joystick_ht_7doan() 
{ 
    giaima_bin_4so_vitri_vn(vrx,4,cx_vn);
    giaima_bin_4so_vitri_vn(vry,0,cx_vn);
    xuat_8led_7doan(); 
}
void b605_joystick_ht_lcd() 
{ 
    if(vrx_t!=vrx)
    {
        vrx_t=vrx; 
        lcd_gm_ht_4so_to_xvn(vrx,0,8,cx_vn); 
    } 
    if(vry_t!=vry)
    {
        vry_t=vry; 
        lcd_gm_ht_4so_to_xvn(vry,2,8,cx_vn);
    }
}

void main()
{ 
    set_up_port();
    lcd_setup();
    lcd_khoi_tao_cgram_so_to();
 
    lcd_goto_xy(0,0); 
    lcd_data("JOYSTICK");
    lcd_goto_xy(1,4); 
    lcd_data("VRX:");
    lcd_goto_xy(3,4);
    lcd_data("VRY:");
    while(true)
    { 
        b605_adc_joystick();
        b605_joystick_ht_7doan();
        b605_joystick_ht_lcd();
        delay_ms(200);
    } 
}
