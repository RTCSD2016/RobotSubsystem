#include"stdafx.h"
#include "Robot.h"
#include <stdio.h>

Robot::Robot(){}

Robot::Robot(Axis axis_x , Axis axis_y , double r, double w)
{
	Axis_X = axis_x;
	Axis_Y = axis_y;
	Radius = r;
	Weight = w;
}

void Robot::Display()   
{
	printf("The location of the Robot Hand is ( %f  , %f )\n", Axis_X.Parameter.Position, Axis_Y.Parameter.Position);

}
