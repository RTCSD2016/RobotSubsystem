#pragma once

#ifndef ROBOTSYSTEM_ROBOTCOMMAND_H
#define ROBOTSYSTEM_ROBOTCOMMAND_H

#include"RobotSystem.h"

namespace IceHockeyGame{
	namespace RobotSubsystem{
		class RobotCommand :public RobotSystem
		{
		private:
			double targ_position_x; //目标点的x坐标
			double targ_position_y; //目标点的y坐标
			double targ_velocity_x; //目标点的x方向速度
			double targ_velocity_y; //目标点的y方向速度
			long targ_time;       //到达目标点所需时间
		public:
			RobotCommand();
			virtual~RobotCommand();
			/**
			*@set the target position
			*/
			virtual void SetPosition(double x, double y);
			/**
			*@set the target velocition
			*/
			virtual void SetVelocity(double x, double y);
			/**
			*@set the target time
			*/
			virtual void SetTime(double time);
			/**
			*@get the targ_position_x
			*/
			virtual double GetTargPosition_X();
			/**
			*@get the targ_position_y
			*/
			virtual double GetTargPosition_Y();
			/**
			*@get the targ_velocity_x
			*/
			virtual double GetTargVelocity_X();
			/**
			*@get the targ_velocity_y
			*/
			virtual double GetTargVelocity_Y();
			/**
			*@get the targ_time
			*/
			virtual double GetTargTime();

		};

	}
}
#endif //RobotSystem_ROBOTCOMMAND_H
