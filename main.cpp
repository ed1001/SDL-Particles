#include <iostream>
#include "SDL.h"
#include "Screen.h"
#include "util.h"
#include "Swarm.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init failed" << std::endl;

        return 1;
    }

    Screen screen(util::SCREEN_HEIGHT, util::SCREEN_WIDTH);
    Swarm swarm;

    while (true) {
        auto red = (uint8_t) ((sin(SDL_GetTicks() * 0.001) + 1) * 128);
        auto green = (uint8_t) ((sin(SDL_GetTicks() * 0.0003) + 1) * 128);
        auto blue = (uint8_t) ((sin(SDL_GetTicks() * 0.0005) + 1) * 128);

        for (int i = 0; i < Swarm::N_PARTICLES; ++i) {
            Particle &particle = swarm.particles[i];
            util::Position &position = particle.position;
            std::vector<util::Position> &tail = particle.tail;

            screen.setPixel(int(position.x), int(position.y), red, green, 255);

            for (int j = 0; j < tail.size(); ++j) {
                int alpha = 255 / tail.size() * j;
                util::Position &tailPosition = tail[j];
                screen.setPixel(int(tailPosition.x), int(tailPosition.y), red, green, blue, alpha);
            }
        }

        screen.update();
        swarm.animate();

        if (!screen.processEvents()) break;
    }

    return 0;
}
