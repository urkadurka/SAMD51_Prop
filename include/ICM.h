#include <Arduino.h>
#include <SPI.h>
#ifndef _ICMH
#define _ICMH


//void BeginTransaction(SPIClass locSPI, uint8_t ui8CS);
uint8_t ICM_DeviceReset(SPIClass locSPI, uint8_t ui8CS);
uint8_t ICM_WhoAmI (SPIClass locSPI, uint8_t ui8CS);

uint8_t ICM_ReadREG(SPIClass locSPI, uint8_t ui8Reg, uint8_t uiCS);
uint8_t ICM_WriteREG(SPIClass locSPI, uint8_t ui8Reg, uint8_t uiCS);

#endif