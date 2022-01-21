#include "main.h"

//GLOBAL VARIABLES--------------------------------------------------------------
bool driveLock = false;
bool mogoMacroBool = false;
bool mogoIsDown = false;
bool mogoIsSensed = false;

int lift_up_speed = 200;
int lift_down_speed = 200;

int claw_open_speed = 200;
int claw_close_speed = 200;

int mogo_down_speed = 200;

int conveyor_speed = 100; // prolly need to change


bool clamp_current_state = false;

int mogo_start_pos = 0;   // check with bbao
int mogo_mid_pos = 100;
int mogo_bottom_pos = 50;
