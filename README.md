![IMG_20260312_200508460_HDR~3](https://github.com/user-attachments/assets/d6c2c4fd-97ee-47dc-a549-c72cb12c9283)

# Smart Overhead Water Tank Motor Control Using ESP8266


## Components

* ESP8266 NodeMCU
* Ultrasonic Sensor (HC-SR04)
* OLED Display (SSD1306 128×64 I2C)
* Relay Module (5V or 3.3V compatible)

## Supporting Components
* Breadboard
* Jumper Wires
* Motor / Water Pump

## Software
* Arduino IDE<br/>
  https://www.arduino.cc/en/software/
* C++
* Required Library: U8g2lib (for OLED graphics display)

## Hardware Connections
**Component	ESP8266 Pin**<br/>
Ultrasonic TRIG	D5 (GPIO14)<br/>
Ultrasonic ECHO	D6 (GPIO12)<br/>
OLED SDA	D2 (GPIO4)<br/>
OLED SCL	D1 (GPIO5)<br/>
Relay IN	D7 (GPIO13)<br/>
(Relay & OLED) VCC	3.3V<br/>
(Relay & OLED) GND	GND

## Working Principle

The system uses an ultrasonic sensor to measure the distance between the sensor and the water surface inside the overhead tank. Based on this distance, the ESP8266 microcontroller calculates the water level percentage in the tank.

When the water level falls below a predefined threshold (for example, 30%), the ESP8266 activates the relay module to turn ON the water pump motor, allowing the tank to refill. When the water level reaches a higher threshold (for example, 90%), the system automatically turns OFF the motor to prevent overflow.

The OLED display continuously shows the water level and motor status, providing real-time feedback to the user.

## System Architecture
<img width="538" height="287" alt="image" src="https://github.com/user-attachments/assets/c3c839e7-c9e6-4f8e-a15f-16a43124493f" />


## Implementation Steps

* Connect all the components according to the pin configuration specified above. Ensure that the wiring is secure and correctly connected.

* After completing the circuit connections, connect the ESP8266 NodeMCU to your laptop using a micro-USB data cable.

* Open the Arduino IDE on your system and install the required libraries mentioned in the dependencies section.

* Once the libraries are installed, copy and paste the main program code into the Arduino IDE editor.

* Click the Verify button (✓) located at the top of the Arduino IDE to compile the code. If any errors occur, review the error messages and correct them accordingly.

* After the code compiles successfully without errors, click the Upload button (→) to upload the program to the ESP8266 microcontroller.

* Once the upload process is completed, the system will start running and the water tank motor automation system will begin monitoring the water level and controlling the motor automatically.

## Advantages of the System

* Automatic operation – no manual monitoring required

* Prevents water overflow

* Reduces water wastage

* Real-time tank level display using OLED

* Low cost and easy to implement

* Expandable to IoT monitoring using WiFi


## Applications

* Residential overhead water tanks

* Apartments and buildings

* Agricultural water storage tanks

* Industrial water tanks

* Smart home automation systems

## Future Enhancements

The system can be further improved by adding:

* AWS IoT cloud monitoring

* Mobile app for tank level monitoring

* SMS / notification alerts when tank is full or empty

* Motor dry-run protection

* Historical water usage analytics

* Voice control using Alexa or Google Assistant
