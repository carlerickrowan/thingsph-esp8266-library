#include <ESP8266WiFi.h>
#include "thingsph_esp8266.h"

const char* ssid = "your ssid here"; // Enter your WiFi name
const char* password = "your password here"; // Enter WiFi password

char* thingsUser = "mqtt username here";  // Get the username on things Docs/Guides under MQTT integration
char* thingsPassword = "mqtt password here"; // Get the password on things Docs/Guides under MQTT integration
char* thingsKey = "api token"; // Get the api token on API Tokens/Endpoint integration. Each unique device that will send payload to same application must have different key.

WiFiClient espClient;

ThingsPH thingsph(espClient);

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
  thingsph.sendUInt8("temperature", temperature_data);
  delay(5000);
  thingsph.sendFloat("battery", battery_data);
  delay(25000);
}
