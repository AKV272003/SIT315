// Define pin numbers for the PIR sensor and the buzzer
const uint8_t PIR_SENSOR_PIN = 2;
const uint8_t BUZZER_PIN = 5;

// Variable to store the current buzzer state
volatile uint8_t buzzerState = LOW;

// Interrupt Service Routine for PIR sensor detection
void motionDetectedISR()
{
  buzzerState = !buzzerState;             
  digitalWrite(BUZZER_PIN, buzzerState);   
  Serial.println("Motion detected! Buzzer is ON!");
}

void setup()
{
  // Set the PIR sensor pin as input
  pinMode(PIR_SENSOR_PIN, INPUT_PULLUP);
  // Set the buzzer pin as output
  pinMode(BUZZER_PIN, OUTPUT);
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Configure interrupt on change edge ((motion detected or no motion)
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_PIN), motionDetectedISR, CHANGE);
}

void loop()
{
  delay(1000);
  // Empty loop, ISR handles buzzer control and serial output
}
