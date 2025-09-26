#pragma once

class PID {
private:
    double kP, kD, previousError = 0.0;

public:
    PID(double kP, double kD)
        : kP(kP), kD(kD) {}

    void setConstants(double kP, double kD) {
        this->kP = kP;
        this->kD = kD;
    }

    double calculate(double setpoint, double measuredValue) {
        double error = setpoint - measuredValue;
        double output = (kP * error) + (kD * (error - previousError));

        previousError = error;
        
        return output;
    }
};