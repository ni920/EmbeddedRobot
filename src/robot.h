/*
 * roboter.h
 *
 *  Created on: 28.03.2023
 *      Author: nicosaia
 */

#ifndef ROBOT_H_
#define ROBOT_H_
typedef signed int int32_t;

static const int32_t DRIVE_SPEED = 15;
static const int32_t DRIVE_STOP = 0;
static const int32_t KICK_ROTATION_SPEED = 50;
static const int32_t WHITE = 6;
static const int32_t RED = 5;

static void init(void);
static int32_t countBalls(void);
static int32_t driveForward(void);
static void kickRoutine(int32_t isPrime);
static int32_t driveBackward(void);
static void exitRobo(void);
static void kickWithMotor(void);
static int32_t isPrimeNumber(int32_t balls);
static void playWinnerSound(void);

#endif /* ROBOT_H_ */
