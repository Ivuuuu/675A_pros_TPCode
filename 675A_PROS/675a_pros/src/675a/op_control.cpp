#include "main.h"


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

  // button presses -- drive lock -----
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP))
  {
    startDriveLockSwitch();
  }

// mogo macro     ----
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
  {
    pros::Task mogo_control_task(mogoMacro);
  }
  else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
  {
    mogoIsDown = true;
    mogoIsSensed = false;
    pros::Task mogo_control_task(mogoMacro);
  }

  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
  {
    if(clamp_current_state == true)
    {
      clawADI.set_value(false);
      clamp_current_state = false;
    }
    else if(clamp_current_state == false)
    {
      clawADI.set_value(true);
      clamp_current_state = true;
    }
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
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT))
  {
    conveyor.move_velocity(conveyor_speed);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT))
  {
    conveyor.move_velocity(-conveyor_speed);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
  {
    conveyor.move_velocity(0);
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
  if(mogoIsDown)
  {
    if(mogoIsSensed)
    {
      mogo.move_relative(mogo_mid_pos, 70);
    }
    else
    {
      mogo.move_relative(mogo_start_pos, 100);
    }
    mogo = false;
  }
  else if(!mogoIsDown)
  {
    if(mogoIsSensed)
    {
      mogo.move_relative(mogo_bottom_pos, 52);
    }
    else
    {
      mogo.move_relative(mogo_bottom_pos, 100);
      mogoIsSensed = true;
    }

    mogoIsDown = true;
  }

  master.rumble(".");
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
