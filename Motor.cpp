#include "Motor.h"
#include <Arduino.h>


void Motor::forward(int speed) {
    if (speed < 0 || speed > 255) {
        return;
    }
    analogWrite(in1, LOW);
    analogWrite(in2, translate(speed));
}

void Motor::backward(int speed) {
    if (speed < 0 || speed > 255) {
        return;
    }
    analogWrite(in2, LOW);
    analogWrite(in1, translate(speed));
}