#include "main.h"

//GLOBAL VARIABLES--------------------------------------------------------------
bool driveLock = false;
bool mogoMacroBool = false;
bool mogoIsDown = false;

int lift_up_speed = 200;
int lift_down_speed = 200;

int claw_open_speed = 200;
int claw_close_speed = 200;

int mogo_down_speed = 200;

int conveyor_speed = 100; // prolly need to change

//MAIN USER CONTROL LOOP--------------------------------------------------------
void op_control()
{
  // use drive lock         ----
  if (driveLock)
  {
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  }
  else if (driveLock == false)
  {
    chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  }

  // button presses -- drive lock -- mogo macro   -----
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP))
  {
    startDriveLockSwitch();
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
  {
    startMogoMacro();
  }

  // button holds -- claw                 -----
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
  {
    claw.move_velocity(claw_open_speed);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
  {
    claw.move_velocity(-claw_close_speed);
  }
  else
  {
    claw.move_velocity(0);
    claw.set_brake_mode(MOTOR_BRAKE_HOLD);
  }

  // button holds -- lift                 -----
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
  {
    lift.move_velocity(lift_up_speed);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
  {
    lift.move_velocity(-lift_down_speed);
  }
  else
  {
    lift.move_velocity(0);
    lift.set_brake_mode(MOTOR_BRAKE_HOLD);
  }

  // mogo lift manual -- lift                 -----
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
  {
    mogo.move_velocity(mogo_down_speed);
  }

  // start/stop conveyor                 -----
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))
  {
    conveyor.move_velocity(conveyor_speed);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
  {
    conveyor.move_velocity(-conveyor_speed);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
  {
    conveyor.move_velocity(0);
    conveyor.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
}

//USER CONTROL TASKS------------------------------------------------------------
int driveLockSwitch()
{
  if (driveLock)
  {
    driveLock = false;
    master.rumble("--");
  }
  else if (driveLock == false)
  {
    driveLock = true;
    master.rumble("--");
  }
  return 1;
}


int mogoMacro()
{
  if (mogoIsDown == false)
  {
    mogo.move_absolute(935, 70);
    mogoMacroBool = false;
    mogoIsDown = true;
  }
  else if (mogoIsDown)
  {
    mogo.move_absolute(478, 100);
    mogoMacroBool = false;
    mogoIsDown = false;
  }
  return 1;
}


void startDriveLockSwitch()
{
  pros::Task c(driveLockSwitch);
}

void startMogoMacro()
{
  mogoMacroBool = true;
  pros::Task b(mogoMacro);
}
