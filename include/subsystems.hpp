#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

inline pros::MotorGroup Lift({21,-2, -19},pros::MotorGearset::green);
inline pros::Motor Roller(10,pros::MotorGearset::green);
inline pros::adi::Pneumatics claw('H', false);
inline pros::adi::Pneumatics left_wing('G', false);
inline pros::adi::Pneumatics right_wing('B', false);
inline pros::adi::Pneumatics knife('C', false);
inline pros::adi::Pneumatics holder('E', false);
inline pros::adi::DigitalIn touch('F');
inline pros::adi::DigitalIn touch_up('D');

inline double Lift_target = 0;
inline void Lift_move(int target, bool wait=true){
    target = target/2;
    Lift_target+=target;
    Lift.move_relative(target, 127);
    if (!wait) return;
    int start_time = pros::millis();
    while (std::fabs(Lift_target - Lift.get_position()) > 5.0) {
        if(pros::millis() - start_time > 1000)
            break;
        pros::delay(20);
    } 
}

inline void Lift_move_to(int target, bool wait=true){
    target = target/2;
    Lift_target=target;
    Lift.move_absolute(target, 127);
    if (!wait) return;
    int start_time = pros::millis();
    while (std::fabs(Lift_target - Lift.get_position()) > 5.0) {
        if(pros::millis() - start_time > 1000)
            break;
        pros::delay(20);
    } 
}