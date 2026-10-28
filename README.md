# 🤖 Arduino 4WD Obstacle-Avoiding Car

An autonomous 4-wheel drive robot built with Arduino that detects obstacles using an ultrasonic distance sensor mounted on a servo motor, scans the surrounding environment, and automatically navigates around barriers.

## 🛠️ Hardware Components

* **Microcontroller:** Arduino Uno / Nano
* **Motors:** 4x DC Motors (4WD chassis)
* **Motor Driver:** L298N Motor Driver Module
* **Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Servo Motor:** SG90 Servo (for horizontal scanning)
* **Power Supply:** 4x AA Batteries / Battery pack
* **Switch:** Power toggle switch

## ⚙️ Pin Mapping & Connections

| Component / Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| **Motor Driver ENA** | Pin 11 | Speed control for Motor A (PWM) |
| **Motor Driver ENB** | Pin 5 | Speed control for Motor B (PWM) |
| **Motor Driver IN1** | Pin 2 | Direction control A1 |
| **Motor Driver IN2** | Pin 4 | Direction control A2 |
| **Motor Driver IN3** | Pin 7 | Direction control B3 |
| **Motor Driver IN4** | Pin 8 | Direction control B4 |
| **Ultrasonic Trig** | Pin 12 | Trigger pin for distance measurement |
| **Ultrasonic Echo** | Pin 13 | Echo pin for distance measurement |
| **Servo Motor** | Pin 9 | Controls sensor scanning angle |


https://github.com/user-attachments/assets/377a5edd-defb-4498-a8cd-98f6cf6266b0

