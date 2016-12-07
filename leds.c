#include "leds.h"

volatile uint8_t color_red;
volatile uint8_t color_green;
volatile uint8_t color_blue;

volatile uint32_t del = 0;

void LedsDelay(uint32_t delay) {
	del = delay;
	while (del > 0) {
		asm("nop");
	}
}

void InitTimersForLeds() {
	//F_CPU/1024
	TCCR0A = ((0 << COM0A1) | (0 << COM0A0) | (0 << COM0B1) | (0 << COM0B0)
			| (1 << WGM01) | (0 << WGM00));
	TCCR0B = ((0 << FOC0A) | (0 << FOC0B) | (0 << WGM02) | (0 << CS02)
			| (0 << CS01) | (1 << CS00));
	OCR0A = 100;
	TIMSK |= (1 << OCIE0A);
}

void InitLeds() {
	LED_DDR |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);
}

void SetColorRGB(uint8_t red, uint8_t green, uint8_t blue) {
	color_red = red;
	color_green = green;
	color_blue = blue;
}

void LedColorWave(void) {
	static uint8_t rf, gf, bf;
	if (rf) {
		if (++color_red == 0) {
			rf = 0;
		}
	} else {
		if (--color_red == 0) {
			rf = 1;
		}
	}
	if (gf) {
		if (++color_green == 0) {
			gf = 0;
		}
	} else {
		if (--color_green == 0) {
			gf = 1;
		}
	}
	if (bf) {
		if (++color_blue == 0) {
			bf = 0;
		}
	} else {
		if (--color_blue == 0) {
			bf = 1;
		}
	}
}

void SetColorSmoothRGB(uint8_t r, uint8_t g, uint8_t b, uint8_t del) {
	while (color_red != r || color_green != g || color_blue != b) {
		if (color_red < r)
			color_red++;
		if (color_red > r)
			color_red--;

		if (color_green < g)
			color_green++;
		if (color_green > g)
			color_green--;

		if (color_blue < b)
			color_blue++;
		if (color_blue > b)
			color_blue--;
		LedsDelay(del);
	}
}


ISR(TIMER0_COMPA_vect) {
	static uint8_t r, g, b;
	static uint8_t i = 0;
	static uint8_t j = 0;

	if (++i == 0) {
		r = color_red;
		g = color_green;
		b = color_blue;
		if (r > 0)
			LED_RED_ON();
		if (b > 0)
			LED_BLUE_ON();
		if (g > 0)
			LED_GREEN_ON();
	} else {
		if (i >= r && r != 0xFF)
			LED_RED_OFF();
		if (i >= b && b != 0xFF)
			LED_BLUE_OFF();
		if (i >= g && g != 0xFF)
			LED_GREEN_OFF();
	}
	if (++j >= 82) {
		j = 0;
		if (del != 0)
			--del;
	}

}

