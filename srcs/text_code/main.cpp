#include"stdafx.h"
#include <iostream>
#include "Axis.h"
#include "Robot.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	Axis_state state_init;
	state_init = { true, false };

	parameter parameter_init_X, parameter_init_Y;
	parameter_init_X = { 0, 0, 0, 0, 5000 };
	parameter_init_Y = { 0, 0, 0, 0, 5000 };

	new_cmd new_cmd_init;
	new_cmd_init = { 350, 1000, 0.5 }; 
	//×¢ÒâÖ¸ÁîÒ»°ãÂú×ã New_Cmd.Time * New_Cmd.Velocity > (New_Cmd.Position - Parameter.Position)> New_Cmd.Time * New_Cmd.Velocity / 2


	Axis Axis_X(state_init, parameter_init_X, new_cmd_init);
	Axis Axis_Y(state_init, parameter_init_Y, new_cmd_init);


	Robot robot_test(Axis_X, Axis_Y,10,10);
	robot_test.Display();

	Axis_X.take_order();

        Axis_Y.take_order();

        Robot robot_test_now(Axis_X, Axis_Y,10,10);
	robot_test_now.Display();

	return 0;

}
