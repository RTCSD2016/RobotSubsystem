#pragma once

#ifndef AXIS_H
#define AXIS_H

// "Axis_h"   

class Axis
{
private:
	bool Request;   //是否接受指指令
	bool Done;      //是否已完成运动指令
	double Position;      //位置
	double Velocity;      //速度
	double Acceleration;  //加速度
	double Deceleration;  //减速度
	double MaxAcceleration; //最大加速度限制值

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
