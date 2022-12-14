//
// Created by Edward Phillips on 11/12/2022.
//

#include "Particle.h"

Particle::Particle() {
    position.x = util::SCREEN_WIDTH / 2;
    position.y = util::SCREEN_HEIGHT / 2;
    direction = M_PI * 2 * random() / RAND_MAX;
    velocity.v = util::getRand(min_velocity, max_velocity) * 0.001;
    velocity.x = velocity.v * cos(direction);
    velocity.y = velocity.v * sin(direction);
}
