#include "keyboard_input.h"

int main(int argc, char** argv){
	// start node
	ros::init(argc, argv, "keyboard_input_node");


	keyboard_input::KeyboardInput keyboard_input;

	ros::Rate loop_rate(100);

	while(ros::ok())
	{

		keyboard_input.read_keyboard();

		ros::spinOnce();
		loop_rate.sleep();
	}
	
	return 0;
}