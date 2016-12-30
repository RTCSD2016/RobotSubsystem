#pragma once
#ifndef ROBIT_SUB_SYSTEM_ROBIT_Trajectory_Plan_H
#define ROBIT_SUB_SYSTEM_ROBIT_Trajectory_Plan_H
#include"RobotCommand.h"
namespace IceHockeyGame{
	namespace RobotSubSystem{
		namespace Robot{
			class TrajectoryPlan :public RobotCommand
			{
			private:
				double accleration;
				double deceleration;
			public:
				double GetPositionX(void);
				double GetPositionY(void);
				double GetVelocityX(void);
				double GetVelocityY(void);
			};
		}
	}
}
#endif //ROBIT_SUB_SYSTEM_ROBIT_Trajectory_Plan_H