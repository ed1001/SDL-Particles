//
// Created by Edward Phillips on 11/12/2022.
//

#include "Swarm.h"
#include "util.h"

Swarm::Swarm(int nParticles) {
    this->nParticles = nParticles;
    particles = new Particle[nParticles];
}

Swarm::~Swarm() {

}

void Swarm::animate() {
    for (int i = 0; i < nParticles; ++i) {
        Particle *p = &particles[i];
        p->x += p->velocity.x;
        p->y += p->velocity.y;
        bool outOfXBounds = p->x < 0 || p->x > ed::SCREEN_WIDTH;
        bool outOfYBounds = p->y < 0 || p->y > ed::SCREEN_HEIGHT;

        if (outOfXBounds) {
            p->velocity.x = -p->velocity.x;
            p->x += p->velocity.x * 2;
        }
        if (outOfYBounds) {
            p->velocity.y = -p->velocity.y;
            p->y += p->velocity.y * 2;
        }
    }
}
