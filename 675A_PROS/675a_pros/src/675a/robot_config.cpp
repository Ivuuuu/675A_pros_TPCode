#include "main.h"

// constructors are (port, gearset, reverse, encoder_units)
pros::Motor mogo(18, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
pros::Motor lift_l = pros::Motor(14, true);
pros::Motor lift_r = pros::Motor(19, false);
pros::Motor conveyor = pros::Motor(2);

pros::ADIDigitalOut clawADI('B', false);
