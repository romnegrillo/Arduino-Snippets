#include <ESP8266WiFi.h>

String apiKey = "JVOJ47D2HFZOHYKJ"; 
const char* ssid="PLDTMyDSL";
const char* password="pldtwifiB4489";
const char* server = "api.thingspeak.com";

WiFiClient client; 

void setup() 
{
  Serial.begin(9600);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
    WiFi.disconnect();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(100);
    Serial.println("Connecting...");
  }

  Serial.println("WiFi connected");
}

void loop() 
{
  if (client.connect(server, 80)) 
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(11);
    postStr += "&status=";
    postStr += "LOW";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
  }
  
  client.stop();

  Serial.println("Waiting…");
  
  delay(15000);
}
