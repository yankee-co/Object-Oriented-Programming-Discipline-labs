// engine.hpp

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>

class Engine {
public:
    int power;
    std::string fuelType;
    int displacement;

    Engine(int p, const std::string& fuel, int d);
    void start();
    void stop();
};

#include "engine.cpp"

#endif // ENGINE_HPP
