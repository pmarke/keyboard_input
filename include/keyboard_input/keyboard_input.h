#pragma once

#include "ros/ros.h"
#include <keyboard_input/keyboard.h>
#include "keyboard_input/instructions.h"
#include <ncurses.h>
#include <iostream>


/*This class reads keyboard inputs and publishes them over ros*/
namespace keyboard_input {

	class KeyboardInput {

	public:
		KeyboardInput();

		// Get input values from the keyboard and publish them via ROS
		void read_keyboard();

	private:

		//ROS
		ros::NodeHandle nh_;
		ros::Publisher keyboard_pub_;
		ros::ServiceServer instructions_srv_;

		// Print instructions
		bool display_instructions(keyboard_input::instructions::Request &req,
								  keyboard_input::instructions::Response &res);



	};



}