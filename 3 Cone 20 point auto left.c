#pragma config(Sensor, in4,    gyro,           sensorGyro)
#pragma config(Sensor, in5,    C_POT,          sensorPotentiometer)
#pragma config(Sensor, dgtl7,  LIFTE,          sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  LEFT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Sensor, dgtl11, RIGHT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Motor,  port1,           MOBILE_GOAL_INTAKE, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LEFT_LIFT_BOTTOM, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           Chainbar,      tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           LEFT_DRIVE_F,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           RIGHT_DRIVE_B, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           RIGHT_DRIVE_F, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           LEFT_DRIVE_B,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           RIGHT_LIFT_BOTTOM, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           LIFT,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          ROLLERS,       tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "driveTask.c"
#include "liftTask.c"
bool begin = false;
task start_(){
	_mogo(127);
	lift_Up(15, 127);
}
task intake_drop(){
	lift_Down(1190, 127);
	//chainbar_down(80);
	_mogo(2250, -127);
	_intake(-127);
}


task main(){

//clear sensors
	_liftClr();
	_driveClr();
	//start
	//Program\\
	//Lift up Mogo and put preloaded cone down on Mogo
	//Raise Lift up and put mogo down
	startTask(start_);
	wait1Msec(500);
	_intake(80);
	//Go forward to mogo
	_driveForward(1300, 127);
	//Lift Mogo
	_mogo(1500, -127);
	//Lift down
	lift_down(5, 127);
	//Drop Cone
	_intake(-127);



	//Pick Up next cone and drop it on Mogo
	//_intake(127);\\
	//Calculate Gyro
	cal_gyro();
	//wait1Msec(400);
	//Clear Drive Value
	_driveClr();
	//Drive Forward to next cone
	_driveForward(90, 127);
	//Put Chainbar Down
	chainbar_down(127);
	//Intake the cone
	_intake(127);
	//_mogo(900, -127);
	//_mogo(-127);
	//lift_Down(65, 100);
	//Lift up Lift
	lift_Up(30, 127);

	//Drop the Second Cone
	//Chainbar Up
	chainbar_up(100, 127);
	//Put lift DOWN
	lift_Down(4, 127);
	//Reverse Intake to drop cone
	_intake(-127);
	//wait1Msec(100);
  lift_Up(15, 127);
  chainbar_down(127);
  _intake(127);
	//_intake(127);
	//chainbar_down(127);


	_driveClr();
	_driveForward(70, 127);
	lift_Down(6, 127);
	_lift(-50);
	wait1Msec(100);

	lift_Up(40, 127);
	chainbar_up(100, 127);
	lift_Down(7, 127);
	_intake(-127);
	wait1Msec(100);

	lift_Up(40, 127);
	_driveBack(-1000, 127);
	turn(1500, -127);
	//wait1Msec(100);
	_driveClr();
	_driveForward(225, 127);
	//wait1Msec(100);

	turn(500, 127);
	_driveClr();
	_driveForward(600, 127);
	wait1Msec(100);
	_mogo(1500, 127);
	_driveBack(-50, 127);
	_mogo(0, -120);
}
