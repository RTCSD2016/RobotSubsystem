#pragma once

#ifndef ROBITSYSTEM_ROBITCOMMAND_H
#define ROBITSYSTEM_ROBOTCOMMAND_H

#include"RobotSystem.h"
namespace IceHockeyGame{
	namespace RobotSubSystem{
		class RobotCommand :public RobotSystem
		{
		protected:
			double targ_position_x; //目标点的x坐标
			double targ_position_y; //目标点的y坐标
			double targ_velocity_x; //目标点的x方向速度
			double targ_velocity_y; //目标点的y方向速度
			double targ_time;       //到达目标点所需时间

		public:
			RobotCommand();

			

			~RobotCommand(){}

			virtual void InitTrajectoryPlan(double tpx, double tpy, double tvx, double tvy, double tt)=0;

			/**
			*@set the target position
			*/
			void SetPosition(double x, double y);
			/**
			*@set the target velocition
			*/
			void SetVelocity(double x, double y);
			/**
			*@set the target time
			*/
			void SetTime(double time);

		};

	}
}
#endif //ROBITSYSTEM_ROBOTCOMMAND_H
