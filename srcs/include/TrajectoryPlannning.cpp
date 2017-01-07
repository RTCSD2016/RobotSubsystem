#include"RobotSystem.h"
#include"RobotCommand.h"
#include"TrajectoryPlanning.h"
#include<iostream>

using namespace IceHockeyGame;
using namespace RobotSubSystem;
using namespace Robot;

TrajectoryPlan::TrajectoryPlan(){
	Acceleration_time_x = 0;
	Uniform_motion_time_x = 0;
	ActualAccelerration_x = 0;
	Acceleration_time_y = 0;
	Uniform_motion_time_y = 0;
	ActualAccelerration_y = 0;
	Deceleration_x = 0;
	Deceleration_y = 0;
	Deceleration_time_x = 0;
	Deceleration_time_y = 0;

}
TrajectoryPlan::TrajectoryPlan(double px, double py, double vx, double vy, bool request, bool done)
{
	position_x = px;
	position_y = py;
	velocity_x = vx;
	velocity_y = vy;
	Request = request;
	Done = done;
}

void TrajectoryPlan::InitTrajectoryPlan(double tpx, double tpy, double tvx, double tvy, double tt,double dx,double dy)
{
	targ_position_x = tpx;
	targ_position_y = tpy;
	targ_velocity_x = tvx;
	targ_velocity_y = tvy;
	targ_time = tt;
	Deceleration_x = dx;
	Deceleration_y = dy;
}

double TrajectoryPlan::GetPositionX(void)
{
	return position_x;
}
double TrajectoryPlan::GetPositionY(void)
{
	return position_y;
}
double TrajectoryPlan::GetVelocityX(void)
{
	return velocity_x;
}
double TrajectoryPlan::GetVelocityY(void)
{
	return velocity_y;
}


void TrajectoryPlan::Planning(void)//规划轨迹，算出速度加速度与对应时间
{
	if (Request)
	{
		//加速
		Uniform_motion_time_x = 2 * (targ_position_x - position_x) / targ_velocity_x - (targ_time / 1000.0);
		Acceleration_time_x = (targ_time / 1000.0) - Uniform_motion_time_x;
		ActualAccelerration_x = targ_velocity_x / Acceleration_time_x;

		std::cout << "ActualAccelerration_x : " << ActualAccelerration_x << std::endl;
		std::cout << "Acceleration_time_x : " << Acceleration_time_x << std::endl;
		std::cout << "Uniform_motion_time_x : " << Uniform_motion_time_x << std::endl;

		Uniform_motion_time_y = 2 * (targ_position_y - position_y) / targ_velocity_y - (targ_time / 1000.0);
		Acceleration_time_y = (targ_time / 1000.0) - Uniform_motion_time_y;
		ActualAccelerration_y = targ_velocity_y / Acceleration_time_y;

		std::cout << "ActualAccelerration_y : " << ActualAccelerration_y << std::endl;
		std::cout << "Acceleration_time_y : " << Acceleration_time_y << std::endl;
		std::cout << "Uniform_motion_time_y : " << Uniform_motion_time_y << std::endl;
		//减速
        Deceleration_time_x = targ_velocity_x / Deceleration_x;
		Deceleration_time_y = targ_velocity_y / Deceleration_y;
	}
	
		


	
}

