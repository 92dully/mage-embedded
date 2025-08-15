# WiFi_Webserver

## Description

This project uses an ***Arduino ESP32 DevKitC V4*** board as a Wi-Fi access point to host a web server. Through the hosted website, users can view the rate at which the LED is blinking.

## Table of Contents

1. [Hardware Setup](#hardware-setup)
2. [Software](#software)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Common Problems](#common-problems)
6. [Reference](#Reference)
7. [Contact](#contact)

## Hardware Setup

### Commponents required:
- Arduino ESP32 board
- Bread board
- Red LED
- 200Ω resistor
- Potentiometer
- 5 male to female cables
- antenna

Have your Arduino ESP32 connected to power and the antenna connected to the board.

***LED setup:*** Cable from pin 23(ESP32) to the 200Ω resistor input, resistor output to LED input, LED output to Ground(GND pin) via cable.

***Potentiometer setup:*** 34 pin (ESP32) to middle pin (Potentiometer), 3.3V (3V3 pin) to anyother(left or right) potentiometer pin, Ground(GND) to last potentiometer pin

## Software

Install the latest version of the Arduino IDE and the ESP32 drivers if you plan to modify or create your own microboard. If you already have an ESP32 with the code pre-installed, then you don't need to download anything.

Here is a snippit of the main loop of the code:

```c++
// Handle ON
  server.handleClient();

  // Read potentiometer value and blink LED
  int potValue = analogRead(potPin);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  digitalWrite(ledPin, HIGH);
  delay(potValue);
  digitalWrite(ledPin, LOW);
  delay(potValue / 2);
```
The main loop of the program handles incoming client requests to the web server and reads the potentiometer value. The potentiometer value determines the blink rate of the LED, with the LED turning on and off according to the read value. The delay is adjusted based on the potentiometer value to control the blinking speed.


## Installation

There is no installation required for this project. Simply connect the **ESP32** and the components, as described in the hardware setup and download the required Software.

## Usage

To use the project, follow these steps:
1. Plug in the **Arduino ESP32 DevKitC V4** to a power source.
2. The red light on the board will turn on.
3. Connect to the board via wifi: ssid = "dullyESP32", password = "th3dully".
4. Go to "192.168.1.22" on your web browser.

<img src="images/led-rate.png" alt="LED Rate image" width="50%">

## Common Problems
### Incorrect Analog Pin Usage
The ESP32 has two types of analog-to-digital converter (ADC) pins: ADC1 and ADC2. It's important to note that ADC2 pins cannot be used for analog readings when Wi-Fi is active, as the Wi-Fi driver uses the ADC2 peripheral internally.

***ADC1 Pins:***
GPIO32, GPIO33, GPIO34, GPIO35, GPIO36, GPIO39

***ADC2 Pins:***
GPIO2, GPIO4, GPIO12, GPIO13, GPIO14, GPIO15, GPIO25, GPIO26, GPIO27

Since this project uses Wi-Fi, only use ADC1 pins for analog input to avoid conflicts and ensure reliable readings.

## Reference

[Setting up an ESP32 with Arduino IDE](https://www.youtube.com/watch?v=CD8VJl27n94) In this video I learnt a bit about the ESP32 microcontroller, and how to set it up with Arduino IDE.

[Blink](https://docs.arduino.cc/built-in-examples/basics/Blink/#circuit) This example shows the simplest thing you can do with an Arduino to see physical output: it blinks the LED.

[Starting Electronics](https://startingelectronics.org/beginners/arduino-tutorial-for-beginners/read-an-analog-input-with-arduino/#:~:text=Connect%20a%20potentiometer%20to%20an%20Arduino%20analog%20input,it%20in%20the%20Arduino%20IDE%20serial%20monitor%20window.) Read an Analog Input with Arduino (using Potentiometer)

[ESP32 Access Point and Router connection explained](https://www.youtube.com/watch?v=PGt_5xQo2_0&t=524s) This video will explain how to setup an ESP32 as an Access Point or alternatively how to connect it to a router.

[ESP32 Access point](https://github.com/mo-thunderz/ESP32AccessPoint) Simple example to setup ESP32 as an Access Point or to connect ESP32 to a router

## Contact

For questions or feedback, please reach out to:

**Email:** [abdullah.muhammad@magecontrol.com](mailto:abdullah.muhammad@magecontrol.com)

<!-- 
 ____        _ _       
|  _ \ _   _| | |_   _ 
| | | | | | | | | | | |
| |_| | |_| | | | |_| |
|____/ \__,_|_|_|\__, |
                 |___/ 
                 
 -->