#include <Servo.h>
#include <Ultrasonic.h>
// Moto driver connection ins
const int in1 = 2;  
const int in2 = 4;  
const int in3 = 7;  
const int in4 = 8; 
const int enA = 11; 
const int enB = 5;  
// Ultrasonic Sensor Initialization (Trig to 12, Echo to 13)
Ultrasonic ultrasonic(12, 13);
// ServoMotor Initiliaztion
Servo myservo;
int distance = 0;
void setup() {
  // Configuring Motor Pins as Outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Connecting servo to 9th ping and making it straight
  myservo.attach(9);
  myservo.write(90);
  Serial.begin(9600);
}
void loop() {  // Measuring the distance in front of the car
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  // If distance is longer than 20 cm the car is moving forward
  if (distance > 80) {
    forward();
    myservo.write(90);
  } else {
    stopRobot();
    delay(500);
    myservo.write(0);  // Turning servo to the right
    delay(600);
    int rightDist = ultrasonic.read();
    if (rightDist > 80) {
      turnRight();
      delay(200);
      myservo.write(90);
      delay(300);
      stopRobot();
    } else {
      stopRobot();
      delay(500);
      myservo.write(180);  // Turning servo to the left
      delay(600);
      int leftDist = ultrasonic.read();
      if (leftDist > 80) {
        turnLeft();
        delay(200);
        myservo.write(90);
        delay(300);
        stopRobot();
      } else {  //If all the ways are blocked, car is moving backward and starting again
        stopRobot();
        //myservo.write(90);
        delay(500);
        backward();
        delay(800);
        stopRobot();
      }
    }
  }
    delay(200);
}
  // Functions for motion in order to  make code simple and convenient
   void forward() {
    analogWrite(enA, 130);
    analogWrite(enB, 130);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

  void backward() {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

  void turnLeft() { 
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

  void turnRight() {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

  void stopRobot() {
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}