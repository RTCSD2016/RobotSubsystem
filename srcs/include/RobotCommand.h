#pragma once

#ifndef ROBITSYSTEM_ROBITCOMMAND_H
#define ROBITSYSTEM_ROBOTCOMMAND_H

#include"RobotSystem.h"
namespace IceHockeyGame{
	namespace RobotSubSystem{
		class RobotCommand :public RobotSystem
		{
		protected:
			double targ_position_x; //Ŀ����x����
			double targ_position_y; //Ŀ����y����
			double targ_velocity_x; //Ŀ����x�����ٶ�
			double targ_velocity_y; //Ŀ����y�����ٶ�
			double targ_time;       //����Ŀ�������ʱ��

		public:
			RobotCommand();

			

			~RobotCommand(){}

			virtual void InitTrajectoryPlan(double tpx, double tpy, double tvx, double tvy, double tt,double dx,double dy)=0;

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
