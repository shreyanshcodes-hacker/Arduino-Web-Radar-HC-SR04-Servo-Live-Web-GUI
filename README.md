# 📡 Arduino Web Radar

A real-time **Arduino-based radar system** using an **HC-SR04 ultrasonic sensor** mounted on an **SG90 servo motor**. The sensor sweeps from **0° to 180°**, measures object distances, and sends the data to a browser where it is visualized through a live radar-style GUI.

## 🚀 Demo

The system provides a live visualization of:
<img src="/Demo/image.png" width="100%">

* 📐 Current scanning angle
* 📏 Measured object distance
* 🎯 Object detection
* 🔄 Real-time 0°–180° scanning
* 📊 Radar sweep visualization
* 🔌 Live Arduino USB serial communication

---

## 🛠️ Hardware

| Component                 |    Quantity |
| ------------------------- | ----------: |
| Arduino Uno               |           1 |
| HC-SR04 Ultrasonic Sensor |           1 |
| SG90 Servo Motor          |           1 |
| Jumper Wires              | As required |
| USB Cable                 |           1 |
| Breadboard                |    Optional |

---

## 🔌 Circuit Connections

### HC-SR04 → Arduino Uno

| HC-SR04 Pin | Arduino |
| ----------- | ------- |
| VCC         | 5V      |
| GND         | GND     |
| TRIG        | D9      |
| ECHO        | D10     |

### SG90 Servo → Arduino Uno

| Servo Wire | Arduino |
| ---------- | ------- |
| Signal     | D6      |
| VCC        | 5V      |
| GND        | GND     |

> ⚠️ If the servo causes Arduino resets or unstable behavior, use a separate regulated 5V supply for the servo and connect its GND to Arduino GND.

---

## 🧠 How It Works

```text
        ┌─────────────────┐
        │   HC-SR04       │
        │ Ultrasonic      │
        │    Sensor       │
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │   Arduino Uno   │
        │                 │
        │ Distance +      │
        │ Servo Control   │
        └────────┬────────┘
                 │
          USB Serial
          115200 Baud
                 │
                 ▼
        ┌─────────────────┐
        │   Web Browser   │
        │                 │
        │ HTML/CSS/JS     │
        │ Web Serial API  │
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │  Live Radar GUI │
        │                 │
        │ Angle + Distance│
        │ Object Detection│
        └─────────────────┘
```

The SG90 rotates the ultrasonic sensor across the scanning area.

At each angle:

1. Servo moves to the required angle.
2. HC-SR04 sends an ultrasonic pulse.
3. The echo time is measured.
4. Arduino calculates the distance.
5. Arduino sends the angle and distance through USB serial.
6. The browser receives the serial data.
7. JavaScript renders the measurement on the radar interface.

---

## 📡 Serial Data Format

The Arduino sends measurements in this format:

```text
angle,distance
```

Example:

```text
0,125.4
1,123.8
2,121.6
3,119.9
45,72.5
90,38.2
135,65.7
180,110.3
```

The serial communication uses:

```text
Baud Rate: 115200
```

---

## 💻 Software

### Arduino

* Arduino IDE
* C/C++
* Servo library

### Web GUI

* HTML5
* CSS3
* JavaScript
* Canvas API
* Web Serial API

The Web Serial API allows the browser to communicate directly with the Arduino through USB.

---

## ▶️ Running the Project

### 1. Upload the Arduino Code

Open the Arduino sketch in Arduino IDE.

Select:

```text
Board: Arduino Uno
Port: Your Arduino COM Port
```

Upload the code.

### 2. Important: Close Serial Monitor

After uploading, **close Arduino Serial Monitor and Serial Plotter**.

The Arduino COM port can generally be accessed by only one application at a time.

### 3. Start the Web GUI

Open a terminal inside the web GUI folder and run:

```bash
python -m http.server 8000
```

Then open:

```text
http://localhost:8000
```

in **Google Chrome or Microsoft Edge on desktop**.

### 4. Connect Arduino

Click:

```text
Connect Arduino
```

Select the Arduino COM port.

The GUI should begin displaying live radar measurements.

---

## 🎯 Features

* [x] Arduino Uno integration
* [x] HC-SR04 distance measurement
* [x] SG90 servo scanning
* [x] 0°–180° sweep
* [x] USB serial communication
* [x] Browser-based GUI
* [x] Real-time radar visualization
* [x] Object detection threshold
* [x] Distance display
* [x] Angle display
* [x] Packet counter
* [x] Connection status
* [ ] Distance-based LED brightness
* [ ] Buzzer alerts
* [ ] Object tracking
* [ ] Distance history
* [ ] Data export
* [ ] Mobile-friendly interface

---

## 📁 Project Structure

```text
arduino-web-radar/
│
├── arduino/
│   └── radar.ino
│
├── web/
│   └── radar.html
│
├── README.md
└── LICENSE
```

---

## 🔧 Troubleshooting

### `NetworkError: Failed to open serial port`

Make sure:

* Arduino is connected through USB.
* The correct COM port is selected.
* Arduino Serial Monitor is closed.
* Arduino Serial Plotter is closed.
* No other application is using the COM port.
* Chrome or Edge is being used.
* The webpage is running through `localhost` or HTTPS.

### Radar GUI connects but no data appears

Check that the Arduino is actually sending data at:

```text
115200 baud
```

The expected format is:

```text
angle,distance
```

For example:

```text
90,42.7
```

### Servo is resetting Arduino

The SG90 can draw significant current.

Try powering the servo from a separate regulated 5V supply and make sure the external supply and Arduino share a **common GND**.

---

## 🔮 Future Improvements

The project can be extended into a more advanced robotics sensing platform with:

* Multi-object detection
* Object tracking
* Distance-based LED intensity
* Buzzer warnings
* Data logging
* Historical radar trails
* WebSocket-based communication
* Wireless ESP32 version
* Computer vision integration
* AI-based object classification

---

## 📸 Project

This project demonstrates the integration of:

**Embedded Systems + Robotics + Sensors + Serial Communication + Web Development**

It was built as a hands-on learning project to understand how physical sensor data can be processed and visualized in a modern web interface.

---

## 👨‍💻 Author

**Shreyansh Jaiswal**

B.Tech — Artificial Intelligence & Machine Learning

Interested in:

`AI • Robotics • IoT • Web Development • Automation • Hackathons`

---

## ⭐ Support

If you find this project useful or want to build your own Arduino radar, consider giving the repository a ⭐ on GitHub.

**Built with Arduino + JavaScript + curiosity. 🤖📡**
