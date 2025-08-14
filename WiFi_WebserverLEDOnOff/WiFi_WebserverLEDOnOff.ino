#include <WiFi.h>
#include <WebServer.h> // Built-in library for ESP32 HTTP server

// AP credentials
const char* ssid = "dullyESP32";
const char* password = "th3dully";

// Static IP configuration (optional)
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

// Set the LED pin
#define LED_BUILTIN 23

// Create a web server on port 80
WebServer server(80);

// HTML Page
String HTML = R"rawliteral(

<!DOCTYPE html>
<html>
<head>
  <title>ESP32 LED Control</title>
  <style>
    body { font-family: Arial; text-align: center; padding-top: 50px; }
    h1 { font-size: 8vw; margin: 0 auto; }
    button { padding: 20px 70px; font-size: 24px; margin: 10px; font-size: 5vw;}
  </style>
</head>
<body>
  <h1>ESP32 LED Control</h1>
  <form action="/on"><button>ON</button></form>
  <form action="/off"><button>OFF</button></form>
</body>
</html>


)rawliteral";

// Handle root (/) route
void handleRoot() {
  server.send(200, "text/html", HTML);
}

// Handle ON
void handleOn() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED turned ON");
  server.send(200, "text/html", HTML);
}

// Handle OFF
void handleOff() {
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED turned OFF");
  server.send(200, "text/html", HTML);
}

void setup() {
  Serial.begin(115200);
  
  // Configure LED pin
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Setup access point
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  // Route setup
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient(); // Listen for incoming client requests
}


/*
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
*/