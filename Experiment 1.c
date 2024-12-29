#include "firebird_simulation.h"
#include <util/delay.h>

void buzzer_pin_config() {
	DDRC |= 0x08;        // Set PC3 as output
	PORTC &= ~0x08;      // Set PC3 to low (turn off buzzer)
}

void buzzer_on() {
	PORTC |= 0x08;       // Set PC3 high (turn on buzzer)
}

void buzzer_off() {
	PORTC &= ~0x08;      // Set PC3 low (turn off buzzer)
}

int main(void) {
	buzzer_pin_config();  // Initialize buzzer pin
	while (1) {
		buzzer_on();       // Turn on buzzer
		_delay_ms(1000);   // Wait for 1 second
		buzzer_off();      // Turn off buzzer
		_delay_ms(1000);   // Wait for 1 second
	}
}
