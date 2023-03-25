/*
 \file		robot.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
 */

#include <ev3.h>

const int DISTANCE_TO_STOP = 150;
const int DRIVE_SPEED = 15;
const int DRIVE_STOP = 0;
const int KICK_ROTATION_SPEED = 50;
const int WHITE = 6;
const int RED = 5;
const int KICK_SPEED = 100;
const int ANGLE_360 = 360;

void init();
int countBalls();
int driveForward();
void kickRoutine(int);
int driveBackward();
void exitRobo();
void kickWithMotor();
int isPrimeNumber(int);

int main(void) {
	// all initial values
	init();
	int balls = countBalls();
	TermPrintf("Count: %d \n", balls);
	int isPrime = isPrimeNumber(balls);
	TermPrintf("IsPrime: %d \n", isPrime);
	kickRoutine(isPrime);

	return 0;
}

void init() {
	ResetRotationCount(OUT_A);
	setAllSensorMode(US_DIST_MM, NO_SEN, NO_SEN, COL_COLOR);
}

int countBalls() {
	int ballCount = 0;
	int finished = 1;
	while (finished == 1) {
		exitRobo();
		finished = driveForward();
		if (readSensor(IN_4) == WHITE || readSensor(IN_4) == RED) {
			ballCount++;
			TermPrintf("Count: %d \n", ballCount);
			Wait(2000);
		}
	}
	return ballCount;
}

int driveForward() {
	int distance = readSensor(IN_1);
	if (distance > DISTANCE_TO_STOP) {
		OnFwdSync(OUT_AD, DRIVE_SPEED);
		return 1;
	} else {
		Off(OUT_AD);
		return 0;
	}
}

void kickRoutine(int isPrime) {
	int stop = 0;
	int ballsToKick;
	if (isPrime == 0) {
		ballsToKick = 1;
	} else {
		ballsToKick = 2;
	}
	while (stop == 0) {
		exitRobo();
		stop = driveBackward();
		if ((readSensor(IN_4) == WHITE || readSensor(IN_4) == RED) && ballsToKick > 0) {
			Off(OUT_AD);
			kickWithMotor();
			ballsToKick--;
		}
	}

}

int driveBackward() {
	int currentDistance = MotorRotationCount(OUT_A);
	TermPrintf("Current Distance: %d \n", currentDistance);
	if (currentDistance > 0) {
		OnRevSync(OUT_AD, DRIVE_SPEED);
		return 0;
	} else {
		Off(OUT_AD);
		return 1;
	}
}

void exitRobo() {
	if (ButtonIsDown(BUTTON_ID_ENTER)) {
		FreeEV3();
	}
}

void kickWithMotor() {
	RotateMotor(OUT_C, KICK_SPEED, ANGLE_360);
}

int isPrimeNumber(int balls) {
	int i;
	int prime = 1;
	if (balls < 2) {
		prime = 0;
	} else {
		for (i = 2; i < balls; i++) {
			if (balls % i == 0) {
				prime = 0;
				break;
			}
		}
	}
	return prime;
}

