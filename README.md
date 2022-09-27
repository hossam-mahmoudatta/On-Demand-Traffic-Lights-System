# On-Demand-Traffic-Lights-System

## System Description
This is the On-demand Traffic light Control System for the EgFWD Embedded Systems Professional NanoDegree Scholarship. This project was written in C Language using Microchip Atmel Studio and was tested and simulated by Proteus 8 Professional.

![image](https://user-images.githubusercontent.com/36197508/192499606-93e07698-a6c5-4135-b394-65b86ed69afb.png)

Here, we are simulating an ATMega32 Microcontroller on Proteus Professional 8.
- Connected to **PORTA** pins are the Car Traffic Lights (Red, Yellow, Green).
- Connected to **PORTB** pins are the Pedestrian Traffic Lights (Red, Yellow, Green).
- Connected to **PORTC** pins are the Testing Lights that are indicators for our unit tests for the system.
- Connected to **PORTD** pins is the external interrupt button that is used by pedestrians.

### System Flowchart
![image](https://user-images.githubusercontent.com/36197508/192501931-826772f1-a103-456e-980f-100798c651d3.png)

[Here](https://drive.google.com/file/d/1AfnwDXWltdA5gQJPY0MVsqUbXjIZ0MEK/view?usp=sharing) is a detailed document about the project's description.

## System Functionality

### Car & Pedestrian Traffic Lights operate in nornal mode
- Car Green LED is on for 5 seconds   &&    Ped Red LED is on for 5 seconds
- Car Blinking Yellow LED is on for 5 seconds   &&    Ped Blinking Yellow LED is on for 5 seconds
- Car Red LED is on for 5 seconds   &&   Ped Green LED is on for 5 seconds

### When external interrupt is engaged: Car & Pedestrian Traffic Lights operate in pedestrian mode

## Files Classification
![image](https://user-images.githubusercontent.com/36197508/192508807-8086cf41-fd17-4c94-b6d0-611552b182cf.png)

- Here You can see that the proram is divided into several blocks
- Drivers are divided seperately

![image](https://user-images.githubusercontent.com/36197508/192509129-1d5de894-e858-4d89-8a21-bac14869ba1c.png)
- To run the program, you call the `TrafficLights_NormalMode(Time_Delay)` function.
- To unit test the drivers, you call either the `Testing_LED_DRIVER(PIN NUMBER, DIRECTON)` or `Testing_TIMER_DRIVER(TIMER MODE, DELAY)` functions.

Feel free to contact me if you have questions regarding this project!
