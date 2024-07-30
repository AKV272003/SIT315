const int pirSensorPin = 2; // Pin where the PIR sensor is connected
const int buzzerPin = 5; // Pin where the buzzer is connected

void setup() {
  pinMode(pirSensorPin, INPUT); // Set the PIR sensor pin as input
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as output
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  int motionState = digitalRead(pirSensorPin); // Read the state of the PIR sensor
  if (motionState == HIGH) { // Motion detected
    digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
    Serial.println("Motion detected! Buzzer is ON");
  } else {
    digitalWrite(buzzerPin, LOW); // Turn the buzzer off
    Serial.println("No motion. Buzzer is OFF");
  }
  delay(500); // Wait for half a second before the next loop
}
