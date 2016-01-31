int MotorPin = 9;
int speed = 100;


void setup() {
  pinMode(MotorPin, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Speed 0 to 255");
}

void loop() {
  if(Serial.available()) {
    speed = Serial.parseInt();
    if(speed >= 0 && speed <=255) {
      analogWrite(MotorPin, speed);
      Serial.print("Speed changed to ");
      Serial.println(speed);
    }
  }
}
