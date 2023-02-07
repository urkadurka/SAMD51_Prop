#include <Arduino.h>
#include <Prop_SPI.h>

void setup() {
  // put your setup code here, to run once:

  // ****************************
  // Open Serial Port
  Serial.begin(115200);
  int iCnt=0;
  while(iCnt<5){
    Serial.printf("Starting %d\n",iCnt);
    delay(1000);
    iCnt++;
  }
  
  setupMySPI(); // 2^ SPI Channel for ADA ICM20948
}

void loop() {
  // put your main code here, to run repeatedly:
}