#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "tasks/auton.h"
#include "subsystems.h"
#include "util/PID.h"

void autonomous_initialize()
{
    drivebase->resetEncoders();
    drivebase->resetIMU();
    pros::lcd::clear();
    pros::lcd::set_text(1, "Autonomous Initialized");
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Auton Control Initialized");

    drivebase->driveInches(24);
    drivebase->turnAngle(180);
    drivebase->driveInches(36);
    drivebase->turnAngle(45);
}