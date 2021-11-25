/*
 * SSD1351.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Matt
 */

#ifndef INC_SSD1351_H_
#define INC_SSD1351_H_

#include "stm32l4xx_hal.h"

#define SPI_CS_ENABLE(a_s_gpio_config) 	HAL_GPIO_WritePin(a_s_gpio_config.GPIO_Port, a_s_gpio_config.GPIO_Pin, GPIO_PIN_RESET)
#define SPI_CS_DISABLE(a_s_gpio_config) HAL_GPIO_WritePin(a_s_gpio_config.GPIO_Port, a_s_gpio_config.GPIO_Pin, GPIO_PIN_SET)

void SSD1351_Init(SPI_HandleTypeDef *h_spi, GPIO_TypeDef *CSS_Port, uint16_t CSS_Pin);


#endif /* INC_SSD1351_H_ */
