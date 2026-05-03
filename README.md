# arduino-radar-system
Arduino based radar system using ultrasonic sensor and servo motor for object detection within a specified range.

## Overview

This project simulates a radar system using an ultrasonic sensor mounted on a servo motor. When an object is detected within a defined range, the system:

- Stops scanning  
- Activates a red LED and buzzer  
- Displays detection message on LCD  
- Resumes scanning only after the object leaves the range
## Features

- Real-time object detection
- 180° scanning using servo motor
- Stops at detected object position
- LED alert on detection
- Buzzer alert on detection
- LCD status display
- Adjustable detection range
## Components Used
- Arduino Uno (or compatible board)
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90 or similar)
- 16x2 LCD Display (I2C recommended)
- Red LED
- Green LED
- Buzzer
- 2 x Resistor (220Ω for LED)
- Breadboard & jumper wires
  ## How It Works
- The servo motor scans from 0° to 180°.
- The ultrasonic sensor continuously measures distance.
- When an object is detected within the set range:
- Servo stops at that angle
  - LED turns ON
  - Buzzer activates
  - LCD displays warning
- The system remains in alert state as long as the object stays in range.
- Once the object moves away:
  - LED and buzzer turn OFF
  - Green LED turns ON
  - Servo resumes scanning
    ## Code
    [View Arduino Code](final.ino)
    ## Circuit Diagram
    [Circuit Diagram (PDF)](CircuitDiagram.pdf)
    ## Working Video
    [View Video](DemoVid.mp4)
