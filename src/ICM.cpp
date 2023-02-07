#include <Prop_SPI.h>
#include <ICM.h>

uint8_t ICM_DeviceReset(SPIClass locSPI, uint8_t ui8CS) {
int ui8Rx;
    // **************
    // Select BANK 0
    BeginTransaction(locSPI, ui8CS);
    ui8Rx = locSPI.transfer(0x7f);  // Select BANK 0
    ui8Rx = locSPI.transfer(0x00);
    EndTransaction(locSPI, ui8CS);


    // **************
    // Device Reset
    BeginTransaction(locSPI, ui8CS);
    ui8Rx = locSPI.transfer(0x06);  // Device Reset
    ui8Rx = locSPI.transfer(0x00);
    EndTransaction(locSPI, ui8CS);

    return (ui8Rx);

}

uint8_t ICM_WhoAmI(SPIClass locSPI, uint8_t ui8CS) {
  int ui8Rx;
    // **************
    // Select BANK 0
    BeginTransaction(locSPI, ui8CS);
    ui8Rx = locSPI.transfer(0x7f);  // Select BANK 0
    ui8Rx = locSPI.transfer(0x00);

    //delayMicroseconds(50);
    EndTransaction(locSPI, ui8CS);

    // **************
    // Select WHO AM I request

    BeginTransaction(locSPI, ui8CS);
    ui8Rx = locSPI.transfer(0x80);
    //delayMicroseconds(10);
    ui8Rx = locSPI.transfer(0xFF);
    EndTransaction(locSPI, ui8CS);

    return(ui8Rx);
}

uint8_t ICM_ReadREG(SPIClass locSPI, uint8_t ui8Reg, uint8_t uiCS){
  byte byteRx;
   
  digitalWrite(uiCS, HIGH);
  digitalWrite(uiCS, LOW);

    
  byteRx = locSPI.transfer(ui8Reg | 0x80);
  byteRx = locSPI.transfer(0xff);

  digitalWrite(uiCS, HIGH);
  

  return((uint8_t)byteRx);
}

uint8_t ICM_WriteREG(SPIClass locSPI, uint8_t ui8Reg, uint8_t uiCS){
  uint8_t ui8Rx;
  
    digitalWrite(uiCS, HIGH);
    digitalWrite(uiCS, LOW);
  
    ui8Rx = locSPI.transfer(ui8Reg);

    digitalWrite(uiCS, HIGH);
  

  return(ui8Rx);
}