//
// Created by Edward Phillips on 05/12/2022.
//

#ifndef UNTITLED_SCREEN_H
#define UNTITLED_SCREEN_H

#include <SDL.h>

class Screen {
public:
    Screen(int height_, int width_);

    ~Screen();

    void clear() const;

    bool processEvents();

    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const;

    SDL_Renderer *renderer = nullptr;
    SDL_Texture *texture = nullptr;
    Uint32 *pixelBuffer = nullptr;

private:
    void update() const;

    int height;
    int width;
    SDL_Window *window = nullptr;
    SDL_Event event{};
};

#endif //UNTITLED_SCREEN_H
