//Display the output 
#define BLYNK_PRINT Serial

//Import libraries
#include "esp_bt_main.h" //Import bluetooth host stack
#include "esp_gap_bt_api.h" //import functionalities
#include "esp_bt_device.h" //Import function for renaming the bluetooth device name
#include <WiFi.h> //import wifi package
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//Initialize variables for wifi name and password
const char* ssid = "Martin Router King";
const char* password = "princessleia";
char auth[] = "ed108b6e871347aa9b557980b7d09125";

bool initBluetooth(const char *deviceName) {
  /*This method starts bluetooth, renames it and returns if
  **the operation was successful
  */
  if (!btStart()) {
    return false;//Return false if bluetooth could not start
  }
  if (esp_bluedroid_init()!= ESP_OK) {
    return false;//Return false if bluedroid could not be initialized
  }
   
  if (esp_bluedroid_enable()!= ESP_OK) {
      return false;//Return false if bluedroid could not be enabled
  }
  esp_bt_dev_set_device_name(deviceName);//Change device name
  esp_bt_gap_set_scan_mode(ESP_BT_SCAN_MODE_CONNECTABLE_DISCOVERABLE); //Make bt discoverable
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, password);
  if(!initBluetooth("ESP32BT Fablab")){//Call the method initBluetooth and attempt to rename the device
    Serial.println("Bluetooth init failed");
  };
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
