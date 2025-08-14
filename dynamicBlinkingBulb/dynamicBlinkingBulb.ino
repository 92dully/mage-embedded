// Pin Definitions
const int ledPin = 23; //2 
const int potPin = 13; //32

void setup() {
  // Initialize LED output
  pinMode(ledPin, OUTPUT);
  
  // Initialize potentiometer input
  pinMode(potPin, INPUT);

  // Start Serial monitor
  Serial.begin(115200);
}

void loop() {
  // Read the potentiometer value (0 to 4095)
  int potValue = analogRead(potPin);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  
  digitalWrite(ledPin, HIGH); // LED on
  //Serial.println("high");
  delay(potValue);           
  digitalWrite(ledPin, LOW);  // LED off
  // delay(100);
  //Serial.println("low");
  delay(potValue/2);            // Use the same delay for turning it off

}

/*
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
*/
