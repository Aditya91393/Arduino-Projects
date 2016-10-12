#include <Servo.h>   
int LS=10;      // declaring left sensor
int RS=11;      // declaring right sensor
int LightSensor=0; // declaring the Light sensor

Servo servoRight; // attaching Right Motor
Servo servoLeft; // attaching Left Motor

void setup()
{
pinMode(RS, INPUT); // Setting Sensors as INPUT
pinMode(LS, INPUT); 
pinMode(LightSensor, INPUT); // Setting Light Sensor as INPUT for Data Reading
}


void loop()
{
  int RS=digitalRead(11);  // activates Right Sensor
  int LS=digitalRead(10);  // activates Left Sensor

 
 if (analogRead(LightSensor) < 200) // Sets condition for LightSensor to execute the command below
{
servoLeft.attach(13); // Left wheel keeps spinning
servoRight.detach(); // Right Wheel Stops
}


else if (analogRead(LightSensor) > 600) // Sets condition for LightSensor to execute command below
{
  servoLeft.detach(); // Left Wheel Stops
  servoRight.attach(12); // Right Wheel keeps spinning
}


else if ((RS==HIGH) && (LS==HIGH))
{ 
servoLeft.attach(13); // Left Wheel Spins
servoRight.attach(12); // Right Wheel Spins
}


else if((RS==LOW) && (LS==LOW))
{  
servoRight.attach(12); // Right Wheel Spins
servoLeft.attach(13); // Left Wheel Spins
}


else if ((RS==LOW) && (LS==HIGH))
{ 
servoRight.attach(12); // Right Wheel Spins
servoLeft.detach(); // Left Wheel Stops
}
  
  
else if((RS==HIGH) && (LS==LOW))
{  
servoLeft.attach(13); // Left Wheel Spins
servoRight.detach(); // Right Wheel Stops
}
}
/* This Project was created by I, Aditya Sharma. I was able to create and program a 
line tracker & light follower robot. I successfully completed the course and was able to complete many more.
This project was a huge success. */
