# 🔐 ESP32 Smart Security System

An ESP32-based smart security prototype that detects possible intrusion when a room or shop is dark.

## 🚨 How It Works

The system continuously monitors:

* 🌑 **LDR** — detects darkness
* 📡 **IR/Disturbance Sensor** — detects movement/object presence
* 🔴 **Red LED** — indicates intrusion
* 🟢 **Green LED** — indicates secure status
* 📱 **Bluetooth** — sends alerts to a phone

### Security Logic

**Dark + Movement = Intrusion**

**Light + Movement = Normal activity**

When an intrusion is detected, the system:

1. Turns ON the red LED
2. Turns OFF the green LED
3. Sends an **INTRUSION DETECTED** message through Bluetooth

When the intrusion clears:

1. Turns OFF the red LED
2. Turns ON the green LED
3. Sends an **INTRUSION CLEARED** message

The ESP32 continues monitoring continuously, but Bluetooth messages are only sent when the security state changes.

## 🔧 Hardware

* ESP32 development board
* LDR sensor module
* IR/disturbance sensor
* Red LED
* Green LED
* 220Ω resistors
* Breadboard
* Jumper wires
* Android phone with a Bluetooth serial terminal

## 📌 Pin Connections

| Component             | ESP32 GPIO |
| --------------------- | ---------: |
| LDR                   |    GPIO 13 |
| IR/Disturbance Sensor |    GPIO 12 |
| Red LED               |    GPIO 25 |
| Green LED             |    GPIO 26 |

## 📱 Bluetooth

Bluetooth device name:

`SMART_SECURITY`

Connect the ESP32 to a Bluetooth Serial Terminal application on an Android phone.

The system reports events such as:

`INTRUSION DETECTED`

and

`INTRUSION CLEARED`

## 🧠 Sensor Logic

The current prototype uses the following tested logic:

* **LDR HIGH** → Dark
* **LDR LOW** → Light
* **IR LOW** → Movement detected
* **IR HIGH** → No movement

## ⚠️ Prototype Limitation

This is an educational embedded-systems prototype. The IR/disturbance sensor has a limited detection range, so it is not equivalent to a full-room PIR security sensor.

For a larger real-world security system, a PIR sensor, alarm/buzzer, battery backup, event logging and remote internet notifications could be added.

## 🚀 Future Improvements

* 🔊 Add an alarm buzzer
* 📱 Improve the phone interface
* 🌐 Add Wi-Fi/cloud notifications
* 🖥️ Add an OLED display
* 📊 Add intrusion event logging
* 🔋 Add battery backup
* 📡 Upgrade to a larger-range PIR sensor

## 👨‍💻 Project

Built with **ESP32 + Arduino IDE + Bluetooth + basic sensors** as an embedded/IoT security project.

