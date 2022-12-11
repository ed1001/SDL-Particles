//
// Created by Edward Phillips on 11/12/2022.
//

#ifndef UNTITLED_PARTICLE_H
#define UNTITLED_PARTICLE_H


#include "util.h"

class Particle {
public:
    Particle();

    double x;
    double y;
    struct Velocity {
        double v;
        double x;
        double y;
    };
    Velocity velocity;
    double direction;

private:
    int min_velocity = -1000;
    int max_velocity = 1000;
};


#endif //UNTITLED_PARTICLE_H
