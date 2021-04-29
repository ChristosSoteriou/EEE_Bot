#if !defined(MAIN_H)
#define MAIN_H

#include <Arduino.h>
#include <Wire.h>

#include "pid.h"
#include "drive.h"
#include "EEEBot.h"
#include "i2c_help.h"

#define I2C_ADDR 0x8

#define PUSH_BTN 10

// LEFT MOTOR
#define PWMA_RIGHT 7
#define PWMB_RIGHT 5

// RIGHT MOTOR
#define PWMA_LEFT 8
#define PWMB_LEFT 6

drive_s motors;

#define KP 7
#define KI 0
#define KD 2
PID_s pid;

#define ROBOT_TIMEOUT 1000
uint32_t i2cTimer = 0;
static float robotAngle = 0;

void i2c_recv(int recved);

#endif // MAIN_H
