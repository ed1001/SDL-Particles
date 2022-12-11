//
// Created by Edward Phillips on 11/12/2022.
//

#include "Particle.h"

Particle::Particle() {
    x = ed::SCREEN_WIDTH / 2;
    y = ed::SCREEN_HEIGHT / 2;
    direction = M_PI * 2 * random() / RAND_MAX;
    velocity.v = ed::getRand(min_velocity, max_velocity) * 0.001;
    velocity.x = velocity.v * cos(direction);
    velocity.y = velocity.v * sin(direction);
}
