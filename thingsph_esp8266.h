/*
  ThingsPH ESP8266 - Library for connecting esp8266 boards to things.ph IoT platform
  Created by Carl Erick Rowan - Antipolo Rizal Philippines
  carlerickrowan@gmail.com
  
  https://fastproto.co
  
  Date: April 8th, 2020
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
*/

#ifndef ThingsPH_h
#define ThingsPH_h

#include <PubSubClient.h>


class ThingsPH
{
  public:
    // Initializes ThingsPH class with network client.
    inline ThingsPH(Client &client) : m_client(client) { }

    PubSubClient m_client;              // PubSub MQTT client instance.

    void initialize(char* user, char* password, char* key);
    void loop();
    void sendUInt8(String data_name , uint8_t data);
    void sendUInt16(String data_name ,uint16_t data);
    void sendUInt32(String data_name ,uint32_t data);

    void sendInt8(String data_name ,int8_t data);
    void sendInt16(String data_name ,int16_t data);
    void sendInt32(String data_name ,int32_t data);

    void sendFloat(String data_name ,float data);
};

#endif
