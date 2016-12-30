#pragma once
#ifndef ROBIT_SUB_SYSTEM_ROBIT_H
#define ROBIT_SUB_SYSTEM_ROBOT_H
#include"RobotSystem.h"
namespace IceHockeyGame{
	namespace RobotSubSystem{
		class RobotCommand :public RobotSystem
		{
		private:
			double targ_position_x; //Ŀ����x����
			double targ_position_y; //Ŀ����y����
			double targ_velocity_x; //Ŀ����x�����ٶ�
			double targ_velocity_y; //Ŀ����y�����ٶ�
			double targ_time;       //����Ŀ�������ʱ��
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
