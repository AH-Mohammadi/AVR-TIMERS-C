#include <avr/io.h>
#define F_CPU 8000000;

void T0Delay();

int main(int argc, char const *argv[]) {
    DDRB = 0xFF;
    while (1) {
        PORTB = 0xFF;

        T0Delay();
        PORTB = 0x00;
        T0Delay();
    }
    return 0;
}

void T0Delay() {
    TCNT0 = 0;      // Set the initial counter value to 0
    TCCR0A = 0x00;  // Normal mode
    TCCR0B = 0x05;  // Prescaler 1024

    uint8_t ovfCount = 0;  // Counter to track overflow occurrences

    // Wait for the overflow flag to be set 10 times
    while (ovfCount < 10) {
        while ((TIFR0 & (1 << TOV0)) == 0) {
            // Wait for timer overflow
        }

        TIFR0 = (1 << TOV0);  // Clear the overflow flag
        ovfCount++;
    }

    TCCR0B = 0x00;  // Stop the timer
}
