#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           FLWheel,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           FRWheel,       tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           BLWheel,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           BRWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

#define LOOP_SPEED              25
#define MAX_POWER              127
#define MIN_POWER             -127

// final motor drive
long            motor_driveR;            ///< final motor control value RIGHT
long            motor_driveL;            /// LEFT

void
MotorSetL( int valueR )
{
	motor[ FLWheel ] = motor_driveL;
	motor[ BLWheel ] = motor_driveL;
}

void
MotorSetR( int valueR )
{
	motor[ FRWheel ] = motor_driveR;
	motor[ BRWheel ] = motor_driveR;
}

void
MotorSetArms( int valueR )
{
	motor[ Motor_FWR ] = valueR;
}

task main()
{
	while(true)
	{
		displayNextLCDString("Main task running");
		//motor[FLWheel] = 100;
		//motor[FRWheel] = 100;
		//motor[BLWheel] = 100;
		//motor[BRWheel] = 100;
		motor[lift] = 127;
		delay(150);
		motor[lift] = 0;
		delay(300);
		motor[lift] = -100;
		delay(100);
		break;
	}
}


//test
