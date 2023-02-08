#include <Arduino.h>
#include <SPI.h>
#ifndef _ICMH
#define _ICMH

enum AccAxis {xAxis=45, yAxis=47, zAxis=31};


//void BeginTransaction(SPIClass locSPI, uint8_t ui8CS);
uint8_t ICM_DeviceReset(SPIClass locSPI, uint8_t ui8CS);
uint8_t ICM_WhoAmI (SPIClass locSPI, uint8_t ui8CS);

uint8_t ICM_ReadREG(SPIClass locSPI, uint8_t ui8Reg, uint8_t uiCS);
uint8_t ICM_WriteREG(SPIClass locSPI, uint8_t ui8Reg, uint8_t uiCS);

uint16_t getAccAxis(SPIClass locSPI, AccAxis enAxis);

#endif