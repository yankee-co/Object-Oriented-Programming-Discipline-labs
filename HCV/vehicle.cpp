#include "vehicle.hpp"

Vehicle::Vehicle(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights)
    : maxSpeed(speed), passengerCapacity(capacity), vehicleWheel(wheel), vehicleEngine(engine), vehicleLights(lights) {}

void Vehicle::move() {
    std::cout << "The vehicle is moving.\n";
}

void Vehicle::stop() {
    std::cout << "The vehicle has stopped.\n";
}