# On-Demand-Traffic-Lights-System

## System Description
This is the On-demand Traffic light Control System for the EgFWD Embedded Systems Professional NanoDegree Scholarship. This project was written in C Language using Microchip Atmel Studio and was tested and simulated by Proteus 8 Professional.

![image](https://user-images.githubusercontent.com/36197508/192499606-93e07698-a6c5-4135-b394-65b86ed69afb.png)

Here, we are simulating an ATMega32 Microcontroller on Proteus Professional 8.
- Connected to PORTA pins are the Car Traffic Lights (Red, Yellow, Green).
- Connected to PORTB pins are the Pedestrian Traffic Lights (Red, Yellow, Green).
- Connected to PORTC pins are the Testing Lights that are indicators for our unit tests for the system.
- Connected to PORTD pins is the external interrupt button that is used by pedestrians.

### System Flowchart
![image](https://user-images.githubusercontent.com/36197508/192501931-826772f1-a103-456e-980f-100798c651d3.png)

![image](https://user-images.githubusercontent.com/36197508/192502295-f83da6a3-fd4c-4438-9765-b7230e879ffc.png)

## System Functionality
- Car & Pedestrian Traffic Lights operate in nornal mode
  -> Green LED is on for 5 seconds
  -> Blinking Yellow LED is on for 5 seconds
  -> Red LED is on for 5 seconds
