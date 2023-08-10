//TIMER0 used for delay of 40 ms


#include <avr/io.h>

void T0Delay();
int main(int argc, char const *argv[])
{
    DDRB = 0xFF;

    while(1){
        PORTB = 0xFF;
        T0Delay();
        PORTB= 0x00;
        T0Delay;
    }

}

void T0Delay(){

    TCNT0 = 0;
    TCCR0A = 0x01;
    TCCR0B = 0x05; // Prescaler of 64, CS00 and CS02 set to 1
    unsigned char ovfCount = 0;
    while(ovfCount <20){
        while ((TIFR0 & (1 << TOV0)==0));

        TIFR0 = (1 <<TOV0);

        ovfCount++;

    }

    TCCR0B = 0x00;


    
}