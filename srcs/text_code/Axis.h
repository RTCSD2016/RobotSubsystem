#ifndef AXIS_H
#define AXIS_H

// "Axis_h"   
struct Axis_state{        //״̬
	bool Request;   //�Ƿ����ָָ��
	bool Done;      //�Ƿ�������˶�ָ��
};


struct parameter{         //�˶�����
	double Position;      //λ��
	double Velocity;      //�ٶ�
	double Acceleration;  //���ٶ�
	double Deceleration;  //���ٶ�
	double MaxAcceleration; //�����ٶ�����ֵ
};

struct new_cmd{           //��������
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
	void init_Axis(Axis_state, parameter, new_cmd);  //���ʼ������
	Axis_state Get_state();                          //����Axis�����״̬
	parameter Get_parameter();                       //����Axis����Ĳ���
	new_cmd Get_new_cmd();                           //����Axis����Ľ����������
	void take_order();                               //ִ���������ʱ����Axis����
	~Axis(){};
};

#endif
