#pragma config(Sensor, dgtl1,  EncoderL,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  EncoderR,       sensorQuadEncoder)
#pragma config(Motor,  port1,           Claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           RF,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RB,            tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, dgtl3)
#pragma config(Motor,  port4,           Arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           MLift2,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           MLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LF,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LB,            tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, dgtl1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//motor speed for mobile lift
int Lift = 120;
//motor speed for motor lift
int speed = 120;
//motor speed for claw
int claw = 100;
//motor speed for arm claw
int arm = 120;

bool first = true;
void writeInt(int value) {

	if(first) {
		writeDebugStream("%d", value);  // writes value without comma
		first = false;
		return;
	} else {
		writeDebugStream(", %d", value);  // writes value with comma
	}

}

void stp (int time){

	motor[Arm] = 0;
	motor[Claw] = 0;
	motor[LB] = 0;
	motor[LF] = 0;
	motor[MLift2] = 0;
	motor[RB] = 0;
	motor[RF] = 0;
	wait1Msec(time);
}

int offset=3;
float diameter=5.0;
int en_val=0;

//Drive straight, backwards or forwards
//*************************************
void drive_back_for(float distance, int speed_motor){
	float circumference=0.0;
	float rotations_shaft=0.0;
	circumference=PI*diameter;
	rotations_shaft=distance/circumference;
	en_val=360*(int)rotations_shaft;

	while((abs(SensorValue[EncoderL])<=en_val) && (abs(SensorValue[EncoderR])<=en_val)){

		if(SensorValue[EncoderL]<SensorValue[EncoderR]){
			motor[RF]=speed_motor-offset;
			motor[RB]=speed_motor-offset;
			motor[LF]=speed_motor;
			motor[LB]=speed_motor;
		}

		else if(SensorValue[EncoderL]>SensorValue[EncoderR]){
			motor[RF]=speed_motor;
			motor[RB]=speed_motor;
			motor[LF]=speed_motor-offset;
			motor[LB]=speed_motor-offset;
		}

		else {
			motor[RF]=speed_motor;
			motor[RB]=speed_motor;
			motor[LF]=speed_motor;
			motor[LB]=speed_motor;
		}

	}
	SensorValue[EncoderL]=0;
	SensorValue[EncoderR]=0;
}

//Function for the mobile lift
//****************************
void mobile_lift(int speed_lift, int wait_milli){
	motor[MLift]=speed_lift;
	motor[MLift2]=speed_lift;
	wait1Msec(wait_milli);
}

void botarm(int speed, int time){
	motor[Arm]=speed;
	wait1Msec(time);
}

void stop_all(int wait_all){
	motor[RB]			=	0;
	motor[RF]  		=	0;
	motor[LB]			=	0;
	motor[LB]			=	0;
	motor[MLift]	=	0;
	motor[MLift2]	=	0;
	motor[Arm]		=	0;
	wait1Msec(wait_all);
}

task main()
{
	{
		int foo;
		clearDebugStream();
		ClearTimer(T1);

{
		{
			writeDebugStream("int x is: %d", x);  // writes the current value of int 'x' to the debug stream
		}


		{
			SensorValue[EncoderL]=0;
			SensorValue[EncoderR]=0;
			stop_all(100);

			// Arm Backwards
			botarm(120,800);

			// Mobile Lift down
			//(lift_speed, amount of time)
			mobile_lift(-127,820);
			stop_all(100);

			motor[RB]=-127;
			motor[RF]=-127;
			motor[LB]=-127;
			motor[LF]=-127;
			wait1Msec(2000);
			stop_all(500);

		}
	}}

}