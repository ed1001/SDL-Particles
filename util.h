//
// Created by Edward Phillips on 11/12/2022.
//

#pragma once
#include <random>

namespace util {
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 900;

    struct Position {
        double x;
        double y;
    };
    struct Velocity {
        double v;
        double x;
        double y;
    };

    double getRand(double rangeStart, double rangeEnd);

    bool outOfBounds(int x, int y, int width, int height);
}
