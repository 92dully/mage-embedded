#include <WiFi.h>
#include <WebServer.h>

// AP credentials
const char* ssid = "dullyESP32";
const char* password = "th3dully";

// Static IP configuration
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

// Pin Definitions
const int ledPin = 23;
const int potPin = 34;

// Web server on port 80
WebServer server(80);

// HTML page with JavaScript to display potentiometer value
String HTML = R"rawliteral(
  <!DOCTYPE html>
  <html>
    <head>
      <title>ESP32 LED Rate</title>
      <style>
        body { font-family: Arial; text-align: center; padding-top: 50px; }
        h1 { font-size: 8vw; margin: 0 auto; }
        #potValue { font-size: 5vw; margin-top: 20px; }
      </style>
    </head>
    <body>
      <h1>ESP32 LED Rate</h1>
      <div id="potValue">Reading...</div>

      <script>
        function updatePotValue() {
          fetch('/pot')
            .then(response => response.text())
            .then(data => {
              document.getElementById('potValue').innerText = "Potentiometer Value: " + data;
            });
        }

        setInterval(updatePotValue, 1000); // Update every second
        updatePotValue(); // Initial call
      </script>
    </body>
  </html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);

  // Setup access point
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  // Serve HTML page at "/"
  server.on("/", []() {
    server.send(200, "text/html", HTML);
  });

  // Serve potentiometer value at "/pot"
  server.on("/pot", []() {
    int potValue = analogRead(potPin);
    server.send(200, "text/plain", String(potValue));
  });

  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();

  // Read potentiometer value and blink LED
  int potValue = analogRead(potPin);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  digitalWrite(ledPin, HIGH);
  delay(potValue);
  digitalWrite(ledPin, LOW);
  delay(potValue / 2);
}


/*
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
*/