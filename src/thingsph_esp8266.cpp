/*
  ThingsPH ESP8266 - Library for connecting esp8266 boards to things.ph IoT platform
  Created by Carl Erick Rowan - Antipolo Rizal Philippines
  carlerickrowan@gmail.com
  
  https://fastproto.co
  
  Date: April 8th, 2020
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
*/

#include <Arduino.h>
#include "thingsph_esp8266.h"

String key_str;
char lib_device_key[50];

void ThingsPH::initialize(char* user, char* password, char* key)
{
  const char* mqttServer = "mqtt.things.ph";
  const int mqttPort = 1883;

  m_client.setServer(mqttServer, mqttPort);

  while (!m_client.connected())
  {
    Serial.println("Connecting...");

    if (m_client.connect("ESP8266Client", user, password))
    {
      Serial.println("Connected to Things PH1");
    }
    else
    {
      Serial.print("failed with state ");
      Serial.print(m_client.state());
      delay(2000);
    }
  }

  strcpy(lib_device_key, key);
  key_str = "/ingest/v2/" + String(lib_device_key);
//  Serial.print(key_str);
    
}

void ThingsPH::loop()
{
  m_client.loop();
}

void ThingsPH::sendUInt8(String data_name , uint8_t data)
{
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(data);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
//  Serial.println("Sending post!");
 
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}

void ThingsPH::sendUInt16(String data_name, uint16_t data)
{
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(data);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
  //  Serial.println("Sending post!");
    
    
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}

void ThingsPH::sendUInt32(String data_name, uint32_t data)
{
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(data);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
  //  Serial.println("Sending post!");
    
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}

void ThingsPH::sendInt8(String data_name , int8_t data)
{
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(data);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
  //  Serial.println("Sending post!");
    
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}

void ThingsPH::sendInt16(String data_name, int16_t data)
{
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(data);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
  //  Serial.println("Sending post!");
  
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}

void ThingsPH::sendInt32(String data_name, int32_t data)
{
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(data);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
  //  Serial.println("Sending post!");
  
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}

void ThingsPH::sendFloat(String data_name, float data)
{ 
  char float_data_str[10];
  String valueString = "";
  dtostrf(data, 4, 6, float_data_str);  //4 is mininum width, 6 is precision
    
  String data_str = "{\"payload_fields\": {";
  data_str = data_str + "\"" + data_name + "\":";
  data_str = data_str + String(float_data_str);
  data_str = data_str + "}} ";

  Serial.println(data_str);

  char payload[1000];
  data_str.toCharArray(payload, 1000);
  //  Serial.println("Sending post!");
  
  char key_chararray[50];
  key_str.toCharArray(key_chararray, 50);
  m_client.publish(key_chararray, payload);
}
