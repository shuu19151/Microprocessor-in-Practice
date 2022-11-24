#include <tv_kit_vdk_18f6722_all.c>
usi8 pr, mp8, cv, t0_tam;
int1 tt_ena_dis = 0, tt_on_off = 0;

void hienthi_led7d(){
    //led_7d[4] = ma7doan[bcd_8led[4]];//hien thi preset
    //led_7d[3] = ma7doan[bcd_8led[3]];
    giaima_bcd_2so_vitri_vn(pr,3,kx_vn);
    giaima_bin_3so_vitri_vn(87,0,kx_vn);
    xuat_8led_7doan();
}

void caidat_preset(){
    mp8 = key_tip229_cdoi_c2(10);
    if((mp8>0)&&(mp8<17))
    {
        mp8 = mp8%16;
        if((mp8<10)&&(tt_ena_dis != enable))
        {
            bcd_8led[4] = bcd_8led[3];
            bcd_8led[3] = mp8;
            pr = bcd_8led[4]*10 + bcd_8led[3];
            delay_ms(200);
        }
    }
}

void kt_start_stop_clr(){
    if(phim_bt0_c2(150) == co_nhan){ // ktra start
        tt_on_off = tt_on;
        tt_ena_dis = enable;
        pr = bcd_8led[3]*10 + bcd_8led[4];

    }
    if(phim_bt2_c2(150) == co_nhan){ // ktra stop
        tt_on_off = tt_off;

    }
    if(phim_bt1_c2(150) == co_nhan){ // ktra clear
        tt_on_off = tt_on;
        set_timer0(0);
    }
}

void dem_counter(){
    if(tt_on_off == tt_on){
        cv = get_timer0();
        if(t0_tam != cv)
        {
            t0_tam = cv;
            pr--;
            hienthi_led7d();
            if ((pr >= 0)&&(tt_on_off == tt_on))
            {
                set_timer0(0);
                for(usi8 i = 0; i < 4; i++){
                   sang_32led();
                   delay_ms(400);
                   tat_32led();
                   delay_ms(400);
                }
            }
        }
    }
}

void main(){
    set_up_port();
    setup_timer_0(t0_ext_l_to_h|t0_div_1);
    set_timer0(0);
    pr = 0;
    //cv = 0;
    t0_tam = 1;
    while(true){
        caidat_preset();
        hienthi_led7d();
    }
}
