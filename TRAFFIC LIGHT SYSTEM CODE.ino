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