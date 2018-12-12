#include "Motor.h"
#include "MPU6050_tockn.h"
#include <Wire.h>
#include <PID_v1.h>

// left Motor pins
int left1 = 6;
int left2 = 5;

// right Motor pins
int right1 = 10;
int right2 = 11;

MPU6050 mpu6050(Wire);

Motor leftMotor(left1, left2, 60);
Motor rightMotor(right1, right2, 60);

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=56, Ki=0, Kd=.3;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
    Serial.begin(9600);
	Wire.begin();
    mpu6050.begin();
    mpu6050.setGyroOffsets(0.6, 1.52, -0.14);

    Setpoint = 0;
    //turn the PID on
    myPID.SetMode(AUTOMATIC);
}

void loop() {
    //*
    mpu6050.update();
    int angle = mpu6050.getAngleX();
    int absoluteAngle = angle;
    if (angle > 0) {
        absoluteAngle = angle * -1;
    }
    if (absoluteAngle < -35) {
        leftMotor.forward(0);
        rightMotor.forward(0);
        return;
    }
    Input = absoluteAngle;
    myPID.Compute();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(Output);

    if (angle < 0) {
        leftMotor.forward(Output);
        rightMotor.forward(Output);
    } else {
        leftMotor.backward(Output);
        rightMotor.backward(Output);
    }
    /**/
}
