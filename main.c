#pragma config(Motor,  port2,           FLWheel,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           FRWheel,       tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           BLWheel,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           BRWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"



#define LOOP_SPEED              25
#define MAX_POWER              127
#define MIN_POWER             -127

// final motor drive
long            motor_driveR;            ///< final motor control value RIGHT
long            motor_driveL;            /// LEFT

/*
	To Do List
	1. Try an empty main()
	2. what does it mean to have greater resolution in sensors?
*/


//action methods
void
liftTester(int power)
{
	motor[ lift ] = power;
	delay(150);
	motor[ lift ] = 0;
	delay(300);
	motor[lift] = -power;
	delay(100);
}

void
move( int time, int power )
{
		setDriveL(power);
		setDriveR(power);
		delay(time);
		power = 0; //what happens when i ommit this portion?
		setDriveR(power);
		setDriveL(power);
		//no delay( )?

}

//stopers
void
killAll()
{
	move(1000, 0); //check the time variable on this

	//add any other motors that need killing �??��??��??��??��??�
	//add a delay( )?
}

//setters
void
setDriveL( int valueL )
{
	motor[ FLWheel ] = valueL;
	motor[ BLWheel ] = valueL;
}

void
setDriveR( int valueR )
{
	motor[ FRWheel ] = valueR;
	motor[ BRWheel ] = valueR;
}

void
setMotorArms( int power )
{
	motor[ lift ] = power;
}

#warning "test task"
//tasks
task test()
{
		displayNextLCDString("Main task running");
		//move(1000, 100);
		liftTester(127);
		//userControl();
		break;
		//test return false;
}

#warning "autonomous"

task autonomous()
{
	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}


#warning "usercontrol"
//try making this a tankDrive()
task usercontrol()
{
  while (true) //try using '1'
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
