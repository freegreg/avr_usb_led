/*
 * main.c
 *
 *  Created on: 3 дек. 2016 г.
 *      Author: grigori.gutu
 */

#include "leds.h"
#include "util/delay.h"

#define SMOOTH_DELAY 25
#define COLOR_SWITCH_DELAY 5000

int main(void) {
	InitTimersForLeds();
	InitLeds();
	sei();
	while (1) {
		SetColorSmoothRGB(midnight_blue, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Red, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Green, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Blue, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Navy, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(black, SMOOTH_DELAY); //pause - leds off
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Teal, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Purple, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Olive, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Maroon, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Silver, SMOOTH_DELAY);//white
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(dark_red, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(Cyan, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(black, SMOOTH_DELAY); //pause - leds off
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(azure, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(dark_orange, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(aqua, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(orange, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(deep_sky_blue, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(gold, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(black, SMOOTH_DELAY); //pause - leds off
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(dodger_blue, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(dark_magenta, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(pring_green, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(magenta, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(orange_red, SMOOTH_DELAY);
		LedsDelay(COLOR_SWITCH_DELAY);
		SetColorSmoothRGB(black, SMOOTH_DELAY); //pause - leds off
		LedsDelay(COLOR_SWITCH_DELAY);
	}
}
