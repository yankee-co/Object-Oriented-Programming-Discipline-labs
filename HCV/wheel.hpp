// wheel.hpp

#ifndef WHEEL_HPP
#define WHEEL_HPP

#include <iostream>
#include <string>

class Wheel {
public:
    int radius;
    int width;
    int height;

    Wheel(int r, int w, int h);
    void rotate();
};

#include "wheel.cpp"

#endif // WHEEL_HPP
