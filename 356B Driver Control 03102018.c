#pragma config(Motor,  port3,           RF,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           RR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           LF,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           LR,            tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//void for right drive
void driver(int speed)
{
	motor[RF] = speed;
	motor[RR] = speed;
}

//void for left drive
void drivel(int speed)
{
	motor[LF] = speed;
	motor[LR] = speed;
}


task main()
{
	while(true)
{
	//driver cotrol
	//DRIVER CONTROL FOR CHASSIS
	motor[RF] = vexRT[Ch2];
	motor[RR] = vexRT[Ch2];
	motor[LF] = vexRT[Ch3];
	motor[LR] = vexRT[Ch3];

}
}