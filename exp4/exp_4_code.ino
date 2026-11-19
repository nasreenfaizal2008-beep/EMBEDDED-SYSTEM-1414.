
// Automatic Temperature-Based DC Motor Speed Control
// Arduino UNO + LM35

#define TEMP_SENSOR A0
#define MOTOR_PIN 9

float temperature;
float voltage;
int sensorValue;
int pwmValue;

void setup()
{
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);

  Serial.println("Temperature Based Motor Control");
  Serial.println("--------------------------------");
}

void loop()
{
  // Read LM35 sensor
  sensorValue = analogRead(TEMP_SENSOR);

  // Convert analog value to voltage
  voltage = sensorValue * (5.0 / 1023.0);

  // Calculate temperature
  temperature = voltage * 100.0;

  // Set motor speed based on temperature
  if (temperature < 20)
  {
    pwmValue = 0;
  }
  else if (temperature < 25)
  {
    pwmValue = 77;
  }
  else if (temperature < 30)
  {
    pwmValue = 128;
  }
  else if (temperature < 35)
  {
    pwmValue = 180;
  }
  else
  {
    pwmValue = 255;
  }

  // Control DC motor speed
  analogWrite(MOTOR_PIN, pwmValue);

  // Display temperature
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C   PWM: ");

  Serial.print((pwmValue * 100) / 255);
  Serial.println("%");

  delay(1000);
}
