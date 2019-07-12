	#pragma config(Sensor, in5,    C_POT,          sensorPotentiometer)
#pragma config(Sensor, in4,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl7,  LIFTE,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RIGHT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LEFT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Motor,  port1,           MOBILE_GOAL_INTAKE, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           Chainbar,      tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           RIGHT_DRIVE_F, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           RIGHT_DRIVE_B, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           RIGHT_LIFT_BOTTOM, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port2,           LEFT_LIFT_BOTTOM, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           LEFT_DRIVE_B,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           LEFT_DRIVE_F,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           LIFT,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          ROLLERS,       tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "Subsystems/chainBar.c"
//#include "control_functions.c"

void _chassis(int leftDrive, int rightDrive){
	if(vexRT[Btn6U] == true){
		motor[RIGHT_DRIVE_B] = -leftDrive;
		motor[RIGHT_DRIVE_F] = -leftDrive;
		motor[LEFT_DRIVE_F] = -rightDrive;
		motor[LEFT_DRIVE_B] = -rightDrive;
		}else if(vexRT[Btn6D] == true){
		motor[RIGHT_DRIVE_F] = 25;
		motor[RIGHT_DRIVE_B] = -25;
		motor[LEFT_DRIVE_F] = 25;
		motor[LEFT_DRIVE_B] = -25;
		}else{
		motor[RIGHT_DRIVE_B] = rightDrive;
		motor[RIGHT_DRIVE_F] = rightDrive;
		motor[LEFT_DRIVE_F] = leftDrive;
		motor[LEFT_DRIVE_B] = leftDrive;
	}
}
void _chainbar(int speed){
	motor[Chainbar] = speed;
}
void _mobileGoal(int speed){
	motor[MOBILE_GOAL_INTAKE] = speed;
}
void _lift(int speed){
	motor[LEFT_LIFT_BOTTOM] = -speed;
	motor[RIGHT_LIFT_BOTTOM] = -speed;
	motor[LIFT] = -speed;
}
void _intake(int speed){
	motor[ROLLERS] = -speed;
}
bool up = false;

task lcd_(){
		bLCDBacklight = true;
	string mainBattery;
	displayLCDCenteredString(0,"Welcome 356B");
	wait1Msec(1000);}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
 motor[LEFT_DRIVE_B] = 127;
 motor[LEFT_DRIVE_F] = 127;
 motor[RIGHT_DRIVE_B] = 127;
 motor[RIGHT_DRIVE_F] = 127;
 wait10Msec(999999999);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
 	//startTask(chainBar_PID);
	//int chainBar_lastPoint;

	/*bLCDBacklight = true;
	string mainBattery;
	displayLCDCenteredString(0,"Welcome 356B");
	wait1Msec(1000);*/

  while (true)


{
int leftPower = -vexRT(Ch3);
		int rightPower = -vexRT(Ch2);

		_chassis(leftPower, rightPower);

		if(vexRT[Btn5DXmtr2] == 1){
			_chainbar(120);
			}else if(vexRT[Btn5UXmtr2] == 1){
			//while(SensorValue[ultra] < 1){
			_chainbar(-120);
			//}
			//_chainbar(-50);
			}else{
			_chainbar(-15);
		}

		if(vexRT[Btn7UXmtr2] == 1){
			_mobileGoal(127);
			}else if(vexRT[Btn7DXmtr2] == 1){
			_mobileGoal(-127);
			}else{
			_mobileGoal(0);
		}

		if(vexRT[Btn6UXmtr2] == 1){
			_lift(-127);
			up = true;
			}else if(vexRT[Btn6DXmtr2] == 1){
			_lift(127);
			//up = false;
			//}else{
			//if(up == false)
			//	_lift(15);
		}
		else {
			_lift(0);
		}

		if(vexRT[Btn8UXmtr2] == 1){
			_intake(127);
			}else if(vexRT[Btn8DXmtr2] == 1){
			_intake(-127);
			}else{
			_intake(40);
		}
}

  }
