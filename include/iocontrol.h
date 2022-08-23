#include <Arduino.h>
byte prev_ina, prev_inb;
uint16_t inreg;
uint16_t outreg;

void read_inputs(){

    byte ina = PINJ;
    byte inb = PINC;

    if(prev_ina != ina || prev_inb != inb){
        prev_ina = ina;
        prev_inb = inb;
        return;
    }
    inreg = (ina << 8 | inb) & 0xffff;

}

void set_outputs(){
    PORTH = (outreg >> 8) & 0xff;
    PORTB = outreg & 0xff;
}

void set_ports(){
    DDRH = 0xff;
    DDRB = 0xff;
}