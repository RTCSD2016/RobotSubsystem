#include<iostream>
#include"RobotSystem.h"
#include"RobotCommand.h"
#include"TrajectoryPlanning.h"



using namespace IceHockeyGame;
using namespace RobotSubSystem;
using namespace Robot;



int main(void)
{
	double x, y,vx,vy,t;
	char i;
	TrajectoryPlan RobotHand(0, 0, 0, 0, true, false);
	RobotHand.InitTrajectoryPlan(300, 400, 900, 1000, 500, 200, 200);
    i = std::cin.get();
	while (1)
	{
		if (i == '\n')
		{
			std::cout << "����Ŀ��λ�ò���\n:";
			std::cout << "targ_position_x=";
			std::cin >> x;
			std::cout << "targ_position_y=";
			std::cin >> y;
			std::cout << "����Ŀ���ٶȲ���\n:";
			std::cout << "targ_velocity_x=";
			std::cin >> vx;
			std::cout << "targ_velocity_y=";
			std::cin >> vy;
			std::cout << "���뵽��Ŀ��λ��ʱ��\n:";
			std::cout << "targ_time=";
			std::cin >> t;
			RobotHand.SetPosition(x, y);
			RobotHand.SetVelocity(vx, vy);
			RobotHand.SetTime(t);
			RobotHand.Planning();
			RobotHand.LinearInterpolation();

		}


	}
	
	return 0;
	
	
}