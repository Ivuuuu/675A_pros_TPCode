#include "api.h"

extern bool driveLock;
extern bool mogoMacroBool;
extern bool mogoIsDown;

extern int lift_up_speed;
extern int lift_down_speed;

extern int claw_open_speed;
extern int claw_close_speed;

extern int mogo_down_speed;

extern int conveyor_speed;

extern pros::Task drive_lock_switch_task();
extern pros::Task mogoMacro_task();

void op_control();
void startDriveLockSwitch();
void startMogoMacro();
int driveLockSwitch();
int mogoMacro();
