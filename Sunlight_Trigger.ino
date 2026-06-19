#include <Wire.h>
#include <BH1750.h>
#include <WiFiNINA.h>

// Network credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// IFTTT settings
const char* host = "maker.ifttt.com";
const char* eventName = "sunlight_event";
const char* key = "YOUR_IFTTT_KEY";

BH1750 lightMeter;
float threshold = 50.0; 
bool sunlightActive = false;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
  float lux = lightMeter.readLightLevel();
  
  // Trigger logic
  if (lux > threshold && !sunlightActive) {
    sendNotification("Sunlight_Started");
    sunlightActive = true;
  } else if (lux <= threshold && sunlightActive) {
    sendNotification("Sunlight_Stopped");
    sunlightActive = false;
  }
  delay(2000);
}

void sendNotification(String state) {
  if (client.connect(host, 80)) {
    String url = "/trigger/" + String(eventName) + "/with/key/" + String(key) + "?value1=" + state;
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    client.stop();
  }
}
