// wifi board ***COM3***

// Board 1: Transmitter ESP32 (MASTER)

#include <WiFi.h>
#include <WebServer.h>

HardwareSerial SerialPort(2); // UART2 on GPIO16 (RX) and GPIO17 (TX)

// Wi-Fi credentials
const char* ssid = "dullyESP32";
const char* password = "th3dully";

// Static IP configuration
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

// Web server on port 80
WebServer server(80);

// Variable to store delay value received from SLAVE
String delayValue = "N/A";

// HTML response
String getHTML() {
  return String(R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 LED Delay Monitor</title>
      <style>
        body { font-family: Arial; text-align: center; padding-top: 50px; }
        h1 { font-size: 6vw; margin-bottom: 20px; }
        p { font-size: 5vw; }
      </style>
      <meta http-equiv="refresh" content="1"> <!-- Auto-refresh every 1 second -->
    </head>
    <body>
      <h1>LED Delay Monitor</h1>
      <p>Current Delay: )rawliteral" + delayValue + R"rawliteral(</p>
    </body>
    </html>
  )rawliteral");
}

void handleRoot() {
  server.send(200, "text/html", getHTML());
}

void setup() {
  Serial.begin(115200);
  SerialPort.begin(115200, SERIAL_8N1, 16, 17); // RX = GPIO16, TX = GPIO17

  // Set up Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  // Set up web routes
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle web client
  server.handleClient();

  // Read delay value from SLAVE if available
  if (SerialPort.available()) {
    delayValue = SerialPort.readStringUntil('\n'); // Read until newline
    delayValue.trim(); // Remove any trailing whitespace
    Serial.println("Received delay: " + delayValue);
  }
}

/*
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
*/
