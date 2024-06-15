// vehicle.hpp

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "wheel.hpp"
#include "engine.hpp"
#include "lighting_system.hpp"

class Vehicle {
public:
    int maxSpeed;
    int passengerCapacity;
    Wheel vehicleWheel;
    Engine vehicleEngine;
    LightingSystem vehicleLights;

    Vehicle(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights);
    void move();
    void stop();
};

#include "vehicle.cpp"

#endif // VEHICLE_HPP