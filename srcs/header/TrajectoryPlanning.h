#pragma once

#ifndef ROBITSYSTEM_ROBOTCOMMAND_TRAJECTORY_PLAN_H
#define ROBITSYSTEM_ROBOTCOMMAND_TRAJECTORY_PLAN_H

#include"RobotCommand.h"

namespace IceHockeyGame{
	namespace RobotSubsystem{
		namespace Robot{
			class TrajectoryPlan :public RobotCommand
			{
			public:
				double GetPosition(void);
				double GetVelocity(void);
			};
		}
	}
}
#endif //ROBITSYSTEM_ROBOTCOMMAND_TRAJECTORY_PLAN_H