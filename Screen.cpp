//
// Created by Edward Phillips on 05/12/2022.
//

#include <iostream>
#include "Screen.h"

Screen::Screen(int height, int width) : m_height(height), m_width(width) {
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow("SDL Particles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height,
                                SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, m_width, m_height);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    pixelBuffer = new Uint32[m_width * m_height];
    SDL_RenderClear(renderer);
    clear();
}

Screen::~Screen() {
    std::cout << "quitting SDL..." << std::endl;
    delete[] pixelBuffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Screen::update() const {
    SDL_RenderClear(renderer);
    SDL_UpdateTexture(texture, nullptr, pixelBuffer, m_width * sizeof(Uint32));
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    clear();
}

bool Screen::processEvents() {
    SDL_PollEvent(&m_event);

    return m_event.type != SDL_QUIT;
}

void Screen::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const {
    int pixelBufferIndex = x + y * m_width;

    if (pixelBufferIndex > m_width * m_height || pixelBufferIndex < 0) {
        return;
    }

    uint8_t colors[] = {r, g, b};
    Uint32 result = 0x00000000;

    for (uint8_t color: colors) {
        result += color;
        result <<= 8;
    }

    result += alpha;
    pixelBuffer[pixelBufferIndex] = result;
}

void Screen::clear() const {
    std::memset(pixelBuffer, 0x00, m_width * m_height * sizeof(Uint32));
}
