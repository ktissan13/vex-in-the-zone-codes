#pragma config(Sensor, in5,    C_POT,          sensorPotentiometer)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl7,  LIFTE,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  LEFT_DRIVE_ENC, sensorQuadEncoder)
#pragma config(Sensor, dgtl11, RIGHT_DRIVE_ENC, sensorQuadEncoder)
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
void rightD(int speed){
	motor[RIGHT_DRIVE_B] = speed;
	motor[RIGHT_DRIVE_F] = speed;
}
void leftD(int speed){
	motor[LEFT_DRIVE_B] = speed;
	motor[LEFT_DRIVE_F] = speed;
}
void turnE(int speed, int val){
	while((abs(SensorValue[LEFT_DRIVE_ENC])) < val){
		rightD(-speed);
		leftD(speed);
	}
}
void move(int speed, int mogo, int val){
	while((abs(SensorValue[LEFT_DRIVE_ENC])) < val){
		rightD(speed);
		leftD(speed);
		motor[port1] = mogo;
	}
}

void zero(){
	SensorValue[LEFT_DRIVE_ENC] = 0;
	SensorValue[RIGHT_DRIVE_ENC] = 0;
	wait1Msec(50);
}

task main(){
	_liftClr();
	_driveClr();
	//start
	//Program\\
	//Raise Lift up and put mogo down
	startTask(start_);
	wait1Msec(500);
	//wait 1 second
	//wait1Msec(750);
	//Roller Intake run
	_intake(80);
	//Go forward to mogo
	_driveForwardM(1400, 100, 100);
	//Lift Mogo
	_mogo(1200, -127);
	//startTask(intake_drop);
	lift_down(5, 70);
	//wait1Msec(100);

	_intake(-127);
	wait1Msec(250);
	_intake(127);


	cal_gyro();
	wait1Msec(400);
	_driveClr();
	_driveForward(50, 127);
	//_mogo(1500, -127);
	chainbar_down(127);
	wait1Msec(200);
	//_mogo(900, -127);
	//_mogo(-127);
	//lift_Down(65, 100);
	lift_Up(10, 127);
	chainbar_down(-127);
	lift_Down(4, 127);
	_intake(-127);
	wait1Msec(250);

	lift_Up(15, 127);
	_intake(127);
	chainbar_down(127);
	wait1Msec(500);
	_driveClr();
	_driveForward(40, 127);
	lift_Down(2, 127);
	_lift(-50);
	chainbar_down(127);
	_intake(-127);
	wait1Msec(250);

	//lift_Up(15, 127);
	//_intake(127);
	//chainbar_down(127);
	//_driveClr();
	//_driveForward(40, 127);
	//lift_Down(2, 127);
	//_lift(-50);
	//chainbar_down(127);
	//_intake(-127);
	//wait1Msec(250);

	lift_Up(25, 127);
	_driveBack(-15, 127);
	wait1Msec(250);
	_driveClr();
	zero();
	turnE(100, 250);
	_driveClr();
	_driveForward(100, 127);
	wait1Msec(100);
	_driveClr();
	zero();
	turnE(100, 500);
	wait1Msec(100);
	//_driveClr();
	//_driveForward(-220, 127);
	//wait1Msec(100)

	//turn(-600, 127);
	_driveClr();
	_driveForward(400, 127);
	_mogo(1500, 127);
	wait1Msec(100);
	_driveBack(-50, 127);
	_mogo(0, -127);
}
