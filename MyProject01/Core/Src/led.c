/*
 * led.c
 *
 *  Created on: Oct 11, 2022
 *      Author: SW2142
 */

#include "main.h"

static uint8_t _led;

void onLed(int n)
{
	_led |= 1 << (n-1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 << (n-1), SET);
}

void onLedEx(int n /* led bitfeild*/)
{
	for (int i = 0; i < 4; ++i) {
		if (n >> i & 0x01) onLed(n + 1);
	}
}

void offLed(int n)
{
	_led &= ~(1 << (n-1));
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6 << (n-1), RESET);
}

void offLedEx(int n /* led bitfeild*/)
{
	for (int i = 0; i < 4; ++i) {
		if (n >> i & 0x01) offLed(n + 1);
	}
}

int *getLed(void)
{
	return _led;
}
