
#include <Wire.h>

#define PULSE_PIN 8

float temperature;
float pulseRate;

unsigned long highTime;
unsigned long lowTime;
unsigned long totalTime;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  pinMode(PULSE_PIN, INPUT);

  Serial.println("Temperature and Pulse Monitoring");
  Serial.println("--------------------------------");
}

void loop()
{
  // Read temperature from LM75AD
  Wire.beginTransmission(0x48);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(0x48, 2);

  if (Wire.available() >= 2)
  {
    int msb = Wire.read();
    int lsb = Wire.read();

    int raw = (msb << 8) | lsb;
    raw >>= 7;

    if (raw & 0x100)
      raw -= 512;

    temperature = raw * 0.5;
  }

  // Measure pulse rate
  highTime = pulseIn(PULSE_PIN, HIGH, 2000000);
  lowTime = pulseIn(PULSE_PIN, LOW, 2000000);

  totalTime = highTime + lowTime;

  if (totalTime > 0)
  {
    pulseRate = 60000000.0 / totalTime;
  }
  else
  {
    pulseRate = 0;
  }

  // Display temperature
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  // Display pulse rate
  Serial.print("Pulse Rate: ");
  Serial.print(pulseRate, 0);
  Serial.println(" BPM");

  Serial.println("----------------------------");

  delay(500);
}
