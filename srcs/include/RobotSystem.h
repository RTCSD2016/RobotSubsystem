#pragma once
#ifndef ROBITSYSTEM_H
#define ROBOTSYSTEM_H


namespace IceHockeyGame
{
	class RobotSystem
	{
	
	protected:
		double position_x;             //机械手x坐标
		double position_y;             //机械手y坐标
		double velocity_x;             //机械手x方向速度
		double velocity_y;             //机械手y方向速度
		bool Request;                  //是否接受指指令
		bool Done;                     //是否已完成运动指令

	public:

		RobotSystem(){}
		
		~RobotSystem(){}

		/*virtual void InitPosition(double x, double y);

		virtual void InitVelocity(double x, double y);*/
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
#endif //ROBOTSYSTEM_H