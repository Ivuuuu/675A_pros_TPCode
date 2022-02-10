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
  lift_to(540, 50);
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

    chassis.set_drive_pid(17.5, 90, true);
    chassis.wait_drive();

    chassis.set_turn_pid(-90, 90);
    claw_open();      //start_claw_open();

    chassis.wait_drive();

    chassis.set_drive_pid(-16, 55, true);
    chassis.wait_drive();

    mogo_mid(150);
    wait(100);

    // first alliance goal has been picked up with tilter
    chassis.set_drive_pid(16.5, 80, true);
    chassis.wait_drive();

    chassis.set_turn_pid(0, 70);
    chassis.wait_drive();

    start_lift_to(0, 100);

    chassis.set_drive_pid(24, 80, true);
    chassis.wait_drive();

    claw_close();
    wait(200);



    // first yellow picked up
    start_lift_to(150, 100);

    chassis.set_drive_pid(23, 80, true); //drives fwd after grabbing mogo
    chassis.wait_drive();

    chassis.set_turn_pid(-44, 60); //turns to face platform 44
    chassis.wait_drive();

    start_lift_to(550, 100);
    wait(300);

    chassis.set_drive_pid(42, 80, true); //drives to the platform
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, -32, 60); //swings to adjust with platform
    chassis.wait_drive();

    chassis.set_drive_pid(2.5, 80, true); //drives to the platform
    chassis.wait_drive();

    // lift_to(530, 100);

    wait(100);

    claw_open();

    // ----------------------------------------------------------------------
    // first neutral scored on plat

    lift_to(450, 100);

    chassis.set_drive_pid(-20, 80, true);
    chassis.wait_until(-5);
    start_lift_to(-3, 100);
    wait(1000);
    mogo_down(mogo_down_speed);

    chassis.wait_drive();

    // stoped here

    // alliance goal has been droped
    chassis.set_drive_pid(7.5, 85, true); //drives away from mogo
    chassis.wait_drive();
    start_mogo_up();
    wait(400);

    chassis.set_turn_pid(145, 90); //spins to face mogo
    chassis.wait_drive();

    chassis.set_drive_pid(9, 60, true); //drives into mogo
    chassis.wait_drive();

    claw_close();
    wait(200);

    lift_to(540, 100);

    chassis.set_turn_pid(-25, 65);
    chassis.wait_drive();

    chassis.set_drive_pid(22, 80, true);
    chassis.wait_drive();

    claw_open();
    wait(300);

    chassis.set_drive_pid(-3, 80, true);
    chassis.wait_drive();

    // // --------------------------------------------------------------
    // // alliance picked up and scored on platform (80)

    chassis.set_turn_pid(-90, 90);
    chassis.wait_drive();

    chassis.set_drive_pid(-37, 90, true);
    start_lift_to(-3, 100);

    chassis.wait_drive();

    chassis.set_turn_pid(-42, 80);
    chassis.wait_drive();

    chassis.set_drive_pid(15, 60, true);
    chassis.wait_drive();

    claw_close();


    // grabs alliance goal near platform


    chassis.set_drive_pid(-3, 70, true);
    chassis.wait_drive();

    lift_to(155, 100);

    chassis.set_swing_pid(ez::RIGHT_SWING, 8, 70);
    chassis.wait_drive();

    chassis.set_drive_pid(-60, 90, true);
    chassis.wait_drive();

    chassis.set_turn_pid(-141, 70);
    chassis.wait_until(-100);
    chassis.set_max_speed(60);

    chassis.wait_drive();

    start_lift_to(600, 100);
    wait(300);

    chassis.set_drive_pid(33, 70, true);
    chassis.wait_until(24);
    chassis.set_max_speed(50);
    chassis.wait_drive();

    lift_to(405, 100);

    claw_open();
    wait(500);

    // // ----------------------------------------------------------------
    // // 2rd alliance mogo scored on plat (120)

    start_lift_to(500, 100);
    wait(400);

    chassis.set_drive_pid(-21, 90, true);

    // chassis.wait_until(-12);
    // start_lift_to(0, 100);
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(-45, 90);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(100, 90, true);
    // chassis.wait_until(23);
    // claw_close();
    //
    // start_lift_to(140, 100);
    //
    // chassis.wait_drive();
    //
    // start_lift_to(10, 100);
    //
    // wait(1200);
    // claw_open();
    //
    // // // ------------------------------------------------------------------
    // // // tall yellow scored in zone (140)
    //
    // chassis.set_drive_pid(-17.5, 90, true);
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(90, 100);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(-19, 55);
    // chassis.wait_drive();
    //
    // tilter_up();
    //
    //
    // // alliance goal picked up with tilter
    //
    //
    // chassis.set_drive_pid(18, 80);
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(180, 90);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(41, 70);
    // chassis.wait_until(24);
    // claw_close();
    //
    // chassis.set_max_speed(55);
    //
    // start_lift_to(155, 100);
    //
    //
    // // yellow goal picked up while driving forward
    //
    //
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(140, 60);
    // chassis.wait_drive();
    //
    // start_lift_to(480, 100);
    // wait(200);
    //
    // chassis.set_drive_pid(43, 80);
    // chassis.wait_until(30);
    // chassis.set_max_speed(60);
    //
    // chassis.wait_drive();
    //
    // start_lift_to(450, 100);
    // wait(300);
    // claw_open();
    //
    // //3rd yellow goal has been scored on close platform
    // chassis.set_drive_pid(-21, 80, true);
    // chassis.wait_until(-5);
    // start_lift_to(0, 90);
    // tilter_down();
    //
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(8, 85, true); //drives away from mogo
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(-39, 95); //spins to face mogo
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(8, 65, true); //drives into mogo
    // chassis.wait_drive();
    //
    // claw_close();
    // wait(200);
    //
    // lift_to(485, 100);
    //
    // chassis.set_turn_pid(-217, 55);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(20, 60);
    // chassis.wait_drive();
    //
    // claw_open();
    // wait(100);
    // start_lift_to(530, 100);
    //
    // //3rd alliance mogo has been scored on close platform
    // chassis.set_drive_pid(-2, 110, true);
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(-271, 90);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(-36, 110, true);
    // start_lift_to(0, 100);
    //
    // chassis.wait_drive();
    //
    // chassis.set_turn_pid(-223, 90);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(22.5, 60, true);
    // chassis.wait_drive();
    //
    // claw_close();
    //
    //
    // // grabs alliance goal near platform
    // chassis.set_drive_pid(-3, 70, true);
    // chassis.wait_drive();
    //
    // lift_to(155, 100);
    //
    // chassis.set_swing_pid(ez::RIGHT_SWING, -175, 80);
    // chassis.wait_drive();
    //
    // chassis.set_drive_pid(-60, 120, true);
    // chassis.wait_drive();
    //
    //
    // chassis.set_turn_pid(-328, 70);
    // chassis.wait_until(-100);
    // chassis.set_max_speed(60);
    //
    // chassis.wait_drive();
    //
    // start_lift_to(530, 100);
    // wait(400);
    //
    // chassis.set_drive_pid(29, 70, true);
    // chassis.wait_until(24);
    // chassis.set_max_speed(50);
    // chassis.wait_drive();
    //
    // lift_to(410, 80);
    //
    // claw_open();
    //
    // chassis.set_drive_pid(-10, 10, true);
    // chassis.wait_drive();

}
//

//
