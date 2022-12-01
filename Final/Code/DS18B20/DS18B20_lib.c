
#define DS18B20_PIN PIN_A0
signed int16 raw_temp;
float temp;

int1 DS18B20_start(){
    output_low(DS18B20_PIN);        // Send reset pulse to the DS18B20 sensor
    output_drive(DS18B20_PIN);      // Configure DS18B20 pin as output
    delay_us(500);                  // Wait 500 us
    output_float(DS18B20_PIN);      // Configure DS18B20 pin as input
    delay_us(100);                  // Wait to read the DS18B20 sensor response
    if(!input(DS18B20_PIN)){
        delay_us(400);              // Wait 400 us
        return TRUE;                // DS18B20 sensor is present
    }
    return FALSE;
}

void DS18B20_write_bit(int1 value){
    output_low(DS18B20_PIN);
    output_drive(DS18B20_PIN);      // Configure DS18B20 pin as output
    delay_us(2);                    // Wait 2 us
    output_bit(DS18B20_PIN, value); 
    delay_us(80);                   // Wait 80 us
    output_float(DS18B20_PIN);      // Configure DS18B20 pin as input
    delay_us(2);                    // Wait 2 us
}

void DS18B20_write_byte(int8 value){
    int8 i;
    for(i = 0; i < 8; i++){
        DS18B20_write_bit(bit_test(value,i));
    }
}

int1 DS18B20_read_bit(void){
    int1 value;
    output_low(DS18B20_PIN);
    output_drive(DS18B20_PIN);
    delay_us(2);
    output_float(DS18B20_PIN);
    delay_us(5);
    value = input(DS18B20_PIN);
    delay_us(100);
    return value;
}

int8 DS18B20_read_byte(void){
    int8 i, value = 0;
    for(i = 0; i < 8; i++){
        shift_right(&value, 1, DS18B20_read_bit());
    }
    return value;
}

int1 DS18B20_read(int16 *raw_temp_value) {
    if(!DS18B20_start()){
        return FALSE;
    }
    DS18B20_write_byte(0xCC);
    DS18B20_write_byte(0x44);
    while(DS18B20_read_byte() == 0);
    if(!DS18B20_start()){
        return FALSE;
    }
    DS18B20_write_byte(0xCC);
    DS18B20_write_byte(0xBE);
    *raw_temp_value = DS18B20_read_byte();

    *raw_temp_value |= (int16)(DS18B20_read_byte()) << 8;

    return TRUE;
}