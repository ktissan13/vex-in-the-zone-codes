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



task main(){
	_intake(30);
	_liftClr();
	_driveClr();
	startTask(start_);
	chainbar_up(127);
	chainbar_up(127);
	_driveForward(380, 120);
	stop_chassis();
	_intake(-127);
	chainbar_up(127);
	_lift(-25);
	lift_Up(8, 80);
	_driveBack(320, 80);
	_mogo(120);
	//turnE(-100, 480);
	_mogo(70);
	_driveClr();
	_driveBack(-1900, 127);
	_mogo(0);
}
