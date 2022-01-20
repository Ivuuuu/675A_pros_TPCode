#include "main.h"

// variables
bool clamp_current_state = false;

int mogo_start_pos = 0;   // check with bbao
int mogo_mid_pos = 175;
int mogo_bottom_pos = 497;

const int DRIVE_SPEED = 122;

void rightYellowAuton(void)
{
  chassis.set_drive_pid(40.1, DRIVE_SPEED, true);
  chassis.wait_drive();

  claw_open();
  // task::sleep(1000);

  claw_close();
  // task::sleep(500);

  //set_drive_pid(drive, X, DRIVE_SPEED, true);
  //  desiredVal = -600;
  //set_drive_pid(drive, X, DRIVE_SPEED, true);
  // wait_drive();

  //claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);

  //desiredVal = -300;
  chassis.wait_drive();

  desiredVal = 0;
  turnDesiredVal = -92; //-80
  chassis.wait_drive();

  turnDesiredVal = 0;
  desiredVal = 1100;
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  desiredVal = -900;
  chassis.wait_drive();

  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  mogo.startRotateTo(940, rotationUnits::deg, 100, velocityUnits::pct);
  lift.startRotateTo(150, rotationUnits::deg, 100, velocityUnits::pct);

  desiredVal = 0;
  turnDesiredVal = -170;
  mogo.startRotateTo(940, rotationUnits::deg, 100, velocityUnits::pct);
  chassis.wait_drive();

  turnDesiredVal = 0;
  desiredVal = -500;
  chassis.wait_drive();
}

void rightRingAuton(void) {
  turnSlow = 0.7;
  turnDesiredVal = -140;
  chassis.wait_drive();

  turnDesiredVal = 0;
  turnSlow = 1;
  resetDriveSensors = true;
  desiredVal = -650;
  chassis.wait_drive();

  mogo.startRotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);
  mogo.startRotateTo(-5, rotationUnits::deg, 100, velocityUnits::pct);

  resetDriveSensors = true;
  desiredVal = 550;
  chassis.wait_drive();

  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = -245;
  chassis.wait_drive();

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = 1250;
  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -900;
  chassis.wait_drive();
}

void rightRingMidAuton(void)
{
  turnSlow = 0.7;
  turnDesiredVal = -140;
  chassis.wait_drive();

  turnDesiredVal = 0;
  turnSlow = 1;
  resetDriveSensors = true;
  desiredVal = -600;
  chassis.wait_drive();

  mogo.startRotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);
  mogo.startRotateTo(-5, rotationUnits::deg, 100, velocityUnits::pct);

  resetDriveSensors = true;
  desiredVal = 500;
  chassis.wait_drive();

  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = -245;
  chassis.wait_drive();

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = 1250;
  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -750;
  chassis.wait_drive();

  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -400;
  chassis.wait_drive();

  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = -85;
  chassis.wait_drive();

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = 1000;
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -800;
  chassis.wait_drive();
}

void leftYellowAuton(void)
{
  desiredVal = 1050;
  claw.startRotateTo(-300, rotationUnits::deg, 90, velocityUnits::pct);
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -600;
  chassis.wait_drive();
}

void leftRingMidAuton(void) {
  desiredVal = -300;
  claw.startRotateTo(-300, rotationUnits::deg, 90, velocityUnits::pct);
  task::sleep(1000);

  mogo.startRotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);
  mogo.startRotateTo(-5, rotationUnits::deg, 100, velocityUnits::pct);

  resetDriveSensors = true;
  desiredVal = 300;
  claw.startRotateTo(-300, rotationUnits::deg, 90, velocityUnits::pct);
  task::sleep(1000);

  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = -280;
  task::sleep(1000);

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = 1200;
  task::sleep(1500);

  claw.startRotateTo(-160, rotationUnits::deg, 90, velocityUnits::pct);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -900;
  task::sleep(1500);
}

