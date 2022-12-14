//
// Created by Edward Phillips on 11/12/2022.
//

#include "Swarm.h"

Swarm::Swarm() {
    particles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() = default;

void Swarm::animate() const {
    for (int i = 0; i < N_PARTICLES; ++i) {
        util::Position &position = particles[i].position;
        util::Velocity &velocity = particles[i].velocity;
        std::vector<util::Position> &tail = particles[i].tail;
        tail.push_back({.x =  position.x, .y =  position.y});

        if (tail.size() > Particle::TAIL_LENGTH) {
            rotate(tail.begin(), tail.begin() + 1, tail.end());
            tail.pop_back();
        }

        position.x += velocity.x;
        position.y += velocity.y;

        bool outOfXBounds = position.x < 0 || position.x > util::SCREEN_WIDTH;
        bool outOfYBounds = position.y < 0 || position.y > util::SCREEN_HEIGHT;

        if (outOfXBounds) {
            velocity.x = -velocity.x;
            position.x += velocity.x * 2;
        }
        if (outOfYBounds) {
            velocity.y = -velocity.y;
            position.y += velocity.y * 2;
        }
    }
}
