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
const int redLedPin = 8;
const int yellowLedPin = 9;
const int greenLedPin = 10;
const int buttonPin = 2;


const int greenLightDuration = 3000;  
const int yellowLightDuration = 2000; 
const int redLightDuration = 3000;    

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
 
  if (digitalRead(buttonPin) == HIGH) {
    handlePedestrianCrossing();
  } else {
    runTrafficLightCycle();
  }
}

void runTrafficLightCycle() {
  // Green light
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  delay(greenLightDuration);
  if (digitalRead(buttonPin) == HIGH) {
    handlePedestrianCrossing();
  }

  // Yellow light
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  delay(yellowLightDuration);
  if (digitalRead(buttonPin) == HIGH) {
    handlePedestrianCrossing();
  }

  // Red light
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  delay(redLightDuration);
  if (digitalRead(buttonPin) == HIGH) {
    handlePedestrianCrossing();
  }
}

void handlePedestrianCrossing() {
  // Immediately turn red light on
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, HIGH);

  delay(redLightDuration); 
}
