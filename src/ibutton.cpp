#include "ibutton.h"
#include <OneWire.h>

OneWire ibutton(2); // I button connected on PIN 2.
byte buffer[10];    //array to store the readed Ibutton ID.

void readIButton()
{
    if (!ibutton.search(buffer))
    { //read attached ibutton and assign value to buffer
        ibutton.reset_search();
        return;
    }

    Serial.print("Die ID des iButtons lautet: ");
    for (int x = 0; x < 8; x++)
    {
        if (buffer[x] < 10)
        {
            Serial.print("0");
        }
        Serial.print(buffer[x], HEX); //print the buffer content in LSB. For MSB: for (int x = 8; x>0; x--)
        Serial.print(" ");            // print a space
    }
    Serial.println("\n"); // print new line

    for (int x = 0; x < 10; x++)
    {
        buffer[x] = 0;
    }
}