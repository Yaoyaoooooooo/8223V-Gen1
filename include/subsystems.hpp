#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

inline pros::MotorGroup Lift({1,-7},pros::MotorGearset::green);
inline pros::Motor Roller(9,pros::MotorGearset::green);
inline pros::Motor Intake(21,pros::MotorGearset::green);
inline pros::adi::Pneumatics claw('H', false);
