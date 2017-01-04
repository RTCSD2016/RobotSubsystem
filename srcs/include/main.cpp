
#include<iostream>
#include"RobotSystem.h"
#include"RobotCommand.h"
#include"TrajectoryPlanning.h"



using namespace IceHockeyGame;
using namespace RobotSubSystem;
using namespace Robot;



void main(void)
{
	TrajectoryPlan RobotHand(0, 0, 0, 0, true, false);
	RobotHand.InitTrajectoryPlan(300, 400, 900, 1200, 500);
	RobotHand.Planning();
	RobotHand.LinearInterpolation();
	
}