#include <Arduino.h>
byte prev_ina, prev_inb;
struct{
    bool in0;
}in_reg;
void read_inputs(){

    byte ina = PINJ;
    byte inb = PINC;

    if(prev_ina != ina || prev_inb != inb){
        prev_ina = ina;
        prev_inb = inb;
        return;
    }


}