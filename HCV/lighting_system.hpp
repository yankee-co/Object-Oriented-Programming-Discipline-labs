// lighting_system.hpp

#ifndef LIGHTING_SYSTEM_HPP
#define LIGHTING_SYSTEM_HPP

#include <iostream>
#include <string>

class LightingSystem {
public:
    bool headlights;
    bool brakeLights;
    bool turnSignals;

    LightingSystem();
    void turnOnHeadlights();
    void turnOnBrakeLights();
    void useTurnSignals();
};

#include "lighting_system.cpp"

#endif // LIGHTING_SYSTEM_HPP
