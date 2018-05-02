#pragma config(Sensor, in1,    lineFinder,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonarFront,     sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           wristServo,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//This version of the main code is based on the pseudo-code on the autonomous' google doc. It will alternate from left side and right side of the field for the first 3 pipes. for the ast 3 pipes there is a special section of code at the end.

//TO DO:
// Turn pseudo code into real code
// Adjust values for actual playoff (requires field being finished).

#include "functions.c" // this is the file with all of the functions

task main() {
    //SETUP
    stop();

    int threshold = 3000; // change this later based on actual black lines

    int counter = 0; //for counting black lines.

    wait1Msec(1000); // wait 1 second before the program starts

    //Step 1: Start at the midpoint of the performance wall facing toward the train cars. Claw should be open.
    for(int N = 1, N <= 3, N++) {
      //Step 2: Get Nth pipe on left side
      //  A: Move backward.
      backward(30)
      //  B: At Nth detection of blackline apply pipePickUp(1).
      while(counter < N){
        if(SensorValue[lineFinder] > threshold) {
          counter++
        }
      }
      counter = 0;
      stop()
      pipePickUp(1);
      //Step 3: Place pipe on train cart.
      //  A: Move forward until ultrasonic sensor detects train cart.
      //  B: Rotate 90 degrees clockwise.
      //  C: Move forward until blackline AND wall is detected.
      //  D: Apply placeDownPipe(-1)(N).
      //  E: Rotate 90 degrees anticlockwise.
      //Step 4: Get Nth pipe on right side.
      //  A: Move backward.
      //  B: At Nth detection of blackline apply pipePickUp(-1)
      //Step 5: 
      //  A: Move forward until ultrasonic sensor detects train cart.
      //  B: Rotate 90 degrees anticlockwise.
      //  C: Move forward until black line AND wall is detected.
      //  D: Apply [place pipe down](1)(N).
      //  E: Rotate 90 degrees clockwise.
      //Step 6: Repeat Steps 2-5 2 more times. (N++) 
    }
    //Step 7: Get 4th pipe on left side.
    //  A: Move backward.
    //  B: At 4th detection of backline apply pipePickUp(1).
    //Step 8: Place left 4th pipe on MIDDLE train cart.
    //  A: Move forward until ultrasonic sensor detects train cart.
    //  B: Rotate 90 degrees clockwise.
    //  C: Move forward until center line is detected.
    //  D: Apply placePipeDown(-1)(1).
    //  E: Rotate 90 degrees anticlockwise.
    //Step 9: Get 4th pipe on left side.
    //  A: Move backward.
    //  B: At 4th detection of backline apply pipePickUp(-1).
    //Step 10: Place right 4th pipe on MIDDLE train cart.
    //  A: Move forward until ultrasonic sensor detects train cart.
    //  B: Rotate 90 degrees anticlockwise.
    //  C: Move forward until center line is detected.
    //  D: Apply placePipeDown(-1)(2).
    //  E: Rotate 90 degrees anticlockwise.
    //Step 11:
    //  A: Move forward until ultrasonic sensor detects pipe.
    //  B: Close claw now holding the pipe.
    //  C: Go backwards for a bit.
    //  D: Rotate 180 degrees.
    //  E: Move forward until ultrasonic sensor detects MIDDLE train cart.
    //  F: Apply placePipeDown(0)(3)
    //  G: Back away from train carts.
  }
}

//Function to pick up a pipe from anyside of the robot. 1 for rightside. -1 for leftside. 0 for front and 2 or -2 for backside. This code will also return the robot to its position before the function was applied.
void pipePickUp(int x) {
//will need to be coded.
}