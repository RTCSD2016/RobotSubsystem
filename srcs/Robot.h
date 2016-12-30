#ifndef ROBOT_H
#define ROBOT_H

#include "Axis.h"

class Robot{
private:
	Axis Axis_X;
	Axis Axis_Y;
	double Radius;
	double Weight;

public:
	Robot();
	Robot( Axis, Axis, double ,double );
	~Robot(){};
	void Display();
};


#endif
