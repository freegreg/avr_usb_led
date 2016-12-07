/*
 * leds.h
 *
 *  Created on: 5 дек. 2016 г.
 *      Author: grigori.gutu
 */

#ifndef SOURCE_LEDS_H_
#define SOURCE_LEDS_H_

#include <avr/io.h>
#include "util/delay.h"
#include <avr/interrupt.h>

#define RED_PIN 	2
#define GREEN_PIN	4
#define BLUE_PIN	1

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

#define Black	 0x00, 0x00, 0x00	//(0,0,0)
#define White	 0xFF, 0xFF, 0xFF	//(255,255,255)
#define Red	 	 0xFF, 0x00, 0x00	//(255,0,0)
#define Lime	 0x00, 0xFF, 0x00	//(0,255,0)
#define Blue	 0x00, 0x00, 0xFF	//(0,0,255)
#define Yellow	 0xFF, 0xFF, 0x00	//(255,255,0)
#define Cyan 	 0x00, 0xFF, 0xFF	//(0,255,255)
#define Magenta  0xFF, 0x00, 0xFF	//(255,0,255)
#define Silver	 0xC0, 0xC0, 0xC0	//(192,192,192)
#define Gray	 0x80, 0x80, 0x80	//(128,128,128)
#define Maroon	 0x80, 0x00, 0x00	//(128,0,0)
#define Olive	 0x80, 0x80, 0x00	//(128,128,0)
#define Green	 0x00, 0xFF, 0x00	//(0,128,0)
#define Purple	 0x80, 0x00, 0x80	//(128,0,128)
#define Teal	 0x00, 0x80, 0x80	//(0,128,128)
#define Navy	 0x00, 0x00, 0x80	//(0,0,128)
#define dark_orange		0xFF, 0x8C, 0x00	//(255,140,0)
#define orange			0xFF, 0xA5, 0x00	//(255,165,0)
#define gold			0xFF, 0xD7, 0x00	//(255,215,0)
#define aqua			0x00, 0xFF, 0xFF	//(0,255,255)
#define deep_sky_blue	0x00, 0xBF, 0xFF	//(0,191,255)
#define dodger_blue		0x1E, 0x90, 0xFF	//(30,144,255)
#define dark_magenta	0x8B, 0x00, 0x8B	//(139,0,139)
#define deep_pink		0xF1, 0x49, 0x3	//(255,20,147)
#define chocolate		0xD2, 0x69, 0x1E	//(210,105,30)
#define azure			0xF0, 0xFF, 0xFF	//(240,255,255)
#define black			0x00, 0x00, 0x00	//(0,0,0)
#define magenta			0xFF, 0x00, 0xFF	//(255,0,255)
#define pring_green		0x00, 0xFF, 0x7F	//(0,255,127)
#define orange_red		0xFF, 0x45, 0x00	//(255,69,0)
#define dark_red		0x8B, 0x00, 0x00	//(139,0,0)
#define midnight_blue	0x19, 0x19, 0x70	//(25,25,112)

void LedsDelay(uint32_t delay);
void InitTimersForLeds(void);
void InitLeds(void);

void SetColorRGB(uint8_t red, uint8_t green, uint8_t blue);
void SetColorSmoothRGB(uint8_t r, uint8_t g, uint8_t b, uint8_t del);

void LedColorWave(void);

#endif /* SOURCE_LEDS_H_ */
