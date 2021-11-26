/*
 * SSD1351.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Matt
 */

#include "SSD1351.h"

void SSD1351_Init(t_SSD1351_InitStruct *InitStruct)
{
	/*	Power ON sequence :
	 *	- Set RES pin LOW for at least 2us then return to HIGH
	 */
	HAL_GPIO_WritePin(InitStruct->resPin.port, InitStruct->resPin.pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(InitStruct->resPin.port, InitStruct->resPin.pin, GPIO_PIN_SET);

	SSD1351_Send_SingleByte_Command(InitStruct, SSD1351_CMD_PWR_OFF);
	HAL_Delay(1000);
	SSD1351_Send_SingleByte_Command(InitStruct, SSD1351_CMD_PWR_ON);

	SSD1351_Send_SingleByte_Command(InitStruct, SSD1351_CMD_ALL_ON);
	HAL_Delay(5000);
	SSD1351_Send_SingleByte_Command(InitStruct, SSD1351_CMD_ALL_OFF);
}

void SSD1351_Send_SingleByte_Command(t_SSD1351_InitStruct *handler, uint8_t command)
{
	SPI_CS_ENABLE(handler->spiHander.nss);
	HAL_SPI_Transmit(handler->spiHander.handler, &command, 1, 10);
	SPI_CS_DISABLE(handler->spiHander.nss);
}
