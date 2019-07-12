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


#include "driveTask.c"
#include "liftTask.c"

task start_(){
	lift_Up(30, 100);
	chainbar_down(127);
}
void leftD(int speed){
	motor[RIGHT_DRIVE_B] = speed;
	motor[RIGHT_DRIVE_F] = speed;
}
void rightD(int speed){
	motor[LEFT_DRIVE_B] = speed;
	motor[LEFT_DRIVE_F] = speed;
}
void turnE(int speed, int val){
	while((abs(SensorValue[RIGHT_DRIVE_ENC])) < abs(val)){
		leftD(speed);
		rightD(-speed);
	}
}



void _chassisd(int leftDrive, int rightDrive){
	if(vexRT[Btn6U] == true){
		motor[RIGHT_DRIVE_B] = -leftDrive;
		motor[RIGHT_DRIVE_F] = -leftDrive;
		motor[LEFT_DRIVE_F] = -rightDrive;
		motor[LEFT_DRIVE_B] = -rightDrive;
		}else if(vexRT[Btn6D] == true){
		motor[RIGHT_DRIVE_F] = -25;
		motor[RIGHT_DRIVE_B] = 25;
		motor[LEFT_DRIVE_F] = -25;
		motor[LEFT_DRIVE_B] = 25;
		}else{
		motor[RIGHT_DRIVE_B] = rightDrive;
		motor[RIGHT_DRIVE_F] = rightDrive;
		motor[LEFT_DRIVE_F] = leftDrive;
		motor[LEFT_DRIVE_B] = leftDrive;
	}
}
void _chainbard(int speed){
	motor[Chainbar] = speed;
}
void _mobileGoal(int speed){
	motor[MOBILE_GOAL_INTAKE] = speed;
}
void _liftd(int speed){
	motor[LEFT_LIFT_BOTTOM] = -speed;
	motor[RIGHT_LIFT_BOTTOM] = -speed;
	motor[LIFT] = -speed;
}
void _intaked(int speed){
	motor[ROLLERS] = -speed;
}


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
	_intake(30);
	_mogo(127);
	wait1Msec(500);
	_liftClr();
	_driveClr();
	startTask(start_);
	_driveForward(200, 80);
	stop_chassis();
	_intake(-127);
	chainbar_up(100, 127);
	_lift(-25);
	lift_Up(8, 80);
	_driveBack(320, 80);

	//turnE(-100, 480);

	_driveClr();
	_driveBack(-150, 127);

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

		_chassisd(leftPower, rightPower);

		if(vexRT[Btn5UXmtr2] == 1){
			_chainbard(120);
			}else if(vexRT[Btn5DXmtr2] == 1){
			//while(SensorValue[ultra] < 1){
			_chainbard(-120);
			//}
			//_chainbar(-50);
			}else{
			_chainbard(-15);
		}

		if(vexRT[Btn7UXmtr2] == 1){
			_mobileGoal(127);
			}else if(vexRT[Btn7DXmtr2] == 1){
			_mobileGoal(-127);
			}else{
			_mobileGoal(0);
		}

		if(vexRT[Btn6UXmtr2] == 1){
			_liftd(-127);
			//up = true;
			}else if(vexRT[Btn6DXmtr2] == 1){
			_liftd(127);
			//up = false;
			//}else{
			//if(up == false)
			//	_lift(15);
		}
		else {
			_liftd(0);
		}

		if(vexRT[Btn8UXmtr2] == 1){
			_intaked(127);
			}else if(vexRT[Btn8DXmtr2] == 1){
			_intaked(-127);
			}else{
			_intaked(40);
		}
}

  }