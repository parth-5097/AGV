#include <AFMotor.h>

//defining pins and variables
//#define forward 10
//#define back 11

//defining motors
AF_DCMotor motor4(4, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
//AF_DCMotor motor1(1, MOTOR12_8KHZ);
//AF_DCMotor motor2(2, MOTOR12_8KHZ);
/*
  AF_DCMotor motor1(3, MOTOR12_8KHZ);
  AF_DCMotor motor2(4, MOTOR12_8KHZ);
*/

void setup() {
  //setting the speed of motors
  motor3.setSpeed(90);
  motor4.setSpeed(90);
  Serial.begin(9600);
  //motor3.setSpeed(175);
  //motor4.setSpeed(175);

  //declaring pin types
  //pinMode(forward, OUTPUT);
  //pinMode(back, OUTPUT);
  //begin serial communication
}

void loop() {
   motor3.run(BACKWARD);
   motor4.run(BACKWARD);
   delay(1000);
   motor3.run(FORWARD);
   motor4.run(FORWARD);
   delay(1500);
   //motor1.run(RELEASE);
   //delay(3000);
   //motor1.run(BACKWARD); 
  /*analogWrite(forward,255);
  delay(2000);
  analogWrite(forward,0);
  delay(3000);
  
  analogWrite(back,255);
  delay(2000);
  analogWrite(back,0);
  delay(3000);
  */
 //motor2.run(FORWARD);
//motor3.run(FORWARD);
//motor4.run(FORWARD);
}
