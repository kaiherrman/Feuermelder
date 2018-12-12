#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "iPhoneX Kai 2018"; // SSID  of Access Point 
const char* password = "test12345"; // Password of Access Point

const char* link = "http://172.20.10.4/temp"; //The address of the temperature route on the server

void setup() {
  Serial.begin(115200); //Set baud rate
  pinMode(2, OUTPUT); //Set this pin for output
  pinMode(13, OUTPUT); //Set this pin for output
  digitalWrite(2, 0);
  WiFi.mode(WIFI_STA); //Disable access point functionality for this client
  WiFi.begin(ssid, password); //Connect to access point
  Serial.println(""); //Begin new line
  while (WiFi.status() != WL_CONNECTED) {  //Waiting for connection to access point
    delay(500);
    Serial.print(".");
  }
  Serial.println("");  
  Serial.print("Connected to ");
  Serial.println(ssid); //Printing ssid to Serial Monitor
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //Printing web-server IP to Serial Monitor
}

void loop() {
  HTTPClient http; //Create instance of HTTPClient

  http.begin(link); //Begin connection to predefined link
  int httpCode = http.GET(); //Save http response code from request
  String payload = http.getString(); //Set payload to temperature from request

  //Example for testing
  if( payload.toInt() > 50){ //If temperature is higher than 50°C
    digitalWrite(13, HIGH); //Set pin 13 to high
    Serial.println("high");
  }else{ //If temperature is lower than 51°C
    digitalWrite(13, LOW); //Set pin 13 to low
    Serial.println("low");
  }
 
  Serial.println(httpCode); //Print http response code
  Serial.println(payload);  //Print temperature


  http.end(); //End http connection

  delay(1000); //wait 1 second
}
