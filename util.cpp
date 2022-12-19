//
// Created by Edward Phillips on 11/12/2022.
//

#include "util.h"

double util::getRand(double rangeStart, double rangeEnd) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<double> distr(rangeStart, rangeEnd);

    return distr(gen);
}

bool util::outOfBounds(int x, int y, int width, int height) {
    return x < 0 || x > width || y < 0 || y > height;
}
