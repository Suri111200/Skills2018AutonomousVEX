#pragma config(Sensor, in1,    lineFinder,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonarFront,     sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           wristServo,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
* #TODO:
* - finish the goddamn program (programn)
*/

#include "functions.c" // this is the file with all of the functions

task main() {
  stop();

	int threshold = 3000; // change this later based on actual black lines

	wait1Msec(1000); // wait 1 second before the program starts

  for(int i = 0; i < 4; i += 1) {
    ClearTimer(T1);

  	int counter = 0;

    while(counter != i + 1) { // loop until the line sensor discovers a line
      int currentlineFinder = SensorValue[lineFinder]; // just for debugging

      backward(32);

      if(SensorValue[lineFinder] > threshold && time1[T1] > 500) {
        counter += 1;
        ClearTimer(T1);
      }
    }

    // sonar-reliant version of above while loop
    /*
    while(SensorValue[sonarBack] > 10.375 + i * 4.75) {
      backward(32);
    }
    */

    turnRight(90); // if the robot gets to the line, turn right to face the pipes

    moveArm(45);
    // setClawState('o'); // get ready to grab claw

    // all numbers for SensorValue[sonarFront] are in inches
    while(SensorValue[sonarFront] > 5) { // move until drive train is close enough that claw can grab pipe
      forward(32);
    }
    stop();

    setClawState('c'); // grab a pipe

    backward(32,1000);

    turnLeft(90);

    while(SensorValue[sonarFront] > 6) {
      forward(32);
    }
    stop();

    turnClaw(90);
    setClawState('o');
    moveArm(-45); // drop pipe

    turnClaw(-90);
  }
}
