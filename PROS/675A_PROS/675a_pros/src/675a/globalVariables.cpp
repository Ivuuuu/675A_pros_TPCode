#include "main.h"

//GLOBAL VARIABLES--------------------------------------------------------------
bool driveLock = false;
bool mogoMacroBool = false;
bool mogoIsDown = false;
bool mogoMidToggle = false;

int lift_up_speed = 200;
int lift_down_speed = 200;

// int claw_open_speed = 200;
// int claw_close_speed = 200;

int mogo_down_speed = 200;

int conveyor_speed = 600; // prolly need to change


bool clamp_is_down = false;

int mogo_start_pos = 0;   // check with bbao
int mogo_mid_pos = 252;
int mogo_bottom_pos = 525;
