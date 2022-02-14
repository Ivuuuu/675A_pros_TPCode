#include "main.h"


//MAIN USER CONTROL LOOP--------------------------------------------------------
void op_control()
{
  useDriveLock();
  useMogoMacro(); //R2 & X
  useClaw();      //R1
  useLift();      //L1 & L2
  useConveyor();  //left,right,down

  if (lift_r.get_position() <= 100)
  {
    conveyor.move_velocity(0);
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
  {
    mogo.move_relative(10, 100);
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
  {
    mogo.move_relative(-10, 100);
  }

  // if lift value is under 100 make conveyor stop no matter what
}


//MANUAL USER CONTROL-----------------------------------------------------------
void useDriveLock()
{
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP))
  {
    pros::Task drive_lock_task(driveLockSwitch);
  }

  if (driveLock)
  {
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  }
  else if (driveLock == false)
  {
    chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  }
}

void useMogoMacro()
{
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
  {
    pros::Task mogo_control_task(mogoMacro);
  }
  else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2))
  {
    mogoIsDown = true;
    pros::Task mogo_control_task(mogoMacro);
  }
}

void useClaw()
{
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
  {
    if(clamp_is_down == true)
    {
      clawADI.set_value(false);
      clamp_is_down = false;
    }
    else if(clamp_is_down == false)
    {
      clawADI.set_value(true);
      clamp_is_down = true;
    }
  }
}

void useLift()
{
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
  {
    lift_l.move_velocity(lift_up_speed);
    lift_r.move_velocity(lift_up_speed);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
  {
    lift_l.move_velocity(-lift_down_speed);
    lift_r.move_velocity(-lift_down_speed);
  }
  else
  {
    lift_l.move_velocity(0);
    lift_r.move_velocity(0);
  }
}

void useConveyor()
{
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT))
  {
    conveyor.move_velocity(conveyor_speed);
    conveyorOn = true;
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT))
  {
    conveyor.move_velocity(-conveyor_speed);
    conveyorOn = true;
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
  {
    conveyor.move_velocity(0);
    conveyorOn = false;
  }
}


//USER CONTROL TASKS------------------------------------------------------------
int driveLockSwitch()
{
  if (driveLock)  //disable
  {
    driveLock = false;
    master.rumble("-");
  }
  else if (driveLock == false)  //enable
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
    mogo.move_absolute(mogo_start_pos, 100);
    mogoIsDown = false;
  }
  else if(!mogoIsDown)
  {
    if (mogoMidToggle)
    {
      mogo.move_absolute(mogo_bottom_pos, 85);
      mogoMidToggle = false;
    }
    else
    {
      mogo.move_absolute(mogo_mid_pos, 100);
      mogoMidToggle = true;
    }
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
