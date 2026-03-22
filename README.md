<div align="center">

<img src="https://img.shields.io/badge/Platform-ESP8266-blue?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/IDE-Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Protocol-HTTP%20%7C%20JSON-orange?style=for-the-badge" />
<img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" />
<img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge" />

<br><br>

# Smart Home Automation System
### using ESP8266 NodeMCU

*A complete IoT-based smart home solution with real-time web dashboard, environmental monitoring, fire detection, motion sensing, RGB control, LCD display, and instant buzzer alerts.*

---

</div>

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
- [License](#license)

---

## Overview

The **Smart Home Automation System using ESP8266** is a fully functional IoT project that brings together environmental sensing, safety monitoring, and remote control into a single unified platform. The system runs a live web server directly on the ESP8266, serving a responsive dashboard accessible from any browser on the same network.

It demonstrates practical, real-world application of embedded systems concepts including sensor integration, Wi-Fi communication, HTTP server hosting, JSON APIs, I2C display control, and hardware actuation — all on a single low-cost microcontroller.

---

## Features

| Feature | Description |
|---|---|
| Temperature and Humidity | Real-time DHT11 readings displayed on dashboard and LCD |
| Fire Detection | Flame sensor with immediate buzzer alert on detection |
| Motion Detection | IR sensor monitoring with live status indicator |
| RGB LED Control | Full RGB control via Serial commands |
| 16x2 LCD Display | I2C LCD showing sensor readings locally |
| Live Web Dashboard | Mobile and desktop responsive UI with auto-refresh |
| JSON API | REST endpoint at `/data` serving live sensor values |
| Buzzer Alert | Active buzzer triggered on fire or critical sensor event |

---

## System Architecture
```
+------------------+        +---------------------+        +-------------------+
|   Sensors        |        |   ESP8266 NodeMCU   |        |   Output Devices  |
|                  |        |                     |        |                   |
|  DHT11           +------->+  Reads sensor data  +------->+  LCD Display      |
|  Flame Sensor    |        |  Hosts web server   |        |  RGB LED          |
|  IR Sensor       |        |  Serves JSON API    |        |  Buzzer           |
+------------------+        |  Controls outputs   |        |  LEDs             |
                            +----------+----------+        +-------------------+
                                       |
                                  (Wi-Fi)
                                       |
                            +----------+----------+
                            |    Web Dashboard    |
                            |  Any Browser / IP  |
                            |  Mobile + Desktop  |
                            +---------------------+
```

---

## Hardware Components

| No. | Component | Description | Quantity |
|-----|-----------|-------------|----------|
| 01 | ESP8266 NodeMCU | Main microcontroller with Wi-Fi | 1 |
| 02 | DHT11 Sensor | Temperature and humidity sensing | 1 |
| 03 | IR Sensor | Passive motion detection | 1 |
| 04 | Flame / Fire Sensor | Fire and flame detection | 1 |
| 05 | Active Buzzer | Audio alert on critical events | 1 |
| 06 | RGB LED | Color-controlled indicator light | 1 |
| 07 | 16x2 LCD with I2C | Local sensor data display | 1 |
| 08 | LEDs and Resistors | Status indicators | 3 |

---

## Pin Configuration

| Component | NodeMCU Pin | GPIO | Signal Type |
|-----------|-------------|------|-------------|
| DHT11 | D4 | GPIO2 | Digital |
| Fire Sensor | D6 | GPIO12 | Digital |
| IR Sensor | D5 | GPIO14 | Digital |
| Buzzer | D7 | GPIO13 | Digital |
| LED 1 | D8 | GPIO15 | Digital |
| LED 2 | D6 | GPIO12 | Digital |
| LED 3 | D3 | GPIO0 | Digital |
| RGB Red | D2 | GPIO4 | PWM |
| RGB Green | D1 | GPIO5 | PWM |
| RGB Blue | D0 | GPIO16 | PWM |
| LCD SDA | D2 | GPIO4 | I2C Data |
| LCD SCL | D1 | GPIO5 | I2C Clock |

---

## Software and Libraries

| Library | Purpose | Install Via |
|---------|---------|-------------|
| `ESP8266WiFi` | Wi-Fi connectivity | Built-in |
| `ESP8266WebServer` | HTTP web server hosting | Built-in |
| `DHT` | DHT11 sensor reading | Arduino Library Manager |
| `LiquidCrystal_I2C` | 16x2 I2C LCD control | Arduino Library Manager |
| `ArduinoJson` | JSON serialization for API | Arduino Library Manager |

---

## Web API Endpoints

| Endpoint | Method | Description | Response |
|----------|--------|-------------|----------|
| `/` | GET | Serves the live web dashboard | HTML page |
| `/data` | GET | Returns all live sensor readings | JSON object |

### Sample JSON Response
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

### Step 1 — Set Up Arduino IDE

- Download and install [Arduino IDE](https://www.arduino.cc/en/software)
- Go to `File > Preferences`
- Add this URL to Additional Board Manager URLs:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

- Go to `Tools > Board > Board Manager` and install **ESP8266**

### Step 2 — Install Required Libraries

Open `Sketch > Include Library > Manage Libraries` and install:

- `DHT sensor library` by Adafruit
- `LiquidCrystal I2C` by Frank de Brabander
- `ArduinoJson` by Benoit Blanchon

### Step 3 — Configure Wi-Fi Credentials

Open the main `.ino` file and update:
```cpp
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
```

### Step 4 — Upload the Code

- Connect ESP8266 via USB
- Select board: `Tools > Board > NodeMCU 1.0 (ESP-12E Module)`
- Select correct COM port under `Tools > Port`
- Click **Upload**

### Step 5 — Access the Dashboard

- Open `Tools > Serial Monitor` at baud rate `115200`
- Note the IP address printed on screen
- Open that IP in any browser on the same Wi-Fi network

---

## Project Structure
```
Smart-Home-Automation-ESP8266/
│
├── SmartHome.ino            # Main Arduino sketch
├── dashboard.h              # Embedded HTML/CSS dashboard
├── README.md                # Project documentation
└── circuit/
    └── circuit_diagram.png  # Wiring and circuit diagram
```

---

## Future Enhancements

| Phase | Enhancement |
|-------|-------------|
| Phase 2 | MQTT integration for cloud-based monitoring |
| Phase 2 | Blynk or Home Assistant integration |
| Phase 3 | OTA (Over-the-Air) firmware updates |
| Phase 3 | Data logging to Google Sheets or Firebase |
| Phase 4 | Voice control via Alexa or Google Assistant |
| Phase 4 | AI-based anomaly detection on sensor patterns |

---

## License
```
MIT License

Copyright (c) 2025

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
```

---

<div align="center">

Built with ESP8266 NodeMCU and Arduino IDE

**Smart Home Automation System — IoT Project**

</div>
