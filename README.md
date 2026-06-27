# 🚗 Obstacle Avoiding Robot using Arduino UNO

An autonomous **4WD (Four-Wheel Drive) Obstacle Avoiding Robot** developed using the **Arduino UNO** microcontroller. The robot utilizes an **HC-SR04 Ultrasonic Sensor** for non-contact distance measurement and an **SG90 Servo Motor** to scan the surrounding environment. Motion is controlled through an **L293D Motor Driver Shield**, which drives four DC gear motors. The robot is capable of navigating autonomously by detecting obstacles and selecting the safest direction to continue its movement.

---

## 📷 Project Overview

This project demonstrates the integration of embedded systems, sensors, motor control, and autonomous navigation using Arduino.

Once powered on, the robot continuously moves forward while monitoring the distance ahead using the ultrasonic sensor. When an obstacle is detected within the predefined threshold, the robot:

* Stops immediately.
* Moves backward slightly.
* Rotates the ultrasonic sensor to the right and measures the available distance.
* Rotates the sensor to the left and measures the available distance.
* Compares both measurements.
* Turns toward the direction with more free space.
* Continues moving forward.

This project serves as an excellent intermediate-level robotics project for learning sensor interfacing, servo control, autonomous navigation, and embedded firmware development.

---

## ✨ Features

* Autonomous obstacle avoidance
* HC-SR04 ultrasonic distance measurement
* Servo-based environmental scanning
* Automatic left/right path selection
* Four-wheel differential drive system
* Smooth motor acceleration
* Simple hardware implementation using L293D Motor Shield
* Beginner-friendly Arduino robotics project

---

## 🛠 Hardware Used

| Component                 | Quantity |
| ------------------------- | -------- |
| Arduino UNO R3            | 1        |
| L293D Motor Driver Shield | 1        |
| HC-SR04 Ultrasonic Sensor | 1        |
| SG90 Micro Servo Motor    | 1        |
| TT DC Gear Motors         | 4        |
| Robot Chassis (Acrylic)   | 1        |
| Wheels                    | 4        |
| 18650 Li-ion Battery      | 2        |
| 18650 Battery Holder      | 1        |
| ON/OFF Switch             | 1        |
| Jumper Wires              | 1 Set    |

---

## 💻 Software Used

* Arduino IDE
* C++

---

## 📚 Libraries

```cpp
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>
```

Install the following libraries from the Arduino Library Manager:

* AFMotor
* NewPing
* Servo

---

## 📌 Pin Configuration

| Device            | Arduino Pin |
| ----------------- | ----------- |
| HC-SR04 TRIG      | A0          |
| HC-SR04 ECHO      | A1          |
| SG90 Servo Signal | D10         |

> **Note:**
> The four DC motors are connected directly to the **L293D Motor Driver Shield** outputs (M1, M2, M3, and M4).

---

## 🔌 Circuit Diagram

<p align="center">
  <img src="images/circuit_diagram.jpg" width="850">
</p>

---

## 🧩 System Block Diagram

<p align="center">
  <img src="images/block_diagram.png" width="850">
</p>

---

## 📁 Repository Structure

```
Obstacle-Avoiding-Robot/
│
├── Arduino_Code/
│   └── Obstacle_Avoiding_Robot_Firmware.ino
│
├── images/
│   ├── circuit_diagram.jpg
│   ├── block_diagram.png
│   └── robot.jpg
│
├── README.md
└── LICENSE
```

---

## ⚙ Working Algorithm

```
Start
      │
      ▼
Initialize Servo
      │
      ▼
Move Forward
      │
      ▼
Read Distance
      │
      ▼
Obstacle Detected?
      │
 ┌────┴────┐
 │         │
No        Yes
 │         │
 ▼         ▼
Move      Stop
Forward    │
            ▼
      Move Backward
            │
            ▼
      Scan Right
            │
            ▼
      Scan Left
            │
            ▼
Compare Left & Right Distance
            │
      ┌─────┴─────┐
      │           │
Right Clear   Left Clear
      │           │
      ▼           ▼
 Turn Right   Turn Left
      │
      ▼
Continue Forward
      │
      └───────────────► Repeat
```

---

## 🚘 Motor Control Logic

| Robot Action | Motor 1  | Motor 2  | Motor 3  | Motor 4  |
| ------------ | -------- | -------- | -------- | -------- |
| Forward      | FORWARD  | FORWARD  | FORWARD  | FORWARD  |
| Backward     | BACKWARD | BACKWARD | BACKWARD | BACKWARD |
| Turn Left    | BACKWARD | BACKWARD | FORWARD  | FORWARD  |
| Turn Right   | FORWARD  | FORWARD  | BACKWARD | BACKWARD |
| Stop         | RELEASE  | RELEASE  | RELEASE  | RELEASE  |

---

## 📂 Repository Contents

* Arduino firmware source code
* Circuit diagram
* System block diagram
* Project images
* Complete project documentation

---

## 🚀 Future Improvements

* Replace `delay()` with `millis()` for non-blocking execution.
* Add wheel encoders for closed-loop speed control.
* Implement PID motor control.
* Integrate Bluetooth or Wi-Fi remote monitoring.
* Add LiDAR or Time-of-Flight sensor.
* Perform room mapping using SLAM.
* Integrate camera-based object detection using OpenCV or YOLO.
* Upgrade to ESP32 for wireless connectivity.

---

## 👨‍💻 Author

**Ramasamy V**

Embedded Systems & IoT Developer

**GitHub:**
https://github.com/Ramasamy15012004

---

## 📄 License

This project currently does not include an open-source license. All rights are reserved by the author.

You are welcome to view, clone, and fork this repository for educational purposes. Redistribution, commercial use, or modification for commercial projects is not permitted without prior permission from the author.

---

## ⭐ Support

If you found this project useful, consider giving this repository a **⭐ Star** on GitHub.
