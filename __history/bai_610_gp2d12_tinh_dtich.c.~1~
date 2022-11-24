#include <tv_kit_vdk_18f6722_all.c>

void h609_lcd_cbkc_gp2d12() 
{ 
    lcd_goto_xy(0,0); 
    lcd_data("Cam bien do khoang ");
    lcd_goto_xy(1,0); 
    lcd_data("SHARP GP2D12:10-80cm"); 
}
void b609_adc_cbkc_gp2d12(usi8 sl, int1 ht_tp) 
{ 
    float kc;
    usi16 kc_ng,kc_tp,kc_t;
    kc=h601_adc_read(sl,chan_cbkc);
    kc = pow(4277/kc,1.106); 
    if(kc>80) kc=80;
 
    float_to_ng_2so_tp(kc); 
    kc_ng = so_ng;
    kc_tp = so_tp;
    lcd_goto_xy(2,2);
    lcd_data(".");
    if(kc_t!=kc_ng)
    {
        kc_t=kc_ng; 
        lcd_goto_xy(2,0);
        lcd_data(kc_ng/10 + 0x30);
        lcd_goto_xy(2,1);
        lcd_data(kc_ng%10 + 0x30);
        xuat_8led_7doan();
    }
        if(ht_tp){
            lcd_goto_xy(2,3);
            lcd_data(kc_tp/10 + 0x30);
            lcd_goto_xy(2,4);
            lcd_data(kc_tp%10 + 0x30);
        } 
}

void main()
{
    set_up_port();
    lcd_setup();
    lcd_khoi_tao_cgram_so_to(); 
    h609_lcd_cbkc_gp2d12(); 
    lcd_goto_xy(2,0);
    lcd_data(8+0x30);
    lcd_goto_xy(2,1);
    lcd_data(0x30);
    while(true)
    { 
        b609_adc_cbkc_gp2d12(10,1);
    } 
}
