#include <ArduinoBLE.h>
#include "Arduino.h"
#include <Servo.h>

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
const int ledPin = LED_BUILTIN; // pin to use for the LED

char bt = 0;        //BT
int outPin1 = 9;     //motor1
int outPin2 = 10;    //motor1
int speed1 = 30;
int speed2 = 60;
int speed3 = 90;

Servo myservo1;
Servo myservo2;
int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(10);
  pinMode(ledPin, OUTPUT);
  while (!Serial);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("LED");
  BLE.setAdvertisedService(ledService);
  ledService.addCharacteristic(switchCharacteristic);   // add the characteristic to the service
  BLE.addService(ledService);                           // add service
  switchCharacteristic.writeValue(0);                   // set the initial value for the characeristic:

  // start advertising
  BLE.advertise();
  Serial.println("BLE LED Peripheral");
}

void loop() {
  BLEDevice central = BLE.central();

  if (central) {                            // if a central is connected to peripheral:
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      if (switchCharacteristic.written()) {
        if (switchCharacteristic.value() == 1) {   // any value other than 0
          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);
          myservo1.write(100);
          myservo2.write(80);
        }
        else if (switchCharacteristic.value() == 2) {
          Serial.println("LED still on");
          digitalWrite(ledPin, HIGH);
          myservo1.write(120);
          myservo2.write(60);
        }
        else if (switchCharacteristic.value() == 3) {
          Serial.println("LED still on");
          digitalWrite(ledPin, HIGH);
          myservo1.write(60);
          myservo2.write(120);
        }
        else {                              // a 0 value
          Serial.println(F("LED off"));
          digitalWrite(ledPin, LOW);
          myservo1.write(90);
          myservo2.write(90);
        }
      }
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
