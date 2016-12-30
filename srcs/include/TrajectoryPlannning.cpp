#include"RobotSystem.h"
#include"RobotCommand.h"
#include"TrajectoryPlanning.h"
using namespace IceHockeyGame;
using namespace RobotSubSystem;
using namespace Robot;

double TrajectoryPlan::GetPositionX(void)
{
	return position_x;
}
double TrajectoryPlan::GetPositionY(void)
{
	return position_y;
}
double TrajectoryPlan::GetVelocityX(void)
{
	return velocity_x;
}
double TrajectoryPlan::GetVelocityY(void)
{
	return velocity_y;
}