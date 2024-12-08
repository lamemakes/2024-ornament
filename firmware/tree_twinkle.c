#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "tree_twinkle.h"

void toggle_led(LED led){
    // Set all back to input pins besides the high & low pins
    DDRB = (1 << led.highPin | 1 << led.lowPin);
    PORTB = 1 << led.highPin;
}


void blink_leds(){
    for (int i = 0; i < LED_COUNT; i++) {
        toggle_led(ledArray[i]);
        _delay_ms(500);
    }

    DDRB = 0;
    PORTB = 0;
}

ISR(PCINT0_vect) {
    // ikik don't use delay during an interrupt but... it works? ¯\_(ツ)_/¯ 
    blink_leds();
}

int main(void){

    ADCSRA = 0;             // Disable ADC
    GIMSK = 1 << 5;         // General Interrupt Mask Register - Enable Pin Change Interrupts (for button)
    PCMSK = 1 << BUTTON;    // Pin Change Mask Register - Set PB0 as the PCINT pin (button pin)
    sei();                  // Enable interrupts

    blink_leds();           // She's alive

    while(1){
        // Sleep on a loop - ISR will restart this loop
        // For more info, see
        // https://onlinedocs.microchip.com/oxy/GUID-317042D4-BCCE-4065-BB05-AC4312DBC2C4-en-US-2/GUID-0EC704BC-648F-4BF6-90AE-0FAF9C596013.html
        sleep_enable();
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
        sleep_cpu();
    }
}
