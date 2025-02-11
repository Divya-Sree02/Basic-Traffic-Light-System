# Basic-Traffic-Light-System

# Overview
This Arduino-based project simulates a traffic light system that operates normally but immediately turns red when a pedestrian presses a button. The system then resumes its regular cycle after a short delay.

# Features
 -Normal Traffic Light Cycle – Green → Yellow → Red → Green.<br>
 -Pedestrian Crossing Mode – Button press turns red instantly.<br>
 -Resumes Normal Cycle After pedestrian crossing.<br>

# Components Required
-Arduino Uno <br>
-Red, Yellow, and Green LEDs <br>
-Push Button (for pedestrian crossing) <br>
-3 × 220Ω Resistors (for LEDs) <br>
-1kΩ Resistor (for button) <br>
-Breadboard & Jumper Wires.<br>

# Circuit Diagram
![image](https://github.com/user-attachments/assets/7612d257-53c6-4993-b612-ebee396c0125)
# code 
const int redLedPin = 8;<br>
const int yellowLedPin = 9;<br>
const int greenLedPin = 10;<br>
const int buttonPin = 2;<br>


const int greenLightDuration = 3000; <br> 
const int yellowLightDuration = 2000; <br>
const int redLightDuration = 3000;  <br>  

void setup() {<br>
  pinMode(redLedPin, OUTPUT);<br>
  pinMode(yellowLedPin, OUTPUT);<br>
  pinMode(greenLedPin, OUTPUT);<br>

  pinMode(buttonPin, INPUT_PULLUP);<br>
}
<br>
void loop() {<br>
 
  if (digitalRead(buttonPin) == HIGH) {<br>
    handlePedestrianCrossing();<br>
  } else {<br>
    runTrafficLightCycle();<br>
  }<br>
}<br>
<br>
void runTrafficLightCycle() {<br>
  // Green light<br>
  digitalWrite(greenLedPin, HIGH);<br>
  digitalWrite(yellowLedPin, LOW);<br>
  digitalWrite(redLedPin, LOW);<br>
  delay(greenLightDuration);<br>
  if (digitalRead(buttonPin) == HIGH) {<br>
    handlePedestrianCrossing();<br>
  }<br>

  // Yellow light<br>
  digitalWrite(greenLedPin, LOW);<br>
  digitalWrite(yellowLedPin, HIGH);<br>
  digitalWrite(redLedPin, LOW);<br>
  delay(yellowLightDuration);<br>
  if (digitalRead(buttonPin) == HIGH) {<br>
    handlePedestrianCrossing();<br>
  }

  // Red light<br>
  digitalWrite(greenLedPin, LOW);<br>
  digitalWrite(yellowLedPin, LOW);<br>
  digitalWrite(redLedPin, HIGH);<br>
  delay(redLightDuration);<br>
  if (digitalRead(buttonPin) == HIGH) {<br>
    handlePedestrianCrossing();<br>
  }<br>
}<br>

void handlePedestrianCrossing() {<br>
  // Immediately turn red light on<br>
  digitalWrite(greenLedPin, LOW);<br>
  digitalWrite(yellowLedPin, LOW);<br>
  digitalWrite(redLedPin, HIGH);<br>

  delay(redLightDuration); <br>
}<br>
