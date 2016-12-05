#include "leds.h"

typedef struct color_ {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} color;

volatile color led_color;

void InitTimersForLeds(){
	//F_CPU/1024
	TCCR0A = ((0<<COM0A1)|(0<<COM0A0)|(0<<COM0B1)|(0<<COM0B0)|(1<<WGM01)|(0<<WGM00));
	TCCR0B = ((0<<FOC0A)|(0<<FOC0B)|(0<<WGM02)|(0<<CS02)|(0<<CS01)|(1<<CS00));
	OCR0A = 100;
	TIMSK |= (1<<OCIE0A);
}

void InitLeds(){
	LED_DDR = (1<<RED_PIN)|(1<<GREEN_PIN)|(1<<BLUE_PIN);
}

void SetColor(uint32_t clr){
	led_color.red	= (clr & 0xFF0000)>>16;
	led_color.green = (clr & 0x00FF00)>>8;
	led_color.blue 	= (clr & 0x0000FF);
}

void SetColorRGB(uint8_t red, uint8_t green, uint8_t blue){
	led_color.red	= red;
	led_color.green = green;
	led_color.blue 	= blue;
}

ISR(TIMER0_COMPA_vect){
	static color led_color_t;
	static char i = 0;
	if (++i == 0){
		led_color_t.red		= led_color.red;
		led_color_t.green 	= led_color.green;
		led_color_t.blue 	= led_color.blue;
		if (led_color_t.red 	> 0) 	LED_RED_ON();
		if (led_color_t.blue 	> 0) 	LED_BLUE_ON();
		if (led_color_t.green 	> 0)	LED_GREEN_ON();
	}
	else {
		if (led_color_t.red 	== i && led_color_t.red  	!= 0xFF) 	LED_RED_OFF();
		if (led_color_t.blue 	== i && led_color_t.blue 	!= 0xFF) 	LED_BLUE_OFF();
		if (led_color_t.green	== i && led_color_t.green 	!= 0xFF)	LED_GREEN_OFF();
	}
}

