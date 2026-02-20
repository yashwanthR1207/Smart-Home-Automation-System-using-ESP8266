# Smart-Home-Automation-System-using-ESP8266
Smart Home Automation System using ESP8266 is an IoT project that monitors temperature, humidity, fire, and motion in real time. It features a web dashboard, LCD display, buzzer alert, and sensor-based automation, demonstrating practical embedded and IoT concepts.
# Smart Home Automation System using ESP8266

A complete IoT-based smart home system using ESP8266 with real-time web dashboard, fire detection, motion sensing, temperature & humidity monitoring, RGB control, LCD display, and buzzer alert.

## 🔧 Features
- 🌡️ Temperature & Humidity monitoring (DHT11)
- 🔥 Fire detection with buzzer alert
- 🚶 Motion detection using IR sensor
- 🌈 RGB LED control via Serial
- 📟 16x2 I2C LCD display
- 🌐 Web dashboard with live data (JSON API)
- 📱 Mobile & desktop responsive UI

## 🧰 Hardware Used
- ESP8266 (NodeMCU)
- DHT11 Sensor
- IR Sensor
- Fire/Flame Sensor
- Active Buzzer
- RGB LED
- 16x2 LCD with I2C
- LEDs & resistors

## 🔌 Pin Configuration
| Component | GPIO |
|---------|------|
| DHT11 | D4 |
| Fire Sensor | D6 |
| IR Sensor | D5 |
| Buzzer | D7 |
| LED1 | D8 |
| LED2 | D6 |
| LED3 | D3 |
| RGB Red | D2 |
| RGB Green | D1 |
| RGB Blue | D0 |

## 🌐 Web Endpoints
- `/` → Dashboard UI
- `/data` → JSON sensor data

## 🚀 How to Run
1. Install ESP8266 board in Arduino IDE
2. Install libraries:
   - DHT sensor library
   - LiquidCrystal I2C
3. Update WiFi credentials
4. Upload code
5. Open Serial Monitor → note IP address
6. Open IP in browser

## 📸 Screenshots
- Dashboard preview
- Circuit diagram

## 📜 License
MIT License
