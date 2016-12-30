#pragma once
#ifndef SUB_ROBIT_SYSTEM_H
#define SUB_ROBOT_SYSTEM_H
namespace IceHockeyGame
{
	class RobotSystem
	{
	
	private:
		double position_x;             //机械手x坐标
		double position_y;             //机械手y坐标
		double velocity_x;             //机械手x方向速度
		double velocity_y;             //机械手y方向速度
	
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
#endif //SUB_ROBOT_SYSTEM_H