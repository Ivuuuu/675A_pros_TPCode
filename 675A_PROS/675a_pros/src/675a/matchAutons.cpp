#include "main.h"

const int DRIVE_SPEED = 122;
void rightYellowAuton(void)
{
  chassis.set_drive_pid(40.1, DRIVE_SPEED, true);
  chassis.wait_drive();

  claw_open();
}
//   // task::sleep(1000);
//
//   claw_close();
//   // task::sleep(500);
//
//   //set_drive_pid(drive, X, DRIVE_SPEED, true);
//   //  desiredVal = -600;
//   //set_drive_pid(drive, X, DRIVE_SPEED, true);
//   // wait_drive();
//
//   //claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
//
//   //desiredVal = -300;
//   chassis.wait_drive();
//
//   desiredVal = 0;
//   turnDesiredVal = -92; //-80
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   desiredVal = 1100;
//   chassis.wait_drive();
//
//   claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   desiredVal = -900;
//   chassis.wait_drive();
//
//   claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   mogo.startRotateTo(940, rotationUnits::deg, 100, velocityUnits::pct);
//   lift.startRotateTo(150, rotationUnits::deg, 100, velocityUnits::pct);
//
//   desiredVal = 0;
//   turnDesiredVal = -170;
//   mogo.startRotateTo(940, rotationUnits::deg, 100, velocityUnits::pct);
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   desiredVal = -500;
//   chassis.wait_drive();
// }
//
// void rightRingAuton(void) {
//   turnSlow = 0.7;
//   turnDesiredVal = -140;
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   turnSlow = 1;
//   resetDriveSensors = true;
//   desiredVal = -650;
//   chassis.wait_drive();
//
//   mogo.startRotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//   mogo.startRotateTo(-5, rotationUnits::deg, 100, velocityUnits::pct);
//
//   resetDriveSensors = true;
//   desiredVal = 550;
//   chassis.wait_drive();
//
//   desiredVal = 0;
//   resetDriveSensors = true;
//   turnDesiredVal = -245;
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   resetDriveSensors = true;
//   desiredVal = 1250;
//   claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
//   chassis.wait_drive();
//
//   claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   resetDriveSensors = true;
//   desiredVal = -900;
//   chassis.wait_drive();
// }
//
// void rightRingMidAuton(void)
// {
//   turnSlow = 0.7;
//   turnDesiredVal = -140;
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   turnSlow = 1;
//   resetDriveSensors = true;
//   desiredVal = -600;
//   chassis.wait_drive();
//
//   mogo.startRotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//   mogo.startRotateTo(-5, rotationUnits::deg, 100, velocityUnits::pct);
//
//   resetDriveSensors = true;
//   desiredVal = 500;
//   chassis.wait_drive();
//
//   desiredVal = 0;
//   resetDriveSensors = true;
//   turnDesiredVal = -245;
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   resetDriveSensors = true;
//   desiredVal = 1250;
//   claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
//   chassis.wait_drive();
//
//   claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   resetDriveSensors = true;
//   desiredVal = -750;
//   chassis.wait_drive();
//
//   claw.startRotateTo(-300, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   resetDriveSensors = true;
//   desiredVal = -400;
//   chassis.wait_drive();
//
//   desiredVal = 0;
//   resetDriveSensors = true;
//   turnDesiredVal = -85;
//   chassis.wait_drive();
//
//   turnDesiredVal = 0;
//   resetDriveSensors = true;
//   desiredVal = 1000;
//   chassis.wait_drive();
//
//   claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   resetDriveSensors = true;
//   desiredVal = -800;
//   chassis.wait_drive();
// }
//
// void leftYellowAuton(void)
// {
//   desiredVal = 1050;
//   claw.startRotateTo(-300, rotationUnits::deg, 90, velocityUnits::pct);
//   chassis.wait_drive();
//
//   claw.startRotateTo(-160, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//
//   resetDriveSensors = true;
//   desiredVal = -600;
//   chassis.wait_drive();
// }
//
// void leftRingMidAuton(void) {
//   desiredVal = -300;
//   claw.startRotateTo(-300, rotationUnits::deg, 90, velocityUnits::pct);
//   task::sleep(1000);
//
//   mogo.startRotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
//   task::sleep(500);
//   mogo.startRotateTo(-5, rotationUnits::deg, 100, velocityUnits::pct);
//
//   resetDriveSensors = true;
//   desiredVal = 300;
//   claw.startRotateTo(-300, rotationUnits::deg, 90, velocityUnits::pct);
//   task::sleep(1000);
//
//   desiredVal = 0;
//   resetDriveSensors = true;
//   turnDesiredVal = -280;
//   task::sleep(1000);
//
//   turnDesiredVal = 0;
//   resetDriveSensors = true;
//   desiredVal = 1200;
//   task::sleep(1500);
//
//   claw.startRotateTo(-160, rotationUnits::deg, 90, velocityUnits::pct);
//   task::sleep(500);
//
//   resetDriveSensors = true;
//   desiredVal = -900;
//   task::sleep(1500);
// }
//
// void test(void)
// {
//   resetDriveSensors = true;
//   desiredVal = 400;
//   task::sleep(1000);
//
//   //desiredVal = 0;
//   //resetDriveSensors = true;
//   //turnDesiredVal = 200;
//   //task::sleep(1000);
// }
//
// void test2(void)
// {
//   D.rotateFor(fwd, 400, degrees);
// }
//
// void scrapAuton(void)
// {
//   task::sleep(100);
// }
