/*
 * main.c
 *
 *  Created on: 3 ���. 2016 �.
 *      Author: grigori.gutu
 */

#include "leds.h"


int main(void)
{
	InitTimersForLeds();
	InitLeds();
	sei();
	uint32_t clr = 0x000000;
	while(1){
		if (++clr >= 0x1000000){
			clr = 0;
		}
		SetColor(clr);
	}
}
