#ifndef AXIS_H
#define AXIS_H

// "Axis_h"   
struct Axis_state{        //状态
	bool Request;   //是否接受指指令
	bool Done;      //是否已完成运动指令
};


struct parameter{         //运动参数
	double Position;      //位置
	double Velocity;      //速度
	double Acceleration;  //加速度
	double Deceleration;  //减速度
	double MaxAcceleration; //最大加速度限制值
};

struct new_cmd{           //接受命令
	double Position;
	double Velocity;
	double Time;

};

class Axis
{
private:


public:
	Axis_state State;
	parameter Parameter;
	new_cmd New_Cmd;
	Axis();
	Axis(Axis_state, parameter, new_cmd);
	Axis(Axis & axis);
	void init_Axis(Axis_state, parameter, new_cmd);  //轴初始化函数
	Axis_state Get_state();                          //返回Axis对象的状态
	parameter Get_parameter();                       //返回Axis对象的参数
	new_cmd Get_new_cmd();                           //返回Axis对象的接受命令参数
	void take_order();                               //执行命令，并及时更新Axis对象
	~Axis(){};
};

#endif
