//
// Created by Edward Phillips on 05/12/2022.
//

#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H

#include <SDL.h>

struct BoundsBreached {
    bool x;
    bool y;
};

class Rectangle {
public:
    Rectangle(SDL_Renderer *_renderer, int _height, int _width, int _x, int _y, int _screen_height,
              int _screen_width);;

    void draw();

    void animate();

private:
    SDL_Renderer *renderer;
    SDL_Rect rect;
    int height;
    int width;
    int x;
    int y;
    int screen_height;
    int screen_width;
    int ani_increment = 40;
    bool x_dir = true;
    bool y_dir = true;
    BoundsBreached boundsBreached{false, false};
};


#endif //UNTITLED_RECTANGLE_H
