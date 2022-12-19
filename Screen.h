//
// Created by Edward Phillips on 05/12/2022.
//

#pragma once

#include <SDL.h>

class Screen {
private:
    int m_height;
    int m_width;
    SDL_Window *m_window = nullptr;
    SDL_Event m_event{};

public:
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *texture = nullptr;
    Uint32 *pixelBuffer = nullptr;
    Uint32 *blurBuffer = nullptr;

public:
    Screen(int height, int width);

    ~Screen();

    void clear() const;

    bool processEvents();

    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 0xff) const;

    void update() const;

    void boxBlur();
};

