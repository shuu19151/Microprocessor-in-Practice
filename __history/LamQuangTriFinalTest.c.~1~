#include <tv_kit_vdk_18f6722_all.c>

unsigned int16 lm35a_ng,lm35a_tp,lm35a_ngt=0; // bien co hoac khong

usi16 T = 10, dis;
void h609_lcd_cbkc_gp2d12() 
{ 
    lcd_goto_xy(0,0); 
    lcd_data("Tri - 19151087");
}

float kcs;
void h613_lcd_hien_thi_hcsr04() 
{ 
    lcd_goto_xy(2,14); 
    lcd_data("HCSR04"); 
} 
void h613_tao_xung_trigger() 
{ 
    output_high(trig); 
    delay_us(20); 
    output_low(trig); 
 
    set_timer3(0); 
    while(!(input(echo))); 
    setup_timer_3(t3_internal|t3_div_by_8); 
 
    while(input(echo)); 
    setup_timer_3(t3_disabled);
    kcs = get_timer3();
}
void b613_cbkc_hc04() // sieu am
{ 
    usi16 kc_ng,kc_tp,kc_t;
 
    h613_tao_xung_trigger();
    kcs=kcs*1.6; 
    kcs=(kcs/58); 
 
    float_to_ng_2so_tp(kcs); 
    kc_ng = so_ng;
    kc_tp = so_tp;
 if(kc_t!=kc_ng)
 {
    kc_t=kc_ng;
    lcd_gm_ht_2so_to_xvn(kc_ng,2,0,kx_vn);
    giaima_bin_2so_vitri_vn(kc_ng,3,cx_vn);
    xuat_8led_7doan();
 }
    lcd_hien_thi_2so_tp_nho(kc_tp,3,6);
}

void b609_adc_cbkc_gp2d12(usi8 sl, int1 ht_tp) // quang
{ 
    float kc;
    usi16 kc_ng,kc_tp,kc_t;
    kc=h601_adc_read(sl,chan_cbkc);
    kc = pow(4277/kc,1.106); 
    dis = kc;
    if(kc>80) kc=80;

    float_to_ng_2so_tp(kc); 
    kc_ng = so_ng;
    kc_tp = so_tp;
    lcd_goto_xy(1,2);
    lcd_data(".");
    if(kc_t!=kc_ng)
    {
        kc_t=kc_ng; 
        lcd_goto_xy(1,0);
        lcd_data(kc_ng/10 + 0x30);
        lcd_goto_xy(1,1);
        lcd_data(kc_ng%10 + 0x30);
        xuat_8led_7doan();
    }
        if(ht_tp){
            lcd_goto_xy(1,3);
            lcd_data(kc_tp/10 + 0x30);
            lcd_goto_xy(1,4);
            lcd_data(kc_tp%10 + 0x30);
        }
    lcd_goto_xy(2,0);
    lcd_data("T: ");
    lcd_goto_xy(2,3);
    lcd_data(T/10 + 0x30);
    lcd_data(T%10 + 0x30);
}

void buzz(usi8 freq){
    usi8 T;
    T = (1/freq)*1000;
    buzzer_on();
    delay_ms(T);
    buzzer_off();
    delay_ms(T);
}

void h601_adc_lm35a_doc_xuly(usi8 slan) 
{ 
    float lm35a; 
    lm35a=h601_adc_read(slan,chan_lm35a);
    lm35a = lm35a/2.046;
    float_to_ng_2so_tp(lm35a);
    lm35a_ng = so_ng;
    lm35a_tp = so_tp;
}

void hienthi_lcd(usi8 x,y,int1 ht_lcd,ht_tp){
    if(lm35a_ngt!=lm35a_ng)
    {
        lm35a_ngt=lm35a_ng;
        lcd_goto_xy(x,y+2);
        lcd_data(".");
        if(ht_lcd){
            lcd_goto_xy(x,y);
            lcd_data(lm35a_ng/10 + 0x30);
            lcd_data(lm35a_ng%10 + 0x30);
        }
        if(ht_tp){
            lcd_goto_xy(x,y+3);
            lcd_data(lm35a_tp/10 + 0x30);
            lcd_data(lm35a_tp%10 + 0x30);
        }
    }
}



void sosanh_(){
    if((dis > 10) && (dis < T)){
        tat_32led();
        buzzer_on();
        delay_ms(1000);
        buzzer_off();
        delay_ms(1000);
    }
    else if(dis <= 10){
        tat_32led();
        buzzer_on();
        delay_ms(500);
        buzzer_off();
        delay_ms(500);
    }
    else if(dis > T){
        buzzer_off();
        xuat_32led_don_4byte(0,0,0xff,0);
    }
}

void up_dw(){
    if(!input(bt0) == 1){
        delay_ms(20);
        if(!input(bt0) == 1){
            while(!input(bt0) == 1);
            if(T > 19){
                T = 20;
            }
            else T++;
        }
    }
    if(!input(bt1) == 1){
        delay_ms(20);
        if(!input(bt1) == 1){
            while(!input(bt1) == 1);
            if(T < 9){
                T = 10;
            }
            else T--;
        }
    }
}

void main()
{
    set_up_port();
    lcd_setup();
    lcd_khoi_tao_cgram_so_to(); 
    h609_lcd_cbkc_gp2d12(); 
    lcd_goto_xy(1,0);
    lcd_data(8+0x30);
    lcd_goto_xy(1,1);
    lcd_data(0x30);
    while(true)
    { 
        b609_adc_cbkc_gp2d12(10,1);
        up_dw();
        sosanh_();
    } 
}

