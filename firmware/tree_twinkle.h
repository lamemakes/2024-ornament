#define A 3
#define B 4
#define C 2
#define D 1
#define BUTTON 0
#define LED_COUNT 12
#define F_CPU 8000000UL

// make all LED pins to be inputs
int ledInput = (0 << A) | (0 << B) | (0 << C) | (0 << D);

typedef struct {
    int highPin;
    int lowPin;
} LED;

LED ledArray[LED_COUNT] = {{A, B}, {B, A}, {B, C}, {C, B}, {C, D}, {D, C}, {A, C}, {C, A}, {B, D}, {D, B}, {A, D}, {D, A}};