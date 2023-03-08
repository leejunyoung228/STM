#include "main.h"

extern UART_HandleTypeDef huart2;

int __io_putchar(int ch)
{
	if (ch == '\n') HAL_UART_Transmit(&huart2, (uint8_t*)"\r", 1, 0xFFFF);
	HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 0xFFFF);
	return ch;
}

int __io_getchar(void)
{
	uint8_t ch;
	__HAL_UART_CLEAR_OREFLAG(&huart2);
	HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
}
