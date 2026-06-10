# Automatic Door Locking System

## Project Overview

This project implements an Automatic Door Locking System using Arduino, MFRC522 RFID Reader, Servo Motor, and Buzzer. The system uses RFID technology to authenticate users based on their unique card UID and grants access only to authorized users. It provides a simple, reliable, and cost-effective solution for access control and security applications.

## Features

* RFID-based authentication
* Multiple authorized card support
* Servo motor controlled door lock
* Access Granted / Access Denied indication
* Buzzer feedback for security alerts
* Automatic door relocking after access

## Hardware Components

* Arduino Uno
* MFRC522 RFID Reader
* RFID Tags/Cards
* Servo Motor
* Active Buzzer
* Jumper Wires
* Breadboard

## Working

1. RFID card is scanned by the MFRC522 reader.
2. The UID is compared with authorized UIDs stored in the code.
3. If the UID matches:

   * Door unlocks using the servo motor.
   * Buzzer gives a confirmation sound.
   * Door automatically locks after 5 seconds.
4. If the UID does not match:

   * Access is denied.
   * Buzzer generates warning beeps.

## Pin Connections

| Component | Arduino Pin |
| --------- | ----------- |
| RFID SDA  | D10         |
| RFID RST  | D3          |
| Servo     | D9          |
| Buzzer    | D7          |

## Libraries Used

* SPI.h
* MFRC522.h
* Servo.h

## Applications

* Smart Home Security
* Office Access Control
* Hostel & Laboratory Security
* Educational Projects
* Basic Access Management Systems

## Future Enhancements

* LCD Display Integration
* Wi-Fi/Bluetooth Connectivity
* Mobile App Control
* Attendance Logging System
* Cloud-Based Access Monitoring

## Author

Kriti Nitya

Developed using Arduino and RFID technology for embedded systems and access control applications.
