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
double Kp=20, Ki=30, Kd=.55;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
    Serial.begin(9600);
	Wire.begin();
    mpu6050.begin();
    mpu6050.setGyroOffsets(0.6, 1.52, -0.14);

    Setpoint = -1.5;
    myPID.SetOutputLimits(-255, 255);
    //turn the PID on
    myPID.SetMode(AUTOMATIC);
}

void loop() {
    //*
    mpu6050.update();
    float angle = mpu6050.getAngleX();
    
    if (angle < -45 || angle > 45) {
        leftMotor.forward(0);
        rightMotor.forward(0);
        return;
    }
    Input = angle;
    myPID.Compute();
    Serial.print((double)angle);
    Serial.print(",");
    Serial.println(Output);

    if (Output > 0) {
        leftMotor.forward(Output);
        rightMotor.forward(Output);
    } else {
        leftMotor.backward(Output * -1);
        rightMotor.backward(Output * -1);
    }
    /**/
}