void TrajectoryPlan::LinearInterpolation()
{
	double Velocity_new_X, Velocity_new_Y;                         //实时速度
	double Position_new_X, Position_new_Y;                         //实时位移
	long Timer = 0;                                                //实时时间

	while (Request)
	{
		if(Acceleration_time_x-(Timer/1000.0)>=0.001)      //X方向匀加速阶段，
		{
			Velocity_new_X = (Timer/1000.0)*ActualAccelerration_x;
			Position_new_X = 0.5*ActualAccelerration_x*(Timer/1000.0)*(Timer/1000.0);
			std::cout<<"when t= "<<Timer<<" ms,Velocity_X= "<<Velocity_new_X<<" mm/s,Position_X= "<<Position_new_X<<" mm\n";
			//再输出Y
            if (((Acceleration_time_y+Uniform_motion_time_y-(Timer/1000.0))>=0)&&((Acceleration_time_y-(Timer/1000.0))<=0.001))
			{
				Velocity_new_Y = Acceleration_time_y*ActualAccelerration_y;
				Position_new_Y = 0.5*ActualAccelerration_y*Acceleration_time_y*Acceleration_time_y+Velocity_new_Y * ((Timer / 1000.0) - Acceleration_time_y);
				std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
				std::cout << "next cycle: \n";
			}
			if ((Acceleration_time_y-(Timer/1000.0))>=0.001)//Y方向匀加速阶段
			{
				Velocity_new_Y = (Timer/1000.0)*ActualAccelerration_y;
				Position_new_Y = 0.5*ActualAccelerration_y*(Timer/1000.0)*(Timer/1000.0);
				std::cout<<"when t= "<<Timer<<" ms,Velocity_Y= "<<Velocity_new_Y<<" mm/s,Position_Y= "<<Position_new_Y<<" mm\n";
				std::cout<<"next cycle: \n";
			}
			

			
		}
		if (((Acceleration_time_x+Uniform_motion_time_x-(Timer/1000.0))>=0)&&(Acceleration_time_x-(Timer/1000.0))<=0.0001)//X方向匀速阶段
		{
			Velocity_new_X = Acceleration_time_x*ActualAccelerration_x;;
			Position_new_X = 0.5*ActualAccelerration_x*Acceleration_time_x*Acceleration_time_x+Velocity_new_X*((Timer / 1000.0) - Acceleration_time_x);
			std::cout << "when t= " << Timer << " ms,Velocity_X= " << Velocity_new_X << " mm/s,Position_X= " << Position_new_X << " mm\n";
			//再输出Y
            if (((Acceleration_time_y + Uniform_motion_time_y - (Timer / 1000.0) + 0.001)> 0) && ((Acceleration_time_y - (Timer / 1000.0)) <= 0.001))
			{
				Velocity_new_Y = Acceleration_time_y*ActualAccelerration_y;
				Position_new_Y = 0.5*ActualAccelerration_y*Acceleration_time_y*Acceleration_time_y+Velocity_new_Y*((Timer / 1000.0) - Acceleration_time_y);
				std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
				std::cout << "next cycle: \n";
			}
			if ((Acceleration_time_y-(Timer/1000.0))>= 0.001)//Y方向匀加速阶段
			{
				Velocity_new_Y = (Timer / 1000.0) * ActualAccelerration_y;
				Position_new_Y = 0.5*ActualAccelerration_y * (Timer / 1000.0)*(Timer / 1000.0);
				std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
				std::cout << "next cycle: \n";
			}
			
			
		}
		if (Timer > targ_time)
		{
			
			if ((Timer/1000.0) <= ((targ_time/1000.0) + Deceleration_time_x) || (Timer/1000.0) <= ((targ_time/1000.0) + Deceleration_time_y))
			{
				//减速
				if (Velocity_new_X > Deceleration_x)
				{
					Velocity_new_X = Velocity_new_X - Deceleration_x*((Timer/1000.0) - (targ_time/1000.0));
					Position_new_X = Position_new_X + 0.5*Deceleration_x*((Timer/1000.0) - (targ_time/1000.0))*((Timer/1000.0) - (targ_time/1000.0));
					std::cout << "when t= " << Timer << " ms,Velocity_X= " << Velocity_new_X << " mm/s,Position_X= " << Position_new_X << " mm\n";
                    if (Velocity_new_Y <= Deceleration_y)
					{
						Position_new_Y = Position_new_Y + 0.5*Velocity_new_Y*Velocity_new_Y / Deceleration_y;
						Velocity_new_Y = 0;
						std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
						std::cout << "next cycle: \n";

					}
				    if (Velocity_new_Y > Deceleration_y)
				    {
					    Velocity_new_Y = Velocity_new_Y - Deceleration_y*((Timer/1000.0) - (targ_time/1000.0));
					    Position_new_Y = Position_new_Y + 0.5*Deceleration_y*((Timer/1000.0) - (targ_time/1000.0))*((Timer/1000.0) - (targ_time/1000.0));
					    std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
					    std::cout << "next cycle: \n";
				    }
					
				}
				
				if (Velocity_new_X <= Deceleration_x)
				{
					Position_new_X = Position_new_X + 0.5*Velocity_new_X*Velocity_new_X / Deceleration_x;
					Velocity_new_X = 0;
					std::cout << "when t= " << Timer << " ms,Velocity_X= " << Velocity_new_X << " mm/s,Position_X= " << Position_new_X << " mm\n";
	                if (Velocity_new_Y <= Deceleration_y)
					{
						Position_new_Y = Position_new_Y + 0.5*Velocity_new_Y*Velocity_new_Y / Deceleration_y;
						Velocity_new_Y = 0;
						std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
						std::cout << "next cycle: \n";
						Request = false;
						Done = true;
						position_x = targ_position_x;
						position_y = targ_position_y;
						velocity_y = targ_velocity_x;
						velocity_y = targ_velocity_y;


					}
					if (Velocity_new_Y > Deceleration_y)
					{
						Velocity_new_Y = Velocity_new_Y - Deceleration_y*((Timer / 1000.0) - (targ_time/1000.0));
						Position_new_Y = Position_new_Y + 0.5*Deceleration_y*((Timer / 1000.0) - (targ_time/1000.0))*((Timer / 1000.0) - (targ_time/1000.0));
						std::cout << "when t= " << Timer << " ms,Velocity_Y= " << Velocity_new_Y << " mm/s,Position_Y= " << Position_new_Y << " mm\n";
						std::cout << "next cycle: \n";
					}
				
				}
				
			}
			
		}
		
		Timer++;

	}
	while(!Request)
	{
		
	}
}
