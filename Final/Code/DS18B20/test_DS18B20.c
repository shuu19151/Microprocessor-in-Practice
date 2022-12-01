#include <test_DS18B20.h>

void main(){
    start();
    lcd_init();
    lcd_putc("\f");
    hienthi_thongtin();
    while(true){
        xuly_nhietdo();
        ktra_nutnhan();
        delay_ms(200);

    }
}
