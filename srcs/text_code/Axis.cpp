#include"stdafx.h"
#include "Axis.h"
#include <stdio.h>
#include <math.h>


#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/timer.h>


Axis::Axis()
{
	State = {false ,false };
	Parameter = { 0, 0, 0, 0 ,0};
	New_Cmd = { 0, 0, 0 };
}

Axis::Axis(Axis & axis)
{
	State = axis.State;
	Parameter = axis.Parameter;
	New_Cmd = axis.New_Cmd;
}

Axis::Axis(Axis_state init_state, parameter init_parameter, new_cmd init_new_cmd)
{
	State = init_state;
	Parameter = init_parameter;
	New_Cmd = init_new_cmd;

}

void Axis::init_Axis(Axis_state init_state, parameter init_parameter, new_cmd init_new_cmd)
{
	State = init_state;
	Parameter = init_parameter;
	New_Cmd = init_new_cmd;
}

Axis_state Axis::Get_state()
{
	return State;
}

parameter Axis::Get_parameter()
{
	return Parameter;
}

new_cmd Axis::Get_new_cmd()
{
	return New_Cmd;
}

void  Axis::take_order()
{
       
	double Acceleration_time;
	double Uniform_motion_time;
	double ActualAccelerration;
	State.Request = true;


	if (State.Request)
	{		

		Uniform_motion_time = 2 * (New_Cmd.Position - Parameter.Position) / New_Cmd.Velocity - New_Cmd.Time;
		Acceleration_time = New_Cmd.Time - Uniform_motion_time;
		ActualAccelerration = New_Cmd.Velocity / Acceleration_time;



		printf("ActualAccelerration : %f \n", ActualAccelerration);
		printf("Acceleration_time : %f \n", Acceleration_time);
		printf("Uniform_motion_time : %f \n", Uniform_motion_time);

   
                int t = 0;
                double Speed_new;
                double S_new;
           
                while(State.Request)
                {      
                                                
                     while (Acceleration_time - (t/1000.0) + 0.0006 > 0.0005)

			{
				Speed_new = (t/1000.0)*ActualAccelerration;
				S_new = 0.5*ActualAccelerration*(t/1000.0)*(t/1000.0);
				/*
			        RTIME now, previous;

			        rt_task_set_periodic(NULL, TM_NOW, 1000000000);
			        previous = rt_timer_read();

				   axis1_setpoint.Position = 0;
				   axis1_setpoint.Velocity = 0;

				    int temp;                               
                    while (1) {
					rt_task_wait_period(NULL);
					now = rt_timer_read();
					printf("Task A Time since last turn: %ld.%06ld ms\n",
					       (long)(now - previous) / 1000000,
					       (long)(now - previous) % 1000000);
					       previous = now;
		                      }
                                 */
                                
				printf("when t= %f ms,v= %f mm/s,s= %fmm\n", (t/1000.0), Speed_new, S_new);		      
				t++;

			}


			double s = S_new;

			while ( (Acceleration_time + Uniform_motion_time) - (t/1000.0) + 0.0006 > 0.0005)
			{
				Speed_new = Speed_new;
				S_new = s + Speed_new*((t/1000.0) - Acceleration_time);

                              	/*
			        RTIME now, previous;

			        rt_task_set_periodic(NULL, TM_NOW, 1000000000);
			        previous = rt_timer_read();

				axis1_setpoint.Position = 0;
				axis1_setpoint.Velocity = 0;

				int temp;                               
                while (1) {
				rt_task_wait_period(NULL);
				now = rt_timer_read();
				printf("Task A Time since last turn: %ld.%06ld ms\n",
					       (long)(now - previous) / 1000000,
					       (long)(now - previous) % 1000000);
					       previous = now;
		                      }
                                 */
                                
				printf("when t= %f ms,v= %f mm/s,s= %fmm\n", (t/1000.0), Speed_new, S_new);
				t++;
			}

			State.Request = false;
			State.Done = true;
            Parameter.Position = New_Cmd.Position;
			
                }

		
		/*
		while (State.Request)
		{
			
			int t1 = 0;
			double Speed_new;
			double S_new;

			while (t1 <= Acceleration_time)
			{
				Speed_new = t1*New_Cmd.Acceleration;
				S_new = 0.5*New_Cmd.Acceleration*t1*t1;
				printf("t= %d ms时，速度v= %f mm/s,位置s= %fmm\n", t1, Speed_new, S_new);
				t1++;
			}


			double s = S_new;
			while (t1 <= (Acceleration_time + Uniform_motion_time))
			{
				Speed_new = Speed_new;
				S_new = s + Speed_new*(t1 - Acceleration_time);
				printf("t= %d ms时，速度v= %f mm/s,位置s= %fmm\n", t1, Speed_new, S_new);
				t1++;
			}

			double sp = Speed_new;
			double ss = S_new;
			while (t1 <= (Acceleration_time + Uniform_motion_time + Deceleration_time))
			{
				Speed_new = sp - (t1 - Acceleration_time - Uniform_motion_time)*New_Cmd.Deceleration;
				S_new = ss + 0.5*New_Cmd.Deceleration*(t1 - Acceleration_time - Uniform_motion_time)*(t1 - Acceleration_time - Uniform_motion_time);
				printf("t= %d ms时，速度v= %f mm/s,位置s= %fmm\n", t1, Speed_new, S_new);
				t1++;
			}
			if (t1 > (Acceleration_time + Uniform_motion_time + Deceleration_time))
			{
				State.Request = false;
				State.Done = true;
			}
			
		}
		*/
	}
}
