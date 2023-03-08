/*
 * switch.c
 *
 *  Created on: Oct 11, 2022
 *      Author: SW2142
 */

#include "main.h"

__weak void onSwitch(int n)
{
	UNUSED(n);
}

__weak void onOther(int n)
{
	UNUSED(n);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin >= 0 && GPIO_Pin < 4) {
		onSwitch(GPIO_Pin + 1);
	}
	else {
		onOther(GPIO_Pin);
	}
}
