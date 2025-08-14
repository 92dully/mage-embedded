#include <HardwareSerial.h>

HardwareSerial SerialPort(2); // UART2 on GPIO16 (RX), GPIO17 (TX)

int pinA = 26;
int pinB = 14;
int pinC = 4;
int pinD = 18; //35;
int pinE = 32;
int pinF = 27;
int pinG = 2;
int pinDP = 34;

int D1 = 25;
int D2 = 12;
int D3 = 13;
int D4 = 15;

const int ledPin = 33;
const int potPin = 36;

unsigned long previousMillis = 0;
int ledDelay = 0;
int blinkCount = 0;

unsigned long lastSendTime = 0; // For delay transmission

void setup() {
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  ledDelay = analogRead(potPin);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= ledDelay) {
    previousMillis = currentMillis;
    digitalWrite(ledPin, HIGH);
    blinkCount++;
    if (blinkCount > 9999) blinkCount = 0;
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Display logic
  int digitD4 = blinkCount % 10;
  int digitD3 = (blinkCount / 10) % 10;
  int digitD2 = (blinkCount / 100) % 10;
  int digitD1 = (blinkCount / 1000) % 10;

  write_D1(); print_digit(digitD1); delay(1);
  write_D2(); print_digit(digitD2); delay(1);
  write_D3(); print_digit(digitD3); delay(1);
  write_D4(); print_digit(digitD4); delay(1);

  // Send delay value every 1 second
  if (millis() - lastSendTime >= 1000) {
    lastSendTime = millis();
    SerialPort.println(ledDelay); // Send current delay
  }
}

// Digit select functions
void write_D1() { digitalWrite(D1, LOW); digitalWrite(D2, HIGH); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); }
void write_D2() { digitalWrite(D1, HIGH); digitalWrite(D2, LOW); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); }
void write_D3() { digitalWrite(D1, HIGH); digitalWrite(D2, HIGH); digitalWrite(D3, LOW); digitalWrite(D4, HIGH); }
void write_D4() { digitalWrite(D1, HIGH); digitalWrite(D2, HIGH); digitalWrite(D3, HIGH); digitalWrite(D4, LOW); }

// Digit rendering functions
void print_digit(int digit) {
  switch (digit) {
    case 0: print_0(); break;
    case 1: print_1(); break;
    case 2: print_2(); break;
    case 3: print_3(); break;
    case 4: print_4(); break;
    case 5: print_5(); break;
    case 6: print_6(); break;
    case 7: print_7(); break;
    case 8: print_8(); break;
    case 9: print_9(); break;
  }
}

// Segment patterns
void print_0() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, LOW); digitalWrite(pinDP, LOW); }
void print_1() { digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); digitalWrite(pinDP, LOW); }
void print_2() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }
void print_3() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }
void print_4() { digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }
void print_5() { digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }
void print_6() { digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }
void print_7() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); digitalWrite(pinDP, LOW); }
void print_8() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }
void print_9() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); digitalWrite(pinDP, LOW); }

/*
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
*/