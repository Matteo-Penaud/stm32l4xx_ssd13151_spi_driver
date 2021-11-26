/*
 * SSD1351.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Matt
 */

#ifndef INC_SSD1351_H_
#define INC_SSD1351_H_

#include "stm32l4xx_hal.h"

#define SSD1351_CMD_PWR_ON 	((uint8_t) 0xAF)
#define SSD1351_CMD_PWR_OFF ((uint8_t) 0xAE)
#define SSD1351_CMD_ALL_ON 	((uint8_t) 0xA5)
#define SSD1351_CMD_ALL_OFF	((uint8_t) 0xA4)

#define SPI_CS_ENABLE(s_gpio_config) 	HAL_GPIO_WritePin(s_gpio_config.port, s_gpio_config.pin, GPIO_PIN_RESET)
#define SPI_CS_DISABLE(s_gpio_config) HAL_GPIO_WritePin(s_gpio_config.port, s_gpio_config.pin, GPIO_PIN_SET)

typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;
}t_SSD1351_GPIO;

typedef struct {
	SPI_HandleTypeDef *handler;
	t_SSD1351_GPIO nss;
}t_SSD1351_SPI_Config;

typedef struct {
	t_SSD1351_SPI_Config spiHander;
	t_SSD1351_GPIO resPin;
	t_SSD1351_GPIO dcPin;
}t_SSD1351_InitStruct;

void SSD1351_Init(t_SSD1351_InitStruct *InitStruct);
void SSD1351_Send_SingleByte_Command(t_SSD1351_InitStruct *handler, uint8_t command);

#endif /* INC_SSD1351_H_ */
