//
// Created by Edward Phillips on 11/12/2022.
//

#pragma once

#include "util.h"
#include "Particle.h"

class Swarm {
public:
    static const int N_PARTICLES = 5000;
    static const bool BOUNCE = false;
    static const bool RENDER_TAIL = false;
    Particle *particles;

public:
    explicit Swarm();

    virtual ~Swarm();

    void animate() const;
};
