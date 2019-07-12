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

#include "driveTask.c"
#include "liftTask.c"
bool begin = false;

task main()
{
	_liftClr();
	_driveClr();
	_driveForward(500, 100);
	lift_Up(10, 127);
	chainbar_down(127);



}
