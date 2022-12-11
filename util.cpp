//
// Created by Edward Phillips on 11/12/2022.
//

#include "util.h"

double ed::getRand(double rangeStart, double rangeEnd) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<double> distr(rangeStart, rangeEnd);

    return distr(gen);
}
