#pragma once
#ifndef ROBIT_SUB_SYSTEM_ROBIT_H
#define ROBIT_SUB_SYSTEM_ROBOT_H
#include"RobotSystem.h"
namespace IceHockeyGame{
	namespace RobotSubSystem{
		class RobotCommand :public RobotSystem
		{
		private:
			double targ_position_x; //目标点的x坐标
			double targ_position_y; //目标点的y坐标
			double targ_velocity_x; //目标点的x方向速度
			double targ_velocity_y; //目标点的y方向速度
			double targ_time;       //到达目标点所需时间
		public:
			RobotCommand();

			~RobotCommand();

			void InitPosition(double x , double y);

			void InitVelocity(double x , double y);

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
#endif //ROBIT_SUB_SYSTEM_ROBOT_H
