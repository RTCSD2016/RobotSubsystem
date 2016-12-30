#pragma once

#ifndef ROBITSYSTEM_H
#define ROBOTSYSTEM_H

namespace IceHockeyGame
{
	class RobotSystem
	{	
	private:
		double position_x;             //��е��x����
		double position_y;             //��е��y����
		double velocity_x;             //��е��x�����ٶ�
		double velocity_y;             //��е��y�����ٶ�
	
	public:

		RobotSystem();
		
		virtual~RobotSystem();
		/**
		*@return robot hand position
		*/
		virtual double GetPosition(void)=0;
		/**
		*@return robot hand velocoty
		*/
		virtual double GetVelocity(void)=0;
		
	};
}
#endif //ROBOTSYSTEM_H