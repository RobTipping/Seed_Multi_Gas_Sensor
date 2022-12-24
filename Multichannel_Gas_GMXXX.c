/*!
 * @file Multichannel_Gas_GMXXX.c
 * @brief Simple I2C driver for Seed Multi Channel Gas Sesor
 * @license The MIT License (MIT)
 * @author Rob Tipping
 * @version V0.1
 * @date 24/12/2022
 * @url
 */
#include "Multichannel_Gas_GMXXX.h"

#define	GMXXX_ADDRESS	 (GMXXX_ADDRESS_0 << 1) // Define sensor address and bit shift by 1


//Initialise
uint8_t GMXXX_Initialise(GMXXX *dev, I2C_HandleTypeDef *i2cHandle)
{
	dev-> i2cHandle = i2cHandle;
	dev-> nitrogenDioxide = 0;
	dev-> ethanol = 0;
	dev-> volatileOrganicCompounds = 0;
	dev-> carbonMonoxide = 0;

	uint8_t errNum = 0;
	// need to write handshake

	return errNum;
}

float GMXXX_ReadNitrogenDioxide(GMXXX *dev)
{
	uint8_t regData[2] = {0x00};
	HAL_StatusTypeDef status = GMXXX_ReadRegisters( dev, GM_102B, regData, 2);
	dev-> nitrogenDioxide = (regData[0]<<8)+regData[1];
	return 0.0;
}

float GMXXX_ReadEthanol(GMXXX *dev)
{
	uint8_t regData[2] = {0x00};
	HAL_StatusTypeDef status = GMXXX_ReadRegisters( dev, GM_302B, regData, 2);
	dev-> ethanol = (regData[0]<<8)+regData[1];
	return 0.0;
}

float GMXXX_ReadVolatileOrganicCompounds(GMXXX *dev)
{
	uint8_t regData[2] = {0x00};
	HAL_StatusTypeDef status = GMXXX_ReadRegisters( dev, GM_502B, regData, 2);
	dev-> volatileOrganicCompounds = (regData[0]<<8)+regData[1];
	return 0.0;
}

float GMXXX_ReadCarbonMonoxide(GMXXX *dev)
{
	uint8_t regData[2] = {0x00};
	HAL_StatusTypeDef status = GMXXX_ReadRegisters( dev, GM_702B, regData, 2);
	dev-> carbonMonoxide = (regData[0]<<8)+regData[1];
	return 0.0;
}



//Low-Level Functions
HAL_StatusTypeDef GMXXX_ReadRegister(GMXXX *dev, uint8_t reg, uint8_t *data)
{
	return HAL_I2C_Mem_Read( dev->i2cHandle, GMXXX_ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}

HAL_StatusTypeDef GMXXX_ReadRegisters(GMXXX *dev, uint8_t reg, uint8_t *data, uint8_t length)
{
	return HAL_I2C_Mem_Read( dev->i2cHandle, GMXXX_ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, data, length, HAL_MAX_DELAY);
}

HAL_StatusTypeDef GMXXX_WriteRegister(GMXXX *dev, uint8_t reg, uint8_t *data)
{
	return HAL_I2C_Mem_Write( dev->i2cHandle, GMXXX_ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}

