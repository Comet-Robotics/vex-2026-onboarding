#pragma once

// other includes

#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "util/PID.h"
#include <cmath>

class Drivebase
{
public:
    Drivebase() : left_mg({8,
                           14,
                           -7,
                           -9}),
                  right_mg({-18,
                            -20,
                            17,
                            19}),
                  imu(5) {}

    void drive(int forward, int turn)
    {
        left_mg.move_voltage(forward + turn);
        right_mg.move_voltage(forward - turn);
    }

    void resetEncoders()
    {
        left_mg.tare_position();
        right_mg.tare_position();
    }

    void resetIMU()
    {
        imu.reset(true);
    }

    int getEncoderPosition()
    {
        int left_position = left_mg.get_position();
        int right_position = right_mg.get_position();
        return (left_position + right_position) / 2;
    }

    double getAngle()
    {
        return imu.get_heading();
    }

    void turnAngle(int targetAngle)
    {
        while (true)
        {
            double output = turnPID.calculate(targetAngle, getAngle()) * 12000;
            pros::lcd::set_text(2, "Output: " + std::to_string(output));
            drive(0, output); // Turn with PID output

            if (abs(targetAngle - getAngle()) < 1)
            {
                break;
            }

            pros::delay(20);
        }
    }

    void driveInches(double inches)
    {
        int targetPos = inches * (300 / (3.25 * 3.14));

        while (true)
        {
            double output = drivePID.calculate(targetPos, getEncoderPosition()) * 12000;
            drive(output, 0);

            if (abs(targetPos - getEncoderPosition() < 10))
            {
                break;
            }
            pros::delay(20);
        }
    }

private:
    pros::MotorGroup left_mg, right_mg;
    pros::IMU imu;
    PID drivePID{0.02, 0.08};
    PID turnPID{0.02, 0.08};
};