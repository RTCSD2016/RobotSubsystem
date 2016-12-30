#pragma once
#ifndef SUB_ROBIT_SYSTEM_ROBIT_H
#define SUB_ROBIT_SYSTEM_ROBOT_H
#include"SubRobotSystem.h"
namespace IceHockeyGame{
	namespace SubRobotSystem{
		class Robot :public RobotSystem
		{
		private:
			double targ_position_x; //Ŀ����x����
			double targ_position_y; //Ŀ����y����
			double targ_velocity_x; //Ŀ����x�����ٶ�
			double targ_velocity_y; //Ŀ����y�����ٶ�
			double targ_time;       //����Ŀ�������ʱ��
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
