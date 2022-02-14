#include "main.h"

// constructors are (port, gearset, reverse, encoder_units)
// blue = 600 rpm gearset_6
// green = 200 rpm gearset_18
// red = 100 rpm gearset_36
pros::Motor mogo(18, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
pros::Motor lift_l(14, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor lift_r(19, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor conveyor(2, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut clawADI('B', false);
