#include"RobotCommand.h"

using namespace IceHockeyGame;
using namespace RobotSubSystem;

RobotCommand::RobotCommand()
{
	
	this->targ_position_x = 0;
	this->targ_position_y = 0;
	this->targ_velocity_x = 0;
	this->targ_velocity_y = 0;
	this->targ_time = 0;
	
}

void RobotCommand::SetPosition(double x, double y)
{
	targ_position_x = x;
	targ_position_y = y;
}
void RobotCommand::SetVelocity(double x, double y)
{
	targ_velocity_x = x;
	targ_velocity_y = y;
}
void RobotCommand::SetTime(double time)
{
	targ_time = time;
}

