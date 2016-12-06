/*
 * main.c
 *
 *  Created on: 3 дек. 2016 г.
 *      Author: grigori.gutu
 */

#include "leds.h"

int main(void) {
	InitTimersForLeds();
	InitLeds();
	sei();
	SetColorRGB(0xA0, 0xA0, 0xA0);
	while (1) {
//	LedsDelay(1000);
//	SetColorSmoothRGB(0xFF, 0x00, 0x00, 10);
//	LedsDelay(1000);
//	SetColorSmoothRGB(0x00, 0xFF, 0x00, 10);
//	LedsDelay(1000);
//	SetColorSmoothRGB(0x00, 0x00, 0xFF, 10);
	LedsDelay(1000);
	SetColorRGB(0xFF, 0x00, 0x00);
	LedsDelay(1000);
	SetColorRGB(0x00, 0xFF, 0x00);
	LedsDelay(1000);
	SetColorRGB(0x00, 0x00, 0xFF);

//		LedsDelay(1000);
//		SetColorSmoothRGB(Navy, 10);
//		LedsDelay(1000);
//		SetColorSmoothRGB(Teal, 10);
//		LedsDelay(1000);
//		SetColorSmoothRGB(Purple, 10);
//		LedsDelay(1000);
//		SetColorSmoothRGB(Olive, 10);
//		LedsDelay(1000);
//		SetColorSmoothRGB(Maroon, 10);
//		LedsDelay(1000);
//		SetColorSmoothRGB(Silver, 10);
//		LedsDelay(1000);
//		SetColorSmoothRGB(Cyan, 10);
		asm("nop");
	}
}
