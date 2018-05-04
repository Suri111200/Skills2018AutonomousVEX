#pragma config(Sensor, in1, lineFinder, sensorLineFollower)
#pragma config(Sensor, dgtl1, sonarFront, sensorSONAR_inch)
#pragma config(Motor, port2, rightMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor, port3, leftMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor, port4, armMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor, port5, wristServo, tmotorServoStandard, openLoop)
#pragma config(Motor, port6, clawServo, tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "functions.c" // this is the file with all of the functions

task main()
{
  turn(90);
  turn(-90);
  // moveArm(-30);
  // moveArm(30);
  turnClaw(90);
  turnClaw(-90);
  turnClaw(0);
  setClawState('o');
  wait1Msec(5000);
  setClawState('c');
  wait1Msec(1000);
}