//
// Created by Edward Phillips on 11/12/2022.
//

#ifndef UNTITLED_SWARM_H
#define UNTITLED_SWARM_H

#include "util.h"
#include "Particle.h"

class Swarm {
public:
    int nParticles;
    Particle *particles;

public:
    explicit Swarm(int nParticles);

    virtual ~Swarm();

    void animate();

};


#endif //UNTITLED_SWARM_H
