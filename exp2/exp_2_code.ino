
// Two-Way Traffic Light Control System
// Arduino UNO

// North-South Traffic Lights
int NS_RED = 7;
int NS_YELLOW = 6;
int NS_GREEN = 5;

// East-West Traffic Lights
int EW_RED = 2;
int EW_YELLOW = 3;
int EW_GREEN = 4;

void setup()
{
  pinMode(NS_RED, OUTPUT);
  pinMode(NS_YELLOW, OUTPUT);
  pinMode(NS_GREEN, OUTPUT);

  pinMode(EW_RED, OUTPUT);
  pinMode(EW_YELLOW, OUTPUT);
  pinMode(EW_GREEN, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // STATE S0: NS GREEN - EW RED
  digitalWrite(NS_GREEN, HIGH);
  digitalWrite(NS_YELLOW, LOW);
  digitalWrite(NS_RED, LOW);

  digitalWrite(EW_RED, HIGH);
  digitalWrite(EW_YELLOW, LOW);
  digitalWrite(EW_GREEN, LOW);

  Serial.println("STATE S0: NS GREEN - EW RED");
  delay(5000);

  // STATE S1: NS YELLOW - EW RED
  digitalWrite(NS_GREEN, LOW);
  digitalWrite(NS_YELLOW, HIGH);

  Serial.println("STATE S1: NS YELLOW - EW RED");
  delay(2000);

  // STATE S2: NS RED - EW GREEN
  digitalWrite(NS_YELLOW, LOW);
  digitalWrite(NS_RED, HIGH);

  digitalWrite(EW_RED, LOW);
  digitalWrite(EW_GREEN, HIGH);

  Serial.println("STATE S2: NS RED - EW GREEN");
  delay(5000);

  // STATE S3: NS RED - EW YELLOW
  digitalWrite(EW_GREEN, LOW);
  digitalWrite(EW_YELLOW, HIGH);

  Serial.println("STATE S3: NS RED - EW YELLOW");
  delay(2000);
}
