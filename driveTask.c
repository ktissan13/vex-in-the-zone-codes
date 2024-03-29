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

#include "pid_h.h"
#include "simpleSensors.h"



void _mogo(int time, int speed){
	motor[MOBILE_GOAL_INTAKE] = speed;
	wait1Msec(time);
	motor[MOBILE_GOAL_INTAKE] = 0;
}
void _chassis(int left_speed, int right_speed){
	motor[RIGHT_DRIVE_F] = right_speed;
	motor[RIGHT_DRIVE_B] = right_speed;
	motor[LEFT_DRIVE_F] = left_speed;
	motor[LEFT_DRIVE_B] = left_speed;
}

void stop_chassis(){
	motor[RIGHT_DRIVE_F] = 25;
	motor[RIGHT_DRIVE_B] = -25;
	motor[LEFT_DRIVE_F] = 0;
	motor[LEFT_DRIVE_B] = -25;
}

pid drivebase;
void drivebase_PID_init(){
	drivebase.kP = 0.0;
	drivebase.kI = 0.0;
	drivebase.kD = 0.0;
}
int drive_PID(int distance, int maxSpeed){
	drivebase_PID_init();
	drivebase.error = distance - LD_ENC;
	drivebase.derivative = drivebase.error - drivebase.last_error;
	drivebase.last_error = drivebase.error;

	if(abs(drivebase.error) < 50){
		drivebase.integral += drivebase.error;
	}else{
		drivebase.integral = 0;
	}

	int power = (drivebase.error*drivebase.kP) + (drivebase.integral*drivebase.kI) + (drivebase.derivative*drivebase.kD);
	if(power > maxSpeed){
		power = maxSpeed;
	}
	return(power);
}

void _driveForward(int distance, int speed){
	speed*=-1;
	int D_error = distance - LD_ENC;
	while(D_error > 0){
		_chassis(speed, speed);
		D_error = distance - LD_ENC;
	}
	_chassis(25,25);
	wait1Msec(100);
	_chassis(0,0);
}

void _driveForwardM(int distance, int speed, int mogo){
	speed*=-1;
	int D_error = distance - LD_ENC;
	while(D_error > 0){
		_chassis(speed, speed);
		D_error = distance - LD_ENC;
		motor[MOBILE_GOAL_INTAKE] = mogo;
	}
	_chassis(25,25);
	wait1Msec(100);
	_chassis(0,0);
}

void _driveBack(int distance, int speed){
	int D_error = distance - LD_ENC;
	while(D_error < 0){
		_chassis(speed, speed);
		D_error = distance - LD_ENC;
	}
	_chassis(-25,-25);
	wait1Msec(100);
	_chassis(0,0);
}

void _driveClr(){
	LD_ENC = 0;
	RD_ENC = 0;
}

void turn(int time, int speed){
	motor[RIGHT_DRIVE_B] = speed;
	motor[RIGHT_DRIVE_F] = speed;
	motor[LEFT_DRIVE_B] = -speed;
	motor[LEFT_DRIVE_F] = -speed;
	wait1Msec(time);
}
 /* while((D_gyro) < degrees10 - 100){
    _chassis(speed, -speed);
  }
  stop_chassis();
	wait1Msec(100);
	_chassis(0,0);
}*/

void turn_other(int degrees10, int speed){
  while((D_gyro) > degrees10 - 100){
    _chassis(-speed, speed);
  }
  stop_chassis();
	wait1Msec(100);
	_chassis(0,0);
}

void cal_gyro(){
	D_gyro = sensorNone;
  wait1Msec(200);
  D_gyro = sensorGyro;
  wait1Msec(100);
}

void _mogo(int speed){
	motor[MOBILE_GOAL_INTAKE] = speed;
}
