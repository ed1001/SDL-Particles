//
// Created by Edward Phillips on 11/12/2022.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <random>

namespace util {
    const size_t SCREEN_WIDTH = 1200;
    const size_t SCREEN_HEIGHT = 900;

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
}

#endif //UNTITLED_UTIL_H
