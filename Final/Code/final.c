#include <final.h>

void main(){
    start();
    lcd_init();
    lcd_putc("\f");
    hienthi_thongtin();
    setup_adc(adc_clock_div_2);
    setup_adc_ports(AN0);
    while(true){
        doc_value_lm35();
        delay_ms(200);
        hienthi_lcd(1, 1);
        ktra_nutnhan();
        hienthi_gioihan();
        delay_ms(200);

    }
}