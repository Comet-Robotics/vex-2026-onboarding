#pragma once

class PID {
private:
    double kP;

public:
    PID(double kP)
        : kP(kP) {}

    void setConstants(double kP, double kI, double kD) {
        this->kP = kP;
    }

    double calculate(double setpoint, double measuredValue) {
        double error = setpoint - measuredValue;
        double output = (kP * error);
        
        return output;
    }
};