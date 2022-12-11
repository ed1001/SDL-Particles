//
// Created by Edward Phillips on 05/12/2022.
//

#include <iostream>
#include "Screen.h"

Screen::Screen(int _height, int _width) : height(_height), width(_width) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Ed's SDL program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height);
    pixelBuffer = new Uint32[width * height];
    SDL_RenderClear(renderer);
    clear();
}

Screen::~Screen() {
    std::cout << "quitting SDL..." << std::endl;
    delete[] pixelBuffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::update() const {
    // TODO use optimized version of update texture (look it up)
    SDL_RenderClear(renderer);
    SDL_UpdateTexture(texture, nullptr, pixelBuffer, width * sizeof(Uint32));
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    clear();
}

bool Screen::processEvents() {
    update();
    SDL_PollEvent(&event);

    return event.type != SDL_QUIT;
}

void Screen::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const {
    uint8_t colors[] = {r, g, b};
    Uint32 result = 0x00000000;

    for (uint8_t color: colors) {
        result += color;
        result <<= 8;
    }

    result += alpha;

    pixelBuffer[x + y * width] = result;
}

void Screen::clear() const {
    std::memset(pixelBuffer, 0x00, width * height * sizeof(Uint32));
}
