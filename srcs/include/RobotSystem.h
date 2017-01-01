#pragma once
#ifndef ROBIT_SUB_SYSTEM_H
#define ROBOT_SUB_SYSTEM_H
namespace IceHockeyGame
{
	class RobotSystem
	{
	
	protected:
		double position_x;             //��е��x����
		double position_y;             //��е��y����
		double velocity_x;             //��е��x�����ٶ�
		double velocity_y;             //��е��y�����ٶ�
	
	public:

		RobotSystem()
		{
			this->position_x = 0;
			this->position_y = 0;
			this->velocity_x = 0;
			this->velocity_y = 0;
		}
		
		virtual~RobotSystem();

		virtual void InitPosition(double x, double y);

		virtual void InitVelocity(double x, double y);
		/**
		*@return robot hand position
		*/
		virtual double GetPositionX(void)=0;
		/**
		*@return robot hand velocity
		*/
		virtual double GetVelocityX(void)=0;
		/**
		*@return robot hand position
		*/
		virtual double GetPositionY(void)=0;
		/**
		*@return robot hand velocity
		*/
		virtual double GetVelocityY(void)=0;
	};
}
#endif //ROBOT_SUB_SYSTEM_H