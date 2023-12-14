#include <AccelStepper.h>
 
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin1 8
#define stepPin1 6
#define dirPin2 7
#define stepPin2 9
#define dirPin3 44
#define stepPin3 46
#define motorInterfaceType 1
#define pi 3.14

int v=200;


AccelStepper stepper1(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2(motorInterfaceType, stepPin2, dirPin2);// (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper3(motorInterfaceType, stepPin3, dirPin3);
// Create a new instance of the AccelStepper class:
// AccelStepper::DRIVER (1) means a stepper driver (with Step and Direction pins).
//AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
 
void setup() {

  Serial.begin(9600);
  // Set the maximum speed in steps per second:
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(500); // Set acceleration value for the stepper
  stepper1.setCurrentPosition(0); // Set the current position to 0 steps
  
  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(500); // Set acceleration value for the stepper
  stepper2.setCurrentPosition(0); // Set the current position to 0 steps

  stepper3.setMaxSpeed(1000);
  stepper3.setAcceleration(500); // Set acceleration value for the stepper
  stepper3.setCurrentPosition(0); // Set the current position to 0 steps
  
}
 
void loop() 
{   
  //1st line
  // Run the motor forward at 200 steps/second until the motor reaches 400 steps (2 revolutions):
  Serial.println("PROGRAM STARTED");
  while(stepper1.currentPosition() >= -4*v )//consider we need ot travel distance= distance of 1 rev. the vf will be full.
  {
    stepper1.setSpeed(-v);
    stepper1.runSpeed();

    stepper2.setSpeed((v/2));
    stepper2.runSpeed();

    stepper3.setSpeed((v/2));
    stepper3.runSpeed();

    Serial.println(stepper3.currentPosition());
  }
 
  delay(1000);
 
  // Reset the position to 0:
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  
  //2nd line
  while(stepper3.currentPosition() <= ((sqrt(3)*2)*(v))) 
  {
    stepper1.setSpeed(0);
    stepper1.runSpeed();

    stepper2.setSpeed(((sqrt(3)/2)*(-v)));
    stepper2.runSpeed();

    stepper3.setSpeed(((sqrt(3)/2)*(v)));
    stepper3.runSpeed();

    Serial.println(stepper1.currentPosition());
  }
 
  delay(1000);
 
  // Reset the position to 0:
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
/*
  //3rd line
  while(stepper1.currentPosition() != -v) 
  {
    stepper1.setSpeed(-v);
    stepper1.runSpeed();

    stepper2.setSpeed(v/2);
    stepper2.runSpeed();

    stepper3.setSpeed(v/2);
    stepper3.runSpeed();

    Serial.println(stepper1.currentPosition());
  }
 
  delay(1000);
 
  // Reset the position to 0:
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);

  */
 
 
 while(1);

}
