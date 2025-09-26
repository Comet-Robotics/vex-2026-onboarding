#pragma once

// other includes

#include "pros/imu.hpp"
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
        }), imu(5) {}

        void drive(int forward, int turn) {
            left_mg.move_voltage(forward + turn);
            right_mg.move_voltage(forward - turn);
        }

        void resetEncoders() {
            left_mg.tare_position();
            right_mg.tare_position();
        }

        void resetIMU() {
            imu.reset(true);
        }

        int getEncoderPosition() {
            int left_position = left_mg.get_position();
            int right_position = right_mg.get_position();
            return (left_position + right_position) / 2;
        }

        double getAngle() {
            return imu.get_heading();
        }

    private:
        pros::MotorGroup left_mg, right_mg;
        pros::IMU imu;
};