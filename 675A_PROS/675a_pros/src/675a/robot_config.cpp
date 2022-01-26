#include "main.h"

// constructors are (port, gearset, reverse, encoder_units)
pros::Motor mogo(14, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
pros::Motor lift = pros::Motor(11);
pros::Motor conveyor = pros::Motor(10);
pros::Motor claw = pros::Motor(19);

pros::ADIDigitalOut clawADI('G', false);
