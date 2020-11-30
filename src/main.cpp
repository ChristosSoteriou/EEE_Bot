#include <Arduino.h>
#include "motor_drive.h"
#include "imu.h"
#include "distance.h"
#include "bumpers.h"
#include "line_sensor.h"

#define BTN 13

void setup() {
  Serial.begin(115200);

  pinMode(BTN, INPUT_PULLUP);

  imu_setup();
  motors_setup();
  distance_setup();
  bumpers_setup();

  motor_drive(255, 255);
}

void loop() {
  imu_update();
  line_update();

  if (line_values[0] == LINE_BLACK && line_values[1] != LINE_BLACK) { // Turn Right
    motor_drive(255, 50);
  } else if (line_values[0] != LINE_BLACK && line_values[1] == LINE_BLACK) { // Turn Left
    motor_drive(50, 255);
  } else if (line_values[0] == LINE_BLACK && line_values[1] == LINE_BLACK) { // Steight
    motor_drive(255, 255);
  }
}

