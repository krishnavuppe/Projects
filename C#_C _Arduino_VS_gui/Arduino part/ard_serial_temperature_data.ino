/*
Code for serial communication of Visual studios C# gui with Arduino
By: Krishna Vuppe
*/

#include <WString.h>

void serialwrite();

void setup()
{
    pinMode(13, OUTPUT); // setup the LED pin for output
    Serial.begin(9600);  //setup serial pin
    randomSeed(analogRead(0)); // to initialize random seed
}

void loop()
{
    String data = "";  // Used to store the serial data
    char datachar;     // Used to read each character and store in data

    if (Serial.available())
    {
        do
        {
            datachar = Serial.read();
            data = data + datachar; // adding the last read serial character to data
        }while(Serial.available());

        if(data == "get")
        {
            serialwrite();
            digitalWrite(13, HIGH);
            delay(2000);
            digitalWrite(13, LOW);
        }
    }
}

void serialwrite()
{
    float randtemp;
    randtemp = random(1000,2000)*0.01;
    Serial.println(randtemp,2);
}
