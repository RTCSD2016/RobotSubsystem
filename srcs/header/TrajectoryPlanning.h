#pragma once
#ifndef SUB_ROBIT_SYSTEM_ROBIT_Trajectory_Plan_H
#define SUB_ROBIT_SYSTEM_ROBIT_Trajectory_Plan_H
#include"Robot.h"
namespace IceHockeyGame{
	namespace SubRobotSystem{
		namespace Robot{
			class TrajectoryPlan :public Robot
			{
			public:
				double GetPosition(void);
				double GetVelocity(void);
			};
		}
	}
}
#endif //SUB_ROBIT_SYSTEM_ROBIT_Trajectory_Plan_H