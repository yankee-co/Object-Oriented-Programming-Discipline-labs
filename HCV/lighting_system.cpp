// lighting_system.cpp

#include "lighting_system.hpp"

LightingSystem::LightingSystem() : headlights(false), brakeLights(false), turnSignals(false) {}

void LightingSystem::turnOnHeadlights() {
    headlights = true;
    std::cout << "Headlights are turned on.\n";
}

void LightingSystem::turnOnBrakeLights() {
    brakeLights = true;
    std::cout << "Brake lights are turned on.\n";
}

void LightingSystem::useTurnSignals() {
    turnSignals = true;
    std::cout << "Turn signals are in use.\n";
}
