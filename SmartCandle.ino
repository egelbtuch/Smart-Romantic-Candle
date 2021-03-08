//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial
#define PIN_ANALOG_IN   34
#define PIN_LED         12
#define PRESS_VAL 22  //Set a threshold to judge touch
#define RELEASE_VAL 27  //Set a threshold to judge release

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int howMany = 0;
int i = 0;
int sensorPin = 14;

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  int lightCal = analogRead(PIN_ANALOG_IN);
  while (lightCal > 2000){
      SerialBT.println("ON");
      digitalWrite(PIN_LED, HIGH);
      delay(50);
      digitalWrite(PIN_LED, LOW); 
      delay(50);
      /*if (digitalRead(sensorPin) == 1) {
          SerialBT.println("SONG");
      }*/ 
      Serial.println(touchRead(T3));       
      while(touchRead(T0) < PRESS_VAL){
        SerialBT.println("VOLUME");
        digitalWrite(PIN_LED, HIGH);
        delay(50);
        digitalWrite(PIN_LED, LOW); 
        delay(50); 
      }
      if (touchRead(T3) <= PRESS_VAL){
        howMany++;
        while(i < 10){
          digitalWrite(PIN_LED, HIGH);
          delay(25);
          digitalWrite(PIN_LED, LOW); 
          delay(25);
          if (touchRead(T3) <= PRESS_VAL) {
            howMany++;
          }
          i++;
        }
        if(howMany >= 2){
          SerialBT.print("SONG");
        }
      }
      i = 0;
      howMany = 0;
      lightCal = analogRead(PIN_ANALOG_IN);      
  }
  digitalWrite(PIN_LED, LOW);
  SerialBT.println("OFF");
}
