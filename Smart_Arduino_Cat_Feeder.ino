#include <Servo.h>

Servo myservo;

const int servoPin = 3;
const int buttonPin = 12;

unsigned long previousMillis = 0;
const unsigned long intervalMillis = 21600000; 

void setup() {
  myservo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP); 
  myservo.write(180);
  delay(1000);
  myservo.detach();
}

void loop() {
  unsigned long currentMillis = millis();
  int buttonVal = digitalRead(buttonPin);

  
  if (buttonVal == LOW) {
    myservo.attach(servoPin);
    myservo.write(30);
    delay(3000);
    myservo.write(180);
    delay(3000);
    myservo.detach();
    delay(2000); 
  }

  
  if (currentMillis - previousMillis >= intervalMillis) {
    previousMillis = currentMillis;

    myservo.attach(servoPin);
    myservo.write(30);
    delay(3000);
    myservo.write(180);
    delay(3000);
    myservo.detach();
  }

  delay(13); 
}
