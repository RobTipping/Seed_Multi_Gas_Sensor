/*!
 * @file Multichannel_Gas_GMXXX.h
 * @brief Simple I2C driver for Seed Multi Channel Gas Sesor
 * @license The MIT License (MIT)
 * @author Rob Tipping
 * @version V0.1
 * @date 24/12/2022
 * @url
 */
#ifndef __GAS_GMXXX_H__
#define __GAS_GMXXX_H__

#include "stm32L0xx_hal.h" // Needed for I2C

#define           GMXXX_ADDRESS_0            0x08


// data registers
#define GM_102B 0x01	//NO2
#define GM_302B 0x03	//C2H5OH
#define GM_502B 0x05	//VOC
#define GM_702B 0x07	//CO



typedef struct{
	I2C_HandleTypeDef *i2cHandle;
	float nitrogenDioxide;
	float ethanol;
	float volatileOrganicCompounds;
	float carbonMonoxide;
}GMXXX;


//Initialisation
uint8_t GMXXX_Initialise(GMXXX *dev, I2C_HandleTypeDef *i2cHandle);

//Calculate data
float GMXXX_ReadNitrogenDioxide(GMXXX *dev);
float GMXXX_ReadEthanol(GMXXX *dev);
float GMXXX_ReadVolatileOrganicCompounds(GMXXX *dev);
float GMXXX_ReadCarbonMonoxide(GMXXX *dev);

//low level functions
HAL_StatusTypeDef GMXXX_ReadRegister(GMXXX *dev, uint8_t reg, uint8_t *data);
HAL_StatusTypeDef GMXXX_ReadRegisters(GMXXX *dev, uint8_t reg, uint8_t *data, uint8_t length);

HAL_StatusTypeDef GMXXX_WriteRegister(GMXXX *dev, uint8_t reg, uint8_t *data);

#endif
