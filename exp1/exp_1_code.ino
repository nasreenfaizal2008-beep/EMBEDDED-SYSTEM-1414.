
// Gas Leakage and Human Motion Detection System
// Arduino UNO with FreeRTOS not required

#define MQ2 A0
#define PIR 2
#define TRIG 9
#define ECHO 8
#define LED 10
#define BUZZER 12

long duration;
int distance;
int gasValue;
int motion;

void setup()
{
  Serial.begin(9600);

  pinMode(MQ2, INPUT);
  pinMode(PIR, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("System Started");
  Serial.println("----------------------");
}

void loop()
{
  // Read Gas Sensor
  gasValue = analogRead(MQ2);

  // Read PIR Sensor
  motion = digitalRead(PIR);

  // Ultrasonic Sensor
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0)
  {
    distance = -1;
  }
  else
  {
    distance = duration * 0.034 / 2;
  }

  // Display Gas Level
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  // Display Motion Status
  if (motion == HIGH)
  {
    Serial.println("Motion: DETECTED");
  }
  else
  {
    Serial.println("Motion: NOT DETECTED");
  }

  // Display Distance
  Serial.print("Distance: ");
  if (distance == -1)
    Serial.println("Out of range");
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Gas Alert
  if (gasValue > 400)
  {
    Serial.println("GAS ALERT!");
  }

  // Motion Alert
  if (motion == HIGH)
  {
    Serial.println("HUMAN DETECTED!");
  }

  // Alarm Control
  if (gasValue > 400 || motion == HIGH)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  Serial.println("----------------------");

  delay(1000);
}
