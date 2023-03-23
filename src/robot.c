/*
 \file		robot.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
 */

#include <ev3.h>


const int DISTANCE_TO_STOP = 100;
const int DRIVE_SPEED = 10;
const int DRIVE_STOP = 0;
const int KICK_ROTATION_SPEED = 50;
const int WHITE = 6;
const int RED = 5;
const int KICK_SPEED = 100;
const int ANGLE_360 = 360;

int driveForward();
void exitRobo();
void init();
void kick(int);
void kickWithMotor();

int main(void) {
	// all initial values
	init();

	while (true) {
		exitRobo();
		if (readSensor(IN_4) == WHITE || readSensor(IN_4) == RED ) {
			Off(OUT_AD);
			kickWithMotor();
		}else {
			driveForward();
		}

	}

	return 0;
}

void init() {
	setAllSensorMode(US_DIST_MM, NO_SEN, NO_SEN, COL_COLOR);
}

int driveForward() {
	int distance = readSensor(IN_1);
	TermPrintf("Distance: %d \n", distance);
	if (distance > DISTANCE_TO_STOP) {
		OnFwdSync(OUT_AD, DRIVE_SPEED);
		return 1;
	} else {
		Off(OUT_AD);
		return 0;
	}
}

void exitRobo() {
	if (ButtonIsDown(BUTTON_ID_ENTER)) {
		FreeEV3();
	}
}

void kick(int state) {
	if (state == 0) {
		RotateMotor(OUT_A, KICK_ROTATION_SPEED, 360);
		RotateMotor(OUT_A, KICK_ROTATION_SPEED, -360);
	}
}

void kickWithMotor() {
	RotateMotor(OUT_C, KICK_SPEED, ANGLE_360);
}


