//
// Created by Edward Phillips on 11/12/2022.
//

#pragma once

#include "util.h"

class Particle {
public:
    static int const TAIL_LENGTH = 50;
    util::Position position;
    util::Velocity velocity;
    std::vector<util::Position> tail;
public:
    Particle();

private:
    double direction;
    int min_velocity = -1000;
    int max_velocity = 1000;
};

