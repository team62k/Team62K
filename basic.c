#pragma config(Motor,  port1,           one,           tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// delay() wait
task main()
{
	motor[one] = 60;
	delay(3000);
	motor[one] = 0;
}
