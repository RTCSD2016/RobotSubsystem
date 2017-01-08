#pragma once
#ifndef ROBITSYSTEM_ROBITTRAJECTORY_PLAN_H
#define ROBITSYSTEM_ROBITTRAJECTORY_PLAN_H

#include"RobotCommand.h"


namespace IceHockeyGame{
	namespace RobotSubSystem{
		namespace Robot{
			class TrajectoryPlan :public RobotCommand
			{
			private:
				double Acceleration_time_x;
				double Uniform_motion_time_x;
				double ActualAccelerration_x;
				double Acceleration_time_y;
				double Uniform_motion_time_y;
				double ActualAccelerration_y;
				double Deceleration_x;
				double Deceleration_y;
				double Deceleration_time_x;
				double Deceleration_time_y;
			public:
				TrajectoryPlan();
				 
				
				~TrajectoryPlan(){}

				TrajectoryPlan(double, double, double, double, bool, bool);
				void InitTrajectoryPlan(double, double, double, double, double, double, double);
				double GetPositionX(void);
				double GetPositionY(void);
				double GetVelocityX(void);
				double GetVelocityY(void);
				void Planning();
				void LinearInterpolation();
				void Deceleration();
			};
		}
	}
}
#endif //ROBITSYSTEM_ROBITTRAJECTORY_PLAN_H