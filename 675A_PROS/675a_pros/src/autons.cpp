#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 122; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}




///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .

void testAuton()
{
  lift_to(550, 50);
}

void skillsAuton()
{
  claw_open();

  chassis.set_drive_pid(15, 70);
  chassis.wait_drive();

  claw_close(); // grab 1st mogo_up

  lift_to(100, 100);

  chassis.set_drive_pid(-5, 70);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, 70);  // turn to clear wall
  chassis.wait_drive();

  chassis.set_drive_pid(5, 70); // drive into wall to allign
  chassis.wait_drive();

  mogo_down(mogo_down_speed);

  chassis.set_drive_pid(24, 70); // drive to left neutral mogo
  chassis.wait_drive();

  mogo_up();

  chassis.set_turn_pid(-45, 70);  // turn to platform with claw facing platform
  chassis.wait_drive();

  chassis.set_drive_pid(24, 70);  // drive to platform
  chassis.wait_drive();

  chassis.set_turn_pid(-10, 70);
  chassis.wait_drive();

  claw_open();  // drop alliance mogo on plat

  chassis.set_drive_pid(-10, 70);
  chassis.wait_drive();


}

void zoomsSkillsAuton()
{
  // robot starts plat up side, top right corner of 2nd tile, front facing the wall
  mogo_down(mogo_down_speed);

  chassis.set_drive_pid(17.4, 95);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 80);
  claw_open();

  chassis.wait_drive();

  chassis.set_drive_pid(-14.5, 60);
  chassis.wait_drive();

  mogo_mid(200);

  chassis.set_drive_pid(14.5, 80);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 70);
  chassis.wait_drive();

  chassis.set_drive_pid(25, 70);
  chassis.wait_drive();

  claw_close();
  wait(400);



  //first yellow picked up


  start_lift_to(120, 120);

  chassis.set_drive_pid(23, 70); //drives fwd after grabbing mogo
  chassis.wait_drive();

  chassis.set_turn_pid(-41, 75); //turns to face platform
  chassis.wait_drive();

  lift_to(550, 180);

  chassis.set_drive_pid(37, 80, true); //drives to the platform
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, -32, 50); //swings to adjust with platform
  chassis.wait_drive();

  chassis.set_drive_pid(5, 80, true); //drives to the platform
  chassis.wait_drive();

  lift_to(500, 140);

  wait(400);

  claw_open();
  wait(300);

  // ----------------------------------------------------------------------
  // first neutral scored on plat

  //lift_to(450, 80);

  chassis.set_drive_pid(-20, 80, true);
  // chassis.wait_until(-6);
  // start_lift_to(0, 150);
  // mogo_down(mogo_down_speed);
  //
  // chassis.wait_drive();
  //
  //
  // chassis.set_drive_pid(4, 85, true); //drives away from mogo
  // chassis.wait_drive();
  //
  // chassis.set_turn_pid(156, 95); //spins to face mogo
  // chassis.wait_drive();
  //
  // chassis.set_drive_pid(5, 65, true); //drives into mogo
  // chassis.wait_drive();
  //
  // claw_close();
  // wait(200);
  //
  // lift_to(480, 130);
  //
  // chassis.set_turn_pid(-17, 65);
  // chassis.wait_drive();
  //
  // chassis.set_drive_pid(17, 70, true);
  // chassis.wait_drive();
  //
  // claw_open();
  // wait(300);
  //
  // // --------------------------------------------------------------
  // alliance mogo scored on plat
}
//

//
