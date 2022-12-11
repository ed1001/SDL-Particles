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

    Screen screen(ed::SCREEN_HEIGHT, ed::SCREEN_WIDTH);
    Swarm swarm(3000);

    while (true) {
        auto red = (uint8_t) ((sin(SDL_GetTicks() * 0.001) + 1) * 128);
        auto green = (uint8_t) ((sin(SDL_GetTicks() * 0.0003) + 1) * 128);
        auto blue = (uint8_t) ((sin(SDL_GetTicks() * 0.0005) + 1) * 128);
        swarm.animate();

        for (int i = 0; i < swarm.nParticles; ++i) {
            screen.setPixel(int(swarm.particles[i].x), int(swarm.particles[i].y), red, green, blue);
        }

        if (!screen.processEvents()) break;
    }

    return 0;
}
