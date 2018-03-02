#include "keyboard_input.h"


namespace keyboard_input {

  KeyboardInput::KeyboardInput() {

    initscr();
    cbreak(); //Disable buffering
    noecho(); // supress echo
    keypad(stdscr,TRUE); // adds special keystrokes like backspace, delete, and the arrow keys
    nodelay(stdscr,TRUE); // allows getch() to work in a non-blocking manner

    keyboard_pub_ = nh_.advertise<keyboard_input::keyboard>("keyboard_input",1);

    instructions_srv_ = nh_.advertiseService("display_instructions", &KeyboardInput::display_instructions, this);
  }

  void KeyboardInput::read_keyboard() {

    int ch;
    if((ch=getch())==ERR){
      // user hasn't responded. do nothing
    }
    else{
      keyboard_input::keyboard msg;
      msg.key_pressed = ch;
      keyboard_pub_.publish(msg);
    }

  }

  bool KeyboardInput::display_instructions(keyboard_input::instructions::Request &req,
                  keyboard_input::instructions::Response &res) {

    std::string instructions = req.instructions;

    std::cout << instructions << "\r" << std::endl;

    return true;
  }




}


