/*
 * Arduino code to control an item without internet connection
 * Author: Kenneth Murerwa
 */

//Display the output 
#define BLYNK_PRINT Serial

//Import libraries
#include <WiFi.h> //import wifi package
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//Initialize variables for wifi name and password
const char* ssid = "your router name";
const char* password = "its password";
char auth[] = "your blynk auth code";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, password);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
