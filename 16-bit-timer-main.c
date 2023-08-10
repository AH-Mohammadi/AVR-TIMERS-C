#include <avr/io.h>

void T1Delay();

int main(int argc, char const *argv[]) {
    DDRB = 0xFF;

    while (1) {
        T1Delay();
        PORTB = PORTB ^ (1 < PB5);
    }

    return 0;
}

void T1Delay() {
    char TC1= 0;
    TCNT1H = 0xC1;
    TCNT1L = 0x80;

    TCCR1A = 0x00;

    TCCR1B = 0x01;
    while(TC1<= 100){
        while ((TIFR1&(0x1 << TOV1)) == 0);

        TIFR1 = (0x1 << TOV1);
        TC1++;
    }

    TIFR1 = (0x1 << TOV1);
    TCCR0A = 0x00;
}

