#include "api.h"

extern pros::Motor mogo;
extern pros::Motor lift;
extern pros::Motor claw;
extern pros::Motor conveyor;

extern pros::ADIDigitalOut clawADI; // pros::ADIDigitalOut::ADIDigitalOut ( std::uint8_t port, bool init_state = false )
                                  // sensor.set_value(bool state);
