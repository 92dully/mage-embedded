int pinA = 14;
int pinB = 27;
int pinC = 21;
int pinD = 18;
int pinE = 17;
int pinF = 33;
int pinG = 22;
int pinDP = 19;  // the decimal point pin
int D1 = 12;     // Digit 1
int D2 = 25;     // Digit 2
int D3 = 26;     // Digit 3
int D4 = 23;     // Digit 4
int t = 250; // time delay

// Pin Definitions
const int ledPin = 2;       
const int potPin = 32;
unsigned long previousMillis = 0;  // Store the last time LED was toggled
int ledDelay = 0;  // Variable to store delay time for LED
int blinkCount = 0;  // Counter to track LED blink number

void setup() 
{                
  // initialise the digital pins as outputs.
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

  // Initialize LED output
  pinMode(ledPin, OUTPUT);
  
  // Initialize potentiometer input
  pinMode(potPin, INPUT);

  // Start Serial monitor
  Serial.begin(115200);
}

void loop() 
{ 
  // Read the potentiometer value (0 to 4095)
  ledDelay = analogRead(potPin);

  // LED control (Non-blocking using millis)
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= ledDelay) {
    previousMillis = currentMillis;
    digitalWrite(ledPin, HIGH); // LED on
    blinkCount++;  // Increment the blink count each time the LED turns on
    if (blinkCount > 9999) {  // Reset the counter after 9999
      blinkCount = 0;
    }
    //Serial.println("high");
  } else {
    digitalWrite(ledPin, LOW);  // LED off
    //Serial.println("low");
  }

  // Break down blinkCount into digits
  int digitD4 = blinkCount % 10;       // Least significant digit (ones place)
  int digitD3 = (blinkCount / 10) % 10; // Tens place
  int digitD2 = (blinkCount / 100) % 10; // Hundreds place
  int digitD1 = (blinkCount / 1000) % 10; // Thousands place

  // Display digits
  write_D1();
  print_digit(digitD1);  // Display the thousands digit (D1)
  delay(1);

  write_D2();
  print_digit(digitD2);  // Display the hundreds digit (D2)
  delay(1);

  write_D3();
  print_digit(digitD3);  // Display the tens digit (D3)
  delay(1);

  write_D4();
  print_digit(digitD4);  // Display the ones digit (D4)
  delay(1);
}

// the functions for selecting the common pin to turn on
void write_D1()
{
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
}

void write_D2()
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
}

void write_D3()
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 
}

void write_D4()
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 
}

// the functions for writing characters to the display
void print_0() // writing 0
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW); // the decimal point is always off by default
}

void print_1() // writing 1
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}

void print_2() // writing 2
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_3() // writing 3
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_4() // writing 4
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_5() // writing 5
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_6() // writing 6
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_7() // writing 7
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}

void print_8() // writing 8
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_9() // writing 9
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, LOW);
}

void print_decimal() // writing the decimal point
{
  digitalWrite(pinDP, HIGH);
}

void print_OFF() // turning all 7 segments plus the decimal point off
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}

// Print the correct digit function
void print_digit(int digit)
{
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
/*
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
*/