void skillAuton(void)
{
  desiredVal = 10;
  chassis.wait_drive();

  //get first mogo
  mogo.startRotateTo(1085, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  resetDriveSensors = true;
  desiredVal = -350;
  chassis.wait_drive();

  mogo.startRotateTo(-15, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1100);

  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = -245;  //-245
  chassis.wait_drive();

  //turn towards side yellow mogo, open claw, and grab mogo
  turnDesiredVal = 0;
  resetDriveSensors = true;
  driveSlow = .8;
  desiredVal = 1120;
  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(500);

  //turn towards platform and lift up with mogo in claw
  desiredVal = 0;
  driveSlow = 1;
  resetDriveSensors = true;
  turnSlow = .5;
  turnDesiredVal = -78;
  chassis.wait_drive();

  lift.startRotateTo(680, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1500);

  turnDesiredVal = 0;
  turnSlow = 1;
  resetDriveSensors = true;
  desiredVal = 1320;
  chassis.wait_drive();

  //small movements to score the yellow mogo on plat and drop mogo on plat
  desiredVal = 0;
  driveSlow = 1;
  resetDriveSensors = true;
  turnSlow = .5;
  turnDesiredVal = 60;
  chassis.wait_drive();

  lift.startRotateTo(450, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(700);

  //back up from plat and turn away
  turnDesiredVal = 0;
  turnSlow = 1;
  resetDriveSensors = true;
  desiredVal = -400;
  chassis.wait_drive();

  desiredVal = 0;
  driveSlow = 1;
  resetDriveSensors = true;
  turnDesiredVal = 212;
  chassis.wait_drive();

  //lift down and drop first mogo off
  lift.startRotateTo(-10, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1200);

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = -300;
  chassis.wait_drive();

  resetDriveSensors = true;
  desiredVal = 300;
  chassis.wait_drive();

  mogo.startRotateTo(1085, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  //move towards and grabs side mogo
  resetDriveSensors = true;
  desiredVal = 1000;
  chassis.wait_drive();

  claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(700);

  //back up, lift up, and turn towards plat wall
  resetDriveSensors = true;
  desiredVal = -190;
  chassis.wait_drive();

  lift.startRotateTo(550, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = -205;
  chassis.wait_drive();

  //runs into the wall to readjust itself
  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = 870;
  chassis.wait_drive();

  //backs up and bring lift down (not completely)
  resetDriveSensors = true;
  desiredVal = -400;
  chassis.wait_drive();

  lift.startRotateTo(80, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  resetDriveSensors = true;
  desiredVal = -150;
  chassis.wait_drive();

  //lift.startRotateTo(80, rotationUnits::deg, 100, velocityUnits::pct);
  ///task::sleep(1000);

  //turn towards tall yellow mogo and drives to opposite corner
  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = 112;
  chassis.wait_drive();

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = -2700;
  chassis.wait_drive();

  //moves away from corner a little to allow for turn
  resetDriveSensors = true;
  desiredVal = 400;
  chassis.wait_drive();

  // turn mogo lift towards other side yellow mogo
  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = 280;
  chassis.wait_drive();

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = -10;
  chassis.wait_drive();

  //drops side mogo off and drives backwards to push other side yellow mogo into zone
  claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(700);

  resetDriveSensors = true;
  desiredVal = -1000;
  chassis.wait_drive();

  /*
  desiredVal = 0;
  resetDriveSensors = true;
  turnDesiredVal = 90;
  task::sleep(800);

  turnDesiredVal = 0;
  resetDriveSensors = true;
  desiredVal = -2000;
  task::sleep(2500);

  */
}

void test(void)
{
  resetDriveSensors = true;
  desiredVal = 400;
  task::sleep(1000);

  //desiredVal = 0;
  //resetDriveSensors = true;
  //turnDesiredVal = 200;
  //task::sleep(1000);
}

void test2(void)
{
  D.rotateFor(fwd, 400, degrees);
}

void scrapAuton(void)
{
  task::sleep(100);
}
