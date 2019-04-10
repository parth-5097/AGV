#include <AFMotor.h>

//defining pins and variables
#define lefts A5
#define rights A4
#define speeds 75
//defining motors
AF_DCMotor motor4(4, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
/*
  AF_DCMotor motor1(3, MOTOR12_8KHZ);
  AF_DCMotor motor2(4, MOTOR12_8KHZ);
*/
int t_value=600;
void setup() {
  Serial.begin(9600);
  //setting the speed of motors
  motor1.setSpeed(speeds);
  motor2.setSpeed(speeds);
  motor3.setSpeed(speeds);
  motor4.setSpeed(speeds);

  //declaring pin types
  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);
  pinMode(A0, INPUT);
  //begin serial communication
  Serial.begin(9600);
}

void loop() {

 /*motor1.run(FORWARD);
 motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);*/

//Serial.println("left:"+String(analogRead(lefts)));
//Serial.println("right:"+String(analogRead(rights)));
int r=analogRead(rights);
int l=analogRead(lefts);
Serial.println(analogRead(A0));
if(analogRead(A0)>100)
{
  while(analogRead(A0)>100)
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
}
if(l<t_value && r<t_value) //go F_Re
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
else if(l>t_value && r>t_value) //go F_Re
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

else if(l>t_value && r<t_value) //go L_R
{
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor1.run(FORWARD);
  motor4.run(FORWARD);
}
else if(l<t_value && r>t_value) //go R_L
{
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}

//Serial.println("right"+analogRead(rights));
}
