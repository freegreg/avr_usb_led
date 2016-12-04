/*
 * main.c
 *
 *  Created on: 3 дек. 2016 г.
 *      Author: grigori.gutu
 */

#include <avr/io.h>
#include "util/delay.h"
#include <avr/interrupt.h>

#define RED_PIN 	1
#define GREEN_PIN	0
#define BLUE_PIN	2

#define LED_PORT 	PORTD
#define LED_DDR 	DDRD

#define LEDS_ON() 	LED_PORT |= ((1<<RED_PIN)|(1<<GREEN_PIN)|(1<<BLUE_PIN))
#define LEDS_OFF() 	LED_PORT &= ~((1<<RED_PIN)|(1<<GREEN_PIN)|(1<<BLUE_PIN))

#define LED_GREEN_ON() 		LED_PORT |= (1<<GREEN_PIN)
#define LED_GREEN_OFF() 	LED_PORT &= ~(1<<GREEN_PIN)

#define LED_BLUE_ON() 		LED_PORT |= (1<<BLUE_PIN)
#define LED_BLUE_OFF() 		LED_PORT &= ~(1<<BLUE_PIN)

#define LED_RED_ON() 		LED_PORT |= (1<<RED_PIN)
#define LED_RED_OFF() 		LED_PORT &= ~(1<<RED_PIN)

void InitTimers();

int main(void)
{
	InitTimers();
	LED_DDR = (1<<RED_PIN)|(1<<GREEN_PIN)|(1<<BLUE_PIN);
	sei();
	while(1){

//		_delay_ms(333);
//		LED_GREEN_ON();
//		LED_RED_OFF();
//		_delay_ms(333);
//		LED_BLUE_ON();
//		LED_GREEN_OFF();
//		_delay_ms(333);
//		LED_RED_ON();
//		LED_BLUE_OFF();
	}
}

void InitTimers(){
	TCCR0A = ((0<<COM0A1)|(0<<COM0A0)|(0<<COM0B1)|(0<<COM0B0)|(1<<WGM01)|(0<<WGM00));
	TCCR0B = ((0<<FOC0A)|(0<<FOC0B)|(0<<WGM02)|(1<<CS02)|(0<<CS01)|(1<<CS00));
	OCR0A = 156;
	TIMSK |= (1<<OCIE0A);
}

ISR(TIMER0_COMPA_vect){
	static char flag = 0;
	if (flag) {
		LED_GREEN_ON();
		flag = 0;
	}
	else {
		LED_GREEN_OFF();
		flag = 1;
	}
}
