/*
 * SSD1351.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Matt
 */

#include "SSD1351.h"

struct {
	GPIO_TypeDef *GPIO_Port;
	uint16_t GPIO_Pin;
}l_s_gpio_config;

void SSD1351_Init(SPI_HandleTypeDef *hspi, GPIO_TypeDef *CSS_Port, uint16_t CSS_Pin)
{
	l_s_gpio_config.GPIO_Port = CSS_Port;
	l_s_gpio_config.GPIO_Pin = CSS_Pin;

	SPI_CS_ENABLE(l_s_gpio_config);
	HAL_SPI_Transmit(hspi, 0xAA, 1, 10);
	SPI_CS_DISABLE(l_s_gpio_config);
}
