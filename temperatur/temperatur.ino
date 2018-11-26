
#include <DHT.h>;
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


#define DHTPIN 13 // pin we're connected to
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE); 
const char* ssid = "iPhoneX Kai 2018";
const char* password = "test12345";

ESP8266WebServer server(80);

String data;


//Variables
int chk;
float hum;  //humidity 
float temp; //temperature

void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void getTempHumValues(){
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  server.send(200, "text/plain", (String) temp);
}

void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.on("/temp", getTempHumValues);
  
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
  
/*  server.begin();
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Error with WiFI Connection");
  }*/
  //Serial.println(WiFi.localIP()); //Gebt diese an die andere Gruppe
  //dht.begin();
}

void loop()
{
  server.handleClient();
  /*
  WiFiClient client = server.available();
  delay(2000);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  client.flush();
  String httpmessage = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>";
  httpmessage += temp;
  httpmessage += "</html>";
  client.print(httpmessage);
  //Print temp and humidity values
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(15000); //Delay 2 sec.*/
}

   
