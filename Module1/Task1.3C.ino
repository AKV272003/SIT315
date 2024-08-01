// Define pin numbers for the PIR sensors and LEDs
const uint8_t PIR_SENSOR_PIN_1 = 2;
const uint8_t PIR_SENSOR_PIN_2 = 3;

const uint8_t LED_PIN_1 = 6;
const uint8_t LED_PIN_2 = 11;

// Variable to store the current LED states
volatile bool ledState_1 = LOW;
volatile bool ledState_2 = LOW;

void setup()
{
  // Set the PIR sensor pins as input with pull-up resistors
  pinMode(PIR_SENSOR_PIN_1, INPUT_PULLUP);
  pinMode(PIR_SENSOR_PIN_2, INPUT_PULLUP);

  // Set the LED pins as outputs
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);

  // Attach interrupts to PIR sensor pins
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_PIN_1), motionDetectedISR_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_PIN_2), motionDetectedISR_2, CHANGE);
}

void loop()
{
  // Empty loop, ISR handles LED control and serial output
}

// Interrupt Service Routine for PIR sensor 1
void motionDetectedISR_1()
{
  ledState_1 = !ledState_1;
  digitalWrite(LED_PIN_1, ledState_1);
  Serial.println("Motion detected! Green LED toggled!");
}

// Interrupt Service Routine for PIR sensor 2
void motionDetectedISR_2()
{
  ledState_2 = !ledState_2;
  digitalWrite(LED_PIN_2, ledState_2);
  Serial.println("Motion detected! Red LED toggled!");
}
