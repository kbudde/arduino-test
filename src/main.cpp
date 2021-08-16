#include <Arduino.h>
#include "rfid.h"
#include "ibutton.h"

void setup()
{
  Serial.begin(9600); 
  initRFID();
}

void loop()
{
  readIButton();
  readRFID();
  delay(200);
}