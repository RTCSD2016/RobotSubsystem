#pragma once
#ifndef ROBITSYSTEM_H
#define ROBOTSYSTEM_H


namespace IceHockeyGame
{
	class RobotSystem
	{
	
	protected:
		double position_x;             //��е��x����
		double position_y;             //��е��y����
		double velocity_x;             //��е��x�����ٶ�
		double velocity_y;             //��е��y�����ٶ�
		bool Request;                  //�Ƿ����ָָ��
		bool Done;                     //�Ƿ�������˶�ָ��

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