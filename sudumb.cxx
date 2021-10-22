// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include "execpk.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Fl_Double_Window *main_window=(Fl_Double_Window *)0;

Fl_Secret_Input *input_fl=(Fl_Secret_Input *)0;

Fl_Output *cmd_op=(Fl_Output *)0;

int main(int argc, char **argv) {
  if(argc < 2){
  	printf("not enough parameters\n");
  	exit(0);
  }
  { main_window = new Fl_Double_Window(585, 230);
    main_window->color((Fl_Color)38);
    { Fl_Box* o = new Fl_Box(60, 10, 445, 20, "Authentication is needed as the super user");
      o->labelfont(1);
      o->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(42, 40, 445, 20, "An application is attempting to perform an action that requires privileges.");
      o->labelsize(12);
      o->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(21, 60, 445, 20, "Authentication as the super user is required to perform this action.");
      o->labelsize(12);
      o->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { input_fl = new Fl_Secret_Input(175, 90, 350, 30, "Password for root: ");
      input_fl->box(FL_FLAT_BOX);
      input_fl->color((Fl_Color)35);
      input_fl->labelsize(12);
      input_fl->labelcolor(FL_BACKGROUND2_COLOR);
      input_fl->textsize(12);
      input_fl->textcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Input* input_fl
    { Fl_Button* o = new Fl_Button(475, 195, 95, 20, "Authenticate");
      o->box(FL_FLAT_BOX);
      o->color((Fl_Color)33);
      o->labelsize(12);
      o->labelcolor(FL_BACKGROUND2_COLOR);
      o->callback((Fl_Callback*)CB_Button);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(375, 195, 95, 20, "Cancel");
      o->box(FL_FLAT_BOX);
      o->color((Fl_Color)33);
      o->labelsize(12);
      o->labelcolor(FL_BACKGROUND2_COLOR);
      o->callback((Fl_Callback*)Exit_button);
    } // Fl_Button* o
    { cmd_op = new Fl_Output(175, 130, 350, 30, "Command: ");
      cmd_op->box(FL_FLAT_BOX);
      cmd_op->color((Fl_Color)35);
      cmd_op->labelsize(12);
      cmd_op->labelcolor(FL_BACKGROUND2_COLOR);
      cmd_op->textsize(12);
      cmd_op->textcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Output* cmd_op
    main_window->end();
  } // Fl_Double_Window* main_window
  for (int i = 1 ; i < argc ; i++) {
  	string init(cmd_op->value());
  	string add(argv[i]);
  	if (init != ""){
  		init.append(" ");
  	}
  	init.append(add);
  	cmd_op->value(init.c_str());
  }
  main_window->show();
  return Fl::run();
}

void CB_Button(Fl_Widget*, void*) {
  string paswd(input_fl->value());
  string cmd(cmd_op->value());
  main_window->hide();
  system(("echo "+paswd+ " | su -c '"+ cmd + "'&").c_str());
  exit(0);
}

void Exit_button(Fl_Widget*, void*) {
  exit(0);
}