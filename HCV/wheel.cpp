// wheel.cpp

#include "wheel.hpp"

Wheel::Wheel(int r, int w, int h) : radius(r), width(w), height(h) {}

void Wheel::rotate() {
    std::cout << "The wheel is rotating.\n";
}
