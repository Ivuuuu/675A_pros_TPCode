#include "api.h"

extern pros::Task drive_lock_switch_task();
extern pros::Task mogoMacro_task();

void op_control();
void startDriveLockSwitch();
void startMogoMacro();
int driveLockSwitch();
int mogoMacro();
