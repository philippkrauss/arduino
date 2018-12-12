#ifndef MOTOR_H
#define MOTOR_H

class Motor {
public:
	Motor(int in1, int in2, int minimum) {
		this->in1 = in1;
		this->in2 = in2;
		a = ((double)(255 - minimum)) / (double)255;
		b = minimum;
	}
	void forward(int speed);
	void backward(int speed);
private:
	int translate(int speed) {
		if (speed == 0) {
			return 0;
		}
		return a * speed + b;
	}
	int in1;
	int in2;
	double a;
	int b;
};

#endif // MOTOR_H
