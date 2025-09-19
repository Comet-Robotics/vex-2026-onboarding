#pragma once

#include "subsystems/drivebase.h"

inline Drivebase *drivebase = nullptr;

inline void subsystems_initialize() {
    drivebase = new Drivebase();
}