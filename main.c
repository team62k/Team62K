#pragma config(Motor,  port2,           FLWheel,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           FRWheel,       tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           BLWheel,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           BRWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
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
	1. Update the Btn stuff with (UDLR) and (5678)
	2. Ask Jon about competition template
	3. Try an empty main()
	4. what does it mean to have greater resolution in sensors?
	5. Add them deadbands
*/

//setters
void
setMotorL( int valueL )
{
	motor[ FLWheel ] = valueL;
	motor[ BLWheel ] = valueL;
}

void
setMotorR( int valueR )
{
	motor[ FRWheel ] = valueR;
	motor[ BRWheel ] = valueR;
}

void
setMotorArms( int power )
{
	motor[ lift ] = power;
}


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
		setMotorL(power);
		setMotorR(power);
		delay(time);
		power = 0; //what happens when i ommit this portion?
		setMotorR(power);
		setMotorL(power);
		//no delay( )?

}

//stops everything
void
stopAll()
{
	move(1000, 0);
	//add any other motors that need killing �??��??��??��??��??�
}


//tasks
task test()
{
		displayNextLCDString("Main task running");
		//move(1000, 100);
		liftTester(127);
		//userControl();
		//test return false;
}

void pre_auton()
{
	//AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

task autonomous()
{
	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}


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
			motor[ lift ] = (vexRT[ Btn6U ] - vexRT[ Btn5U ]) * -127;
		}
		else motor[ lift ] = 0; //is this necessary?


		//killswitch
		if(vexRT[ Btn8D ] == 1)
		{
			stopAll();
		}
  }
}
