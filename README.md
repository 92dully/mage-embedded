# MAGE Control Systems – Embedded Systems Projects

## About
This repository contains a collection of embedded systems projects completed during my work experience at **MAGE Control Systems**.  
The purpose of this work was to gain practical exposure to **embedded systems development**, which is not yet covered in my school or university curriculum, and to better understand the day-to-day work of a software engineer in a hardware-focused environment.

All projects were developed using **Arduino ESP32 DevKitC V4** boards, combining **hardware prototyping** with **firmware development** in Arduino C++.  
I wrote all the code myself with guidance from engineers at MAGE Control Systems.

---

## Hardware Used
- Multiple Arduino ESP32 boards
- Breadboards
- LEDs
- Resistors
- Potentiometers
- HS420561K-32 4-digit, 7-segment display
- Antenna (for MASTER board Wi-Fi signal)

---

## Communication Protocols
- **UART** – Serial communication between two ESP32 devices
- **Wi-Fi** – Access Point and Web Server functionality

---

## Projects Included

### 1. Wi-Fi Webserver LED On/Off
Hosts a Wi-Fi access point with a web server, allowing users to turn an LED on or off remotely via a web page.

### 2. Dynamic Blinking Bulb and Display
Controls an LED blink rate via a potentiometer and displays the blink count on a 4-digit display.

### 3. UART Between Two ESP32
Two ESP32 devices (MASTER and SLAVE) communicate over UART.  
- **SLAVE:** Reads potentiometer input, blinks LED, shows blink count on display, sends delay value to MASTER.  
- **MASTER:** Hosts a Wi-Fi AP/web server displaying the LED blink delay in real time.

### 4. Wi-Fi Webserver LED Rate
Hosts a Wi-Fi access point with a web server showing the current blink rate of an LED.

---

## Skills Developed
- Embedded systems programming in **Arduino C++**
- Hardware prototyping with breadboards and electronic components
- Implementing communication protocols: UART, Bluetooth, and Wi-Fi
- Debugging and troubleshooting firmware-hardware interactions
- Understanding the integration of hardware control and real-time data monitoring

---

## Outcomes
- All projects successfully built and tested on real hardware
- Demonstrated working prototypes to supervising engineer at MAGE Control Systems
- Strengthened foundational skills in embedded systems and firmware development

---

## Acknowledgements
Special thanks to the engineers at **MAGE Control Systems** for their guidance and support during my work experience.