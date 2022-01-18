#include "main.h"

// constructors are (port, gearset, reverse, encoder_units)
pros::Motor mogo = pros::Motor(14);
pros::Motor lift = pros::Motor(11);
pros::Motor conveyor = pros::Motor(10);
pros::Motor claw = pros::Motor(19);

pros::ADIDigitalOut clamp('G', false);
