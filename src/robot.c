/*
 \file		robot.c
 \author	${user}
 \date		${date}
 \brief
 */

#include <ev3.h>
#include "robot.h"


static int32_t numberOfBalls;

int32_t main(void) {
	// all initial values
	init();
	int32_t balls = countBalls();
	//TermPrintf("Count: %d \n", balls);
	int32_t isPrime = isPrimeNumber(balls);
	//TermPrintf("IsPrime: %d \n", isPrime);
	kickRoutine(isPrime);
	(void) playWinnerSound();

	return 0;
}


static void init(void) {
	(void)ResetRotationCount(OUT_A);
	int32_t catch = setAllSensorMode(US_DIST_MM, (NO_SEN), (NO_SEN), COL_COLOR);
}

static int32_t countBalls(void) {
	int32_t ballCount = 0;
	int32_t finished = 1;
	while ((finished == 1) && (ballCount < (int32_t)sizeof(int32_t)))  {
		exitRobo();
		finished = driveForward();
		if ((readSensor(IN_4) == WHITE) || (readSensor(IN_4) == RED)) {
			ballCount++;
			//TermPrintf("Count: %d \n", ballCount);
			(void) Wait(2000);
		}
	}
	numberOfBalls = ballCount;
	return ballCount;
}

static int32_t driveForward(void) {
	const int32_t DISTANCE_TO_STOP = 150;
	int32_t distance = readSensor(IN_1);
	int32_t returnValue;
	if (distance > DISTANCE_TO_STOP) {
		(void) OnFwdSync(OUT_AD, DRIVE_SPEED);
		returnValue = 1;
	} else {
		(void) Off(OUT_AD);
		returnValue = 0;
	}
	return returnValue;
}

static void kickRoutine(int32_t isPrime) {
	int32_t stop = 0;
	int32_t ballsToKick;
	if (isPrime == 0) {
		ballsToKick = 1;
	} else {
		ballsToKick = 2;
	}
	while (stop == 0) {
		exitRobo();
		stop = driveBackward();
		if (((readSensor(IN_4) == WHITE) || (readSensor(IN_4) == RED)) && (ballsToKick > 0)) {
			(void) Off(OUT_AD);
			(void) kickWithMotor();
			ballsToKick--;
			numberOfBalls--;
		}
	}

}

static int32_t driveBackward(void) {
	int32_t currentDistance = MotorRotationCount(OUT_A);
	int32_t returnValue;
	//TermPrintf("Current Distance: %d \n", currentDistance);
	if (currentDistance > 0) {
		(void) OnRevSync(OUT_AD, DRIVE_SPEED);
		returnValue = 0;
	} else {
		(void) Off(OUT_AD);
		returnValue = 1;
	}
	return returnValue;
}

static void exitRobo(void) {
    static _Bool ev3_is_free = (_Bool) false;
    if (ButtonIsDown(BUTTON_ID_ENTER) && !ev3_is_free) {
    	(void) FreeEV3();
        ev3_is_free = (_Bool) true;
    }
}


static void kickWithMotor(void) {
	const int8_t KICK_SPEED = 100;
	const int32_t ANGLE_360 = 360;
	(void) RotateMotorEx((0x04), KICK_SPEED, ANGLE_360, 0, (bool) 1, (bool) 1);
}

static int32_t isPrimeNumber(int32_t balls) {
	int32_t i;
	int32_t prime = 1;
	if (balls < 2) {
		prime = 0;
	} else {
		for (i = 2; i < balls; i++) {
			if ((balls % i) == 0) {
				prime = 0;
				break;
			}
		}
	}
	return prime;
}

static void playWinnerSound(void) {
	if (numberOfBalls <= 0) {
		Tone a[4]={
				{TONE_C2, NOTE_QUARTER},
				{TONE_E2, NOTE_QUARTER},
				{TONE_G2, NOTE_QUARTER},
				{TONE_C3, NOTE_HALF}
			};
			(void) PlayTones(a);
	}
}
