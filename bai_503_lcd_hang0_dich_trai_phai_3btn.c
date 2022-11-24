#include <tv_kit_vdk_18f6722_all.c>

void kt_bt0(){
    if( phim_bt0_c2(150) == co_nhan){
        lcd_command(lcd_shift_left);
        break;
    }
}
void main() 
{ 
    set_up_port(); 
    lcd_setup();
    delay_ms(1000); 
    while(true)
    {
        
    }
}
