// engine.cpp

#include "engine.hpp"

Engine::Engine(int p, const std::string& fuel, int d) : power(p), fuelType(fuel), displacement(d) {}

void Engine::start() {
    std::cout << "The engine has started.\n";
}

void Engine::stop() {
    std::cout << "The engine has stopped.\n";
}
