#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  frontRight,     sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  frontLeft,      sensorNone)
#pragma config(Motor,  port2,           RDriveBase,    tmotorVex393HighSpeed_MC29, openLoop, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port3,           LDriveBase,    tmotorVex393HighSpeed_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port4,           leftLift,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           topRightLift,  tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           bottomRightLift, tmotorVex393_MC29, openLoop, reversed, driveRight)
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
#define PID_SENSOR_INDEX    myEncoder
#define PID_SENSOR_SCALE    1

#define PID_MOTOR_INDEX     myMotor
#define PID_MOTOR_SCALE     -1

#define PID_INTEGRAL_LIMIT  50

float  pid_Kp = 2.0;
float  pid_Ki = 0.04;
float  pid_Kd = 0.0;

static int   pidRunning = 1;
static float pidRequestedValue;

// final motor drive
long            motor_driveR;            ///< final motor control value RIGHT
long            motor_driveL;            /// LEFT

/*///////////////////////////////////////////////////////////
/////                      __ ___  ____                 /////
/////                     / /|__ \|  _ \                /////
/////                    / /_   ) | |_) |               /////
/////                   | '_ \ / /|  _ <                /////
/////                   | (_) / /_| |_) |               /////
/////                    \___/____|____/                /////
///// Team 62K Robot                                    /////
///// Main Code                                         /////
///// Authors: Abner Benitez                            /////
///// Since: Oct. 30, 2016                              /////
*////////////////////////////////////////////////////////////

/*
To Do List
1. Try an empty main()
2. what does it mean to have greater resolution in sensors?
3. startTask( ); gotta use this within tasks
4. nMotorEncoder[motor�??s name]
5. Check motor and sensors setup
*/

//setters
void
setMotorL( int valueL )
{
  motor[ LDriveBase ] = -valueL; //negative to make robot drive "forward"
}

void
setMotorR( int valueR )
{
  motor[ RDriveBase ] = -valueR; //negative to make robot drive "forward"
}

void
setArms( int power )
{
  motor[ leftLift ] = power;
  motor[ topRightLift ] = power;
  motor[ bottomRightLift ] = power;
}

//action methods
void
liftTester(int power)
{
  setArms(power);
  delay(150);
  setArms(power);
  delay(300);
  setArms(-power);
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
  setArms(0);
  //add any other motors that need killing �??�
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*  pid control task                                                           */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
task pidController()
{
	/*
    float  pidSensorCurrentValue;

    float  pidError;
    float  pidLastError;
    float  pidIntegral;
    float  pidDerivative;
    float  pidDrive;

    // If we are using an encoder then clear it
    if( SensorType[ PID_SENSOR_INDEX ] == sensorQuadEncoder )
        SensorValue[ PID_SENSOR_INDEX ] = 0;

    // Init the variables - thanks Glenn :)
    pidLastError  = 0;
    pidIntegral   = 0;

    while( true )
        {
        // Is PID control active ?
        if( pidRunning )
            {
            // Read the sensor value and scale
            pidSensorCurrentValue = SensorValue[ PID_SENSOR_INDEX ] * PID_SENSOR_SCALE;

            // calculate error
            pidError = pidSensorCurrentValue - pidRequestedValue;

            // integral - if Ki is not 0
            if( pid_Ki != 0 )
                {
                // If we are inside controlable window then integrate the error
                if( abs(pidError) < PID_INTEGRAL_LIMIT )
                    pidIntegral = pidIntegral + pidError;
                else
                    pidIntegral = 0;
                }
            else
                pidIntegral = 0;

            // calculate the derivative
            pidDerivative = pidError - pidLastError;
            pidLastError  = pidError;

            // calculate drive
            pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

            // limit drive
            if( pidDrive > PID_DRIVE_MAX )
                pidDrive = PID_DRIVE_MAX;
            if( pidDrive < PID_DRIVE_MIN )
                pidDrive = PID_DRIVE_MIN;

            // send to motor
            motor[ PID_MOTOR_INDEX ] = pidDrive * PID_MOTOR_SCALE;
            }
        else
            {
            // clear all
            pidError      = 0;
            pidLastError  = 0;
            pidIntegral   = 0;
            pidDerivative = 0;
            motor[ PID_MOTOR_INDEX ] = 0;
            }

        // Run at 50Hz
        wait1Msec( 25 );
        }
        */
}


//tasks
#warning "test task"
task test()
{
  displayNextLCDString("Main task running");
  //move(1000, 100);
  liftTester(127);
  //userControl();
  //test return false;
}

#warning "autonomous task"
void pre_auton()
{
  //Pre-autonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

#warning "autonomous task"
task autonomous()
{
  //AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
	move(1000, MAX_POWER);
}


#warning "usercontrol task"
//try making this a tankDrive()
task usercontrol()
{
  //start PID control task here "startTask( )"
  while (true) //try using '1'
  {
    //left drive with deadbands
    setMotorL(abs(vexRT[ Ch3 ]) > 25 ? vexRT[ Ch3 ] : 0);

    //right drive with deadbands
    setMotorR(abs(vexRT[ Ch2 ]) > 25 ? vexRT[ Ch2 ] : 0);


    //operate the lift
    //switch "6D" to "6U"
    if(vexRT[ Btn5U ] || vexRT[ Btn6U ]) //test with == 1
    {
      setArms((vexRT[ Btn6U ] - vexRT[ Btn5U ]) * -127);
    }
    else setArms(0); //is this necessary?

    //killswitch
    if(vexRT[ Btn8D ] == 1)
    {
      stopAll();
    }

    wait1Msec(20); //don't hog the CPU :)
  }
}
