#include<Servo.h>
Servo myservo;

#define Trig 13
#define Echo 12
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

int duration, distance;



bool b1 = true;
bool b2 = false;
bool b3 = false;
bool b4 = false;
bool b5 = false;
bool b6 = false;
bool b7 = false;
bool b8 = false;
bool b9 = false;
bool b10 = false;

void setup() {
  myservo.attach(9);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
  pinMode(IN3, INPUT);
  pinMode(IN4, INPUT);

}

void loop() {
  if (b1 == true) {
    digitalWrite(Trig, HIGH);
    delay(1);
    digitalWrite(Trig, LOW);
    duration = pulseIn(Echo, HIGH);
    distance = (duration / 2) * (1 / 29.1);
    b1 = false;
    b2 = true;
  }
  if (b2 == true) {
    if (distance < 20) {
      b2 = false;
      b4 = true;
    } else {
      b2 = false;
      b3 = true;
    }
  }
  if (b3 == true) {
    fforward();
    b3 = false;
    b2 = true;
  }
  if (b4 == true) {
    fstop();
    myservo.write(20);
    delay(1000);
    duration = pulseIn(Echo, HIGH);
    distance = (duration / 2) * (1 / 29.1);
    b4 = false;
    b5 = true;
  }
  if (b5 == true) {
    if (distance < 20) {
      b5 = false;
      b7 = true;
    } else {
      b5 = false;
      b6 = true;
    }
  }
  if (b6 == true) {
    myservo.write(90);
    delay(1000);
    fright();
    delay(500);
    b6 = false;
    b2 = true;
  }
  if (b7 == true) {
    myservo.write(160);
    delay(1000);
    duration = pulseIn(Echo, HIGH);
    distance = (duration / 2) * (1 / 29.1);
    b7 = false;
    b8 = true;
  }
  if (b8 == true) {
    if (distance < 20) {
      b8 = false;
      b10 = true;

    }
  }
  if (b10 == true) {
    myservo.write(90);
    delay(1000);
    fleft();
    delay(500);
    b10 = false;
    b2 = true;
  }
  if (b9 == true) {
    myservo.write(90);
    delay(1000);
    fleft();
    delay(500);
    b9 = false;
    b2 = true;
  }
}
void fforward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void fright() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void fleft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void fstop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
