#include "rfid.h"

#include <SPI.h>     
#include <MFRC522.h> 

#define SS_PIN 10                 // SDA an Pin 10 (bei MEGA anders)
#define RST_PIN 9                 // RST an Pin 9 (bei MEGA anders)
MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID-Empfänger benennen

void initRFID()
{
    SPI.begin();
    mfrc522.PCD_Init();
}

void readRFID()
{
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    }

    Serial.print("Die ID des RFID-TAGS lautet: ");
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        if (mfrc522.uid.uidByte[i] < 10)
        {
            Serial.print("0");
        }
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        Serial.print(" ");
    }

    Serial.println();
}