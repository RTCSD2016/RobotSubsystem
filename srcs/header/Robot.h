#pragma once
#ifndef SUB_ROBIT_SYSTEM_ROBIT_H
#define SUB_ROBIT_SYSTEM_ROBOT_H
#include"SubRobotSystem.h"
namespace IceHockeyGame{
	namespace SubRobotSystem{
		class Robot :public RobotSystem
		{
		private:
			double targ_position_x; //目标点的x坐标
			double targ_position_y; //目标点的y坐标
			double targ_velocity_x; //目标点的x方向速度
			double targ_velocity_y; //目标点的y方向速度
			double targ_time;       //到达目标点所需时间
		public:
			Robot();
			virtual~Robot();
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
		};

	}
}
#endif //SUB_ROBIT_SYSTEM_ROBOT_H
