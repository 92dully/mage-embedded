# WiFi_Webserver

## Description

This project uses an ***Arduino ESP32 DevKitC V4*** board as a Wi-Fi access point to host a web server. Through the hosted website, users can remotely control the LED, turning it on or off with a simple click.

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
- 2 male to female cables
- antenna

Have your Arduino ESP32 connected to power and the antenna connected to the board.

***LED setup:*** Cable from pin 23(ESP32) to the 200Ω resistor input, resistor output to LED input, LED output to Ground(GND pin) via cable

## Software

Install the latest version of the Arduino IDE and the ESP32 drivers if you plan to modify or create your own microboard. If you already have an ESP32 with the code pre-installed, then you don't need to download anything.

Here is a snippit of the code:

```c++
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
```

## Installation

There is no installation required for this project. Simply connect the **ESP32** and the components, as described in the hardware setup and download the required Software.

## Usage

To use the project, follow these steps:
1. Plug in the **Arduino ESP32 DevKitC V4** to a power source.
2. The red light on the board will turn on.
3. Connect to the board via wifi: ssid = "dullyESP32", password = "th3dully";
4. Go to "192.168.1.22" on your web browser

<img src="images/led-onoff.png" alt="LED Rate image" width="50%">

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