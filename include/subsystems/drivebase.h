#pragma once

// other includes

#include "pros/motor_group.hpp"

class Drivebase {
    public:
        Drivebase() : 
        left_mg({
            8, 
            14, 
            -7, 
            -9
        }), 
        right_mg({
            -18,
            -20,
            17,
            19
        }) {}

        void drive(int forward, int turn) {
            left_mg.move(forward + turn);
            right_mg.move(forward - turn);
        }

    private:
        pros::MotorGroup left_mg, right_mg;
};