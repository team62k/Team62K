#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


#define LOOP_SPEED              25
#define MAX_POWER              127
#define MIN_POWER             -127

// final motor drive
long            motor_driveR;            ///< final motor control value RIGHT
long            motor_driveL;            /// LEFT



// You may want to perform some actions before the competition starts. Do them in the
// following function.

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

// The "Driver Skills" competition has no autonomous phase. Simply leave the following placeholder.

task autonomous()
{
  AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}


// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    //left drive with deadbands
    motor[ FLWheel ] = abs(vexRT[ Ch3 ]) > 15 ? vexRT[ Ch3 ] : 0;
    motor[ BLWheel ] = abs(vexRT[ Ch3 ]) > 15 ? vexRT[ Ch3 ] : 0;

    //right drive with deadbands
    motor[ FRWheel ] = abs(vexRT[ Ch2 ]) > 15 ? vexRT[ Ch2 ] : 0;
    motor[ BRWheel ] = abs(vexRT[ Ch2 ]) > 15 ? vexRT[ Ch2 ] : 0;

    delay(100); //give it some time

    //operate the lift
    if(vexRT[ Btn5U ] || vexRT[ Btn5U ]) //test with == 1
    {
      motor[ lift ] = (vexRT[ Btn5U ] - vexRT[ Btn5U ]) * -127;
    }
    else motor[ lift ] = 0; //is this necessary?


    //killswitch
    if(vexRT[ Btn8D ] == 1)
    {
      stopAll();
    }
  }
}
