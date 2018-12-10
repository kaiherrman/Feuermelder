
#include <DHT.h>;
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


#define DHTPIN 13 // pin we're connected to
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE); 
const char* ssid = "iPhoneX Kai 2018"; // SSID  of Access Point 
const char* password = "test12345"; // Password of Access Point

ESP8266WebServer server(80);

//Variables
float hum;  //humidity 
float temp; //temperature

/*
 * Function for handling empty routes
 */
void handleRoot() {
  server.send(200, "text/plain", "Server working");
}

/*
 * Function for getting Temperature Values
 */
void getTempValues(){
  temp = dht.readTemperature(); //Setting temp to current temperature
  server.send(200, "text/plain", (String) temp); //sending temperature
}

void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); //Connect to access point
  Serial.println(""); //Waiting for connection to access point
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid); //Printing ssid to Serial Monitor
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //Printing web-server IP to Serial Monitor

  server.on("/", handleRoot); //Default route

  server.on("/temp", getTempValues); //Route for temp GET
  
  server.begin(); //Start server
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();
}

   
