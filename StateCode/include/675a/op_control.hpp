#include "api.h"

extern pros::Task drive_lock_task();
extern pros::Task mogoMacro_task();

void op_control();

// user control macros
void startDriveLockSwitch();
void startMogoMacro();
int driveLockSwitch();
int mogoMacro();

// manual user control
void useDriveLock();
void useMogoMacro();
void useClaw();
void useLift();
void useConveyor();
void useBlocker();
