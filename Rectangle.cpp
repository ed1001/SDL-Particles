//
// Created by Edward Phillips on 05/12/2022.
//

#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(SDL_Renderer *_renderer, int _height, int _width, int _x, int _y, int _screen_height,
                     int _screen_width) {
    height = _height;
    width = _width;
    x = _x;
    y = _y;
    rect = SDL_Rect{x, y, width, height};
    renderer = _renderer;
    screen_height = _screen_height;
    screen_width = _screen_width;
}

void Rectangle::draw() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Rectangle::animate() {
    draw();
    x += x_dir ? ani_increment : -ani_increment;
    y += y_dir ? ani_increment : -ani_increment;
    rect.x = x;
    rect.y = y;

    int x_edge = x_dir ? x + width : x;
    int y_edge = y_dir ? y + height : y;

    bool change_x = x_dir ? x_edge > screen_width : x_edge < 0;
    bool change_y = y_dir ? y_edge > screen_height : y_edge < 0;
    if (change_x) {
        x_dir = !x_dir;
    }
    if (change_y) {
        y_dir = !y_dir;
    }
}


