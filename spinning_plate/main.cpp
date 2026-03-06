#include <Arduino.h>
#include <Stepper.h>

#define STEPS_PER_REV 2048 // steps per full revolution (28BYJ-48)

Stepper stepper(STEPS_PER_REV, 8, 10, 9, 11); // IN1, IN3, IN2, IN4 pins

const int stepSize = STEPS_PER_REV; // one full revolution per loop
const int rpm = 10; // rotation speed in RPM

void setup() {
    stepper.setSpeed(rpm); // setting rotation speed
}

void loop() {
    stepper.step(stepSize); // rotate one full revolution
}
