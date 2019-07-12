#pragma config(Sensor, in5,    C_POT,          sensorPotentiometer)
#pragma config(Sensor, in4,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl7,  LIFT,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RIGHT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LEFT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Motor,  port1,           MOBILE_GOAL_INTAKE, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Chainbar,      tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           RIGHT_DRIVE_F, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           RIGHT_DRIVE_B, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           RIGHT_LIFT_BOTTOM, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LEFT_LIFT_BOTTOM, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           RIGHT_LIFT_TOP,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           LEFT_LIFT_TOP,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           LEFT_DRIVE,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          ROLLERS,       tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "driveTask.c"
#include "liftTask.c"

task start_(){
	lift_Up(24, 100);
	chainbar_down(127);
}


task main(){
	_intake(30);
	_liftClr();
	_driveClr();
	startTask(start_);
	_driveForward(380, 120);
	stop_chassis();
	_intake(-127);
	chainbar_up(127);
	_lift(-25);
	_driveBack(320, 80);
	_mogo(120);
	turn(2020, 120);
	_mogo(70);
	_driveClr();
	_driveBack(-1900, 127);
	_mogo(0);
}