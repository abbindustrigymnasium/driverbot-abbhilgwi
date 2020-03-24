#define motorPinRightDir  0//D2
#define motorPinRightSpeed 5//D1
#define motorPinLeftDir 2
#define motorPinLeftSpeed 4

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPinRightDir, OUTPUT);
  pinMode(motorPinRightSpeed, OUTPUT);
  pinMode(motorPinLeftDir, OUTPUT);
  pinMode(motorPinLeftSpeed, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int speed = 1024;
  int dir = 0;

  delay(2200);
      Serial.println("Börjar");
      digitalWrite(motorPinRightDir, dir);
      analogWrite(motorPinRightSpeed, speed);
      Serial.println("Väntar");
      delay(2200);
      Serial.print("ByterHåll");
      digitalWrite(motorPinRightDir, 1);
      analogWrite(motorPinRightSpeed, speed);
      Serial.println("Slut");

  //Drivetest2(motorPinRightDir, motorPinRightSpeed);
}
