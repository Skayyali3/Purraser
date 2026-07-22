# Purraser - Robotic Laser Cat Toy

Purraser's an arm robot with the catch of having a laser in place of a hand and is controlled via Bluetooth, built to be a simple and cheap way of controlling a laser that can easily be built at home, unlike the more complex robots you can find online like on Amazon.

---

## How to Build:

### Components Needed:

* Arduino (UNO or Nano work just fine)

* 3 SG90 Servo motors

* A box of Popsicle sticks / Wooden Tongue Depressor sticks / any similar sticks

* HC-06

* KY-008

* 3 or 4 screws

### Pinout

| Component | Pin Name | Target Pin / Rail | Wire Function / Notes |
| :--- | :--- | :--- | :--- |
| **All Ground Pins** | GND | **Common Ground Rail** | **Mandatory:** All system grounds must link. |
| **Arduino** | 5V / USB Pin | Battery (+) Output | Powers the logic board (5V). |
| | GND | Common Ground Rail | Main reference point. |
| **Base Servo** | VCC (Red) | Arduino 5V Rail | Power feed. |
| | GND (Black) | Common Ground Rail | System ground. |
| | Data (Yellow) | **Arduino Digital Pin 10** | Control base Servo. |
| **Shoulder Servo** | VCC (Red) | Arduino 5V Rail | Power feed. |
| | GND (Black) | Common Ground Rail | System ground. |
| | Data (Yellow) | **Arduino Digital Pin 9** | Control shoulder Servo. |
| **Elbow Servo** | VCC (Red) | Arduino 5V Rail | Power feed. |
| | GND (Black) | Common Ground Rail | System ground. |
| | Data (Yellow) | **Arduino Digital Pin 8** | Control elbow Servo. |
| **KY-008 Laser** | GND (-) | Common Ground Rail | System ground. |
| | Signal (S) | **Arduino Digital Pin 12** | Control the laser |
| **HC-06** | VCC | Arduino 5V Rail | Power feed. |
| | GND | Common Ground Rail | System ground. |
| | TX | **Arduino Digital Pin 2** | Transmit data to Arduino via SoftwareSerial |
| | RX | **Arduino  Digital Pin 3** | Receive data from Arduino via SoftwareSerial |



At the end it should look somewhat like this except final stick should be in a T shape position instead of an L shape position:

<image src="images/Overview.jpg" alt="overview" height = 155 width = 155>
<image src="images/Top_view.jpg" alt="topview" height = 155 width = 155>

---

## Tech Used:

### Libraries

* **Servo.h:** To control the three servos
* **SoftwareSerial.h:** To communicate data between the bluetooth application & the Arduino

### Application

Any serial bluetooth controller application on Android would probs work but I recommend the following due to its customizability:
[Arduino Bluetooth Controller](https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control&hl=en)

---

## Licensing

This project is licensed under the **MIT License** - For further details: **[Click Here](LICENSE)**

---

## Author:
**Saif Kayyali**