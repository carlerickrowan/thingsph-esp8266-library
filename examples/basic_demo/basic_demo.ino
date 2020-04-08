/*
  ThingsPH ESP8266 - Library for connecting esp8266 boards to things.ph IoT platform
  Created by Carl Erick Rowan - Antipolo Rizal Philippines
  carlerickrowan@gmail.com
  
  https://fastproto.co
  
  Date: April 9th, 2020
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
*/

#include <ESP8266WiFi.h>
#include "thingsph_esp8266.h"

#define UPDATE_INTERVAL (60000)     // This is the update interval in milliseconds.

const char* ssid = "your ssid here"; // Enter your WiFi name
const char* password = "your password here"; // Enter WiFi password

char* thingsUser = "mqtt username here";  // Get the username on things Docs/Guides under MQTT integration
char* thingsPassword = "mqtt password here"; // Get the password on things Docs/Guides under MQTT integration
char* thingsKey = "api token"; // Get the api token on API Tokens/Endpoint integration. Each unique device that will send payload to same application must have different key.

WiFiClient espClient;

ThingsPH thingsph(espClient);

uint32_t current_millis = 0;
uint32_t prev_millis = 0;

uint8_t temperature_data = 25;    // dummy temperature data!
float battery_data = 3.71;        // dummy battery data!

void setup()
{

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  thingsph.initialize(thingsUser, thingsPassword, thingsKey);

}

void loop()
{
  current_millis = millis();

  if(current_millis - prev_millis > UPDATE_INTERVAL)
  {
    prev_millis = current_millis;
    thingsph.sendUInt8("temperature", temperature_data);
    delay(1000);
    thingsph.sendFloat("battery", battery_data);
    delay(1000);
  }
    
  thingsph.loop();
}
