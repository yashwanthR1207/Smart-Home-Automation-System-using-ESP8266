<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:00c6ff,100:0072ff&height=200&section=header&text=Smart%20Home%20Automation&fontSize=40&fontColor=ffffff&fontAlignY=35&desc=ESP8266%20NodeMCU%20%7C%20IoT%20Project&descAlignY=55&descColor=ffffff" />

<br>

<img src="https://img.shields.io/badge/Platform-ESP8266-2196F3?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/IDE-Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Protocol-HTTP%20%7C%20JSON-FF6F00?style=for-the-badge&logo=json&logoColor=white" />
<img src="https://img.shields.io/badge/Dashboard-Web%20UI-6A1B9A?style=for-the-badge&logo=googlechrome&logoColor=white" />
<img src="https://img.shields.io/badge/Status-Active-00E676?style=for-the-badge" />

<br><br>

> ### A complete IoT-based Smart Home System with real-time web dashboard, fire detection, motion sensing, temperature monitoring, RGB control, LCD display, and instant buzzer alerts — all on a single ESP8266 chip.

<br>

</div>

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Pin Configuration](#pin-configuration)
- [Software and Libraries](#software-and-libraries)
- [Web API Endpoints](#web-api-endpoints)
- [How to Run](#how-to-run)
- [Project Structure](#project-structure)
- [Future Enhancements](#future-enhancements)

---

## Overview

The **Smart Home Automation System using ESP8266** is a fully functional IoT project that combines environmental sensing, safety monitoring, and remote control into one unified platform.

The system hosts a live **web server directly on the ESP8266**, serving a responsive dashboard accessible from any browser on the same network — no external cloud required.

It demonstrates real-world embedded systems concepts including:

- Sensor integration and data acquisition
- Wi-Fi communication and HTTP server hosting
- REST JSON API design
- I2C display control
- PWM-based RGB LED actuation

---

## Features

<div align="center">

| Module | Feature | Status |
|:---:|:---|:---:|
| Temperature & Humidity | Real-time DHT11 readings on dashboard and LCD | Active |
| Fire Detection | Flame sensor with immediate buzzer alert | Active |
| Motion Detection | IR sensor with live status indicator | Active |
| RGB LED Control | Full color control via Serial commands | Active |
| 16x2 LCD Display | I2C LCD showing local sensor readings | Active |
| Live Web Dashboard | Mobile and desktop responsive UI | Active |
| JSON REST API | `/data` endpoint serving live sensor values | Active |
| Buzzer Alert | Triggered instantly on critical sensor events | Active |

</div>

---

## System Architecture
```
+==================+       +=======================+       +===================+
|    SENSORS       |       |   ESP8266 NodeMCU     |       |  OUTPUT DEVICES   |
|                  |       |                       |       |                   |
|  DHT11           +------>+  Read sensor data     +------>+  16x2 LCD         |
|  Flame Sensor    |       |  Host web server      |       |  RGB LED          |
|  IR Sensor       |       |  Serve JSON API       |       |  Buzzer           |
+==================+       |  Drive outputs        |       |  LEDs             |
                           +==========+============+       +===================+
                                      |
                                   Wi-Fi
                                      |
                           +==========+=============+
                           |      WEB DASHBOARD     |
                           |  Any Browser / IP      |
                           |  Mobile + Desktop      |
                           |  Live Auto-Refresh     |
                           +========================+
```

---

## Hardware Components

<div align="center">

| No. | Component | Description | Qty |
|:---:|:---|:---|:---:|
| 01 | ESP8266 NodeMCU | Main microcontroller with built-in Wi-Fi | 1 |
| 02 | DHT11 Sensor | Temperature and humidity sensing | 1 |
| 03 | IR Sensor | Passive infrared motion detection | 1 |
| 04 | Flame / Fire Sensor | Fire and open flame detection | 1 |
| 05 | Active Buzzer | Audio alert on critical safety events | 1 |
| 06 | RGB LED | Full-color PWM-controlled indicator | 1 |
| 07 | 16x2 LCD with I2C | Local real-time sensor data display | 1 |
| 08 | LEDs and Resistors | Room and status indicator lights | 3 |

</div>

---

## Pin Configuration

<div align="center">

### Input Sensors

| Sensor | NodeMCU Pin | GPIO | Signal |
|:---|:---:|:---:|:---:|
| DHT11 Temperature and Humidity | D4 | GPIO2 | Digital |
| Flame / Fire Sensor | D6 | GPIO12 | Digital |
| IR Motion Sensor | D5 | GPIO14 | Digital |

### Output Devices

| Device | NodeMCU Pin | GPIO | Signal |
|:---|:---:|:---:|:---:|
| Buzzer | D7 | GPIO13 | Digital |
| LED 1 | D8 | GPIO15 | Digital |
| LED 2 | D6 | GPIO12 | Digital |
| LED 3 | D3 | GPIO0 | Digital |
| RGB Red Channel | D2 | GPIO4 | PWM |
| RGB Green Channel | D1 | GPIO5 | PWM |
| RGB Blue Channel | D0 | GPIO16 | PWM |

### I2C Display

| Device | NodeMCU Pin | GPIO | Signal |
|:---|:---:|:---:|:---:|
| LCD SDA | D2 | GPIO4 | I2C Data |
| LCD SCL | D1 | GPIO5 | I2C Clock |

</div>

---

## Software and Libraries

<div align="center">

| Library | Purpose | Source |
|:---|:---|:---:|
| `ESP8266WiFi` | Wi-Fi connectivity and network management | Built-in |
| `ESP8266WebServer` | HTTP web server hosting on chip | Built-in |
| `DHT` | DHT11 temperature and humidity reading | Library Manager |
| `LiquidCrystal_I2C` | 16x2 I2C LCD control | Library Manager |
| `ArduinoJson` | JSON serialization for REST API | Library Manager |

</div>

---

## Web API Endpoints

<div align="center">

| Endpoint | Method | Description | Response Type |
|:---:|:---:|:---|:---:|
| `/` | `GET` | Serves the live web dashboard UI | `text/html` |
| `/data` | `GET` | Returns all live sensor readings | `application/json` |

</div>

### Sample JSON Response — `/data`
```json
{
  "temperature": 28.5,
  "humidity": 65.0,
  "fire": false,
  "motion": true,
  "buzzer": false
}
```

---

## How to Run

### Step 1 — Install Arduino IDE

Download and install [Arduino IDE](https://www.arduino.cc/en/software), then go to:
```
File > Preferences > Additional Board Manager URLs
```

Paste this URL:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

Then go to `Tools > Board > Board Manager` and install **ESP8266 by ESP8266 Community**.

---

### Step 2 — Install Required Libraries

Go to `Sketch > Include Library > Manage Libraries` and install:
```
DHT sensor library        — by Adafruit
LiquidCrystal I2C        — by Frank de Brabander
ArduinoJson              — by Benoit Blanchon
```

---

### Step 3 — Configure Wi-Fi Credentials

Open the main `.ino` file and update these two lines:
```cpp
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
```

---

### Step 4 — Upload to ESP8266
```
1. Connect ESP8266 to PC via USB
2. Tools > Board > NodeMCU 1.0 (ESP-12E Module)
3. Tools > Port > Select correct COM port
4. Click Upload
```

---

### Step 5 — Open the Dashboard
```
1. Open Tools > Serial Monitor
2. Set baud rate to 115200
3. Copy the IP address shown (e.g., 192.168.1.105)
4. Open that IP in any browser on the same Wi-Fi
```

---

## Project Structure
```
Smart-Home-Automation-ESP8266/
|
|-- SmartHome.ino              # Main Arduino firmware
|-- dashboard.h                # Embedded HTML/CSS/JS dashboard
|-- README.md                  # Project documentation
|
+-- circuit/
    +-- circuit_diagram.png    # Full wiring and circuit diagram
```

---

## Future Enhancements

<div align="center">

| Phase | Enhancement | Priority |
|:---:|:---|:---:|
| Phase 2 | MQTT integration for cloud-based monitoring | High |
| Phase 2 | Blynk or Home Assistant integration | High |
| Phase 3 | OTA — Over-the-Air firmware updates | Medium |
| Phase 3 | Data logging to Google Sheets or Firebase | Medium |
| Phase 4 | Voice control via Alexa or Google Assistant | Low |
| Phase 4 | AI-based anomaly detection on sensor patterns | Low |

</div>

---

<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:0072ff,100:00c6ff&height=120&section=footer" />

**Smart Home Automation System — ESP8266 IoT Project**

*Built with ESP8266 NodeMCU and Arduino IDE*

</div>
