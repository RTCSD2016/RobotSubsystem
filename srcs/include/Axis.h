#pragma once

#ifndef AXIS_H
#define AXIS_H

// "Axis_h"   

class Axis
{
private:
	bool Request;   //�Ƿ����ָָ��
	bool Done;      //�Ƿ�������˶�ָ��
	double Position;      //λ��
	double Velocity;      //�ٶ�
	double Acceleration;  //���ٶ�
	double Deceleration;  //���ٶ�
	double MaxAcceleration; //�����ٶ�����ֵ

public:
	Axis();
	virtual ~Axis();
	/**
	*@get the Request
	*/
	virtual bool GetRequest();
	/**
	*@get the Done
	*/
	virtual bool GetDone();
	/**
	*@get the Position
	*/
	virtual double GetPosition();
	/**
	*@get the Velocity
	*/
	virtual double GetVelocity();
	/**
	*@get the Acceleration
	*/
	virtual double GetAcceleration();
	/**
	*@get the Deceleration
	*/
	virtual double GetDeceleration();
	/**
	*@get the MaxAcceleration
	*/
	virtual double GetMaxAcceleration();
};

#endif
