// transport.cpp

#include "transport.hpp"

Car::Car(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, int doors, const std::string& body)
    : Vehicle(speed, capacity, wheel, engine, lights), numberOfDoors(doors), bodyType(body) {}

void Car::openDoors() {
    std::cout << "Opening the car doors.\n";
}

void Car::startEngine() {
    std::cout << "Starting the car engine.\n";
    vehicleEngine.start();
}

void Car::turnOnHeadlights() {
    vehicleLights.turnOnHeadlights();
}

void Car::turnOnBrakeLights() {
    vehicleLights.turnOnBrakeLights();
}

void Car::useTurnSignals() {
    vehicleLights.useTurnSignals();
}

Motorcycle::Motorcycle(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, const std::string& bikeType, int numWheels)
    : Vehicle(speed, capacity, wheel, engine, lights), type(bikeType), wheels(numWheels) {}

void Motorcycle::lean() {
    std::cout << "Leaning the motorcycle into a turn.\n";
}

void Motorcycle::startEngine() {
    std::cout << "Starting the motorcycle engine.\n";
    vehicleEngine.start();
}

void Motorcycle::turnOnHeadlights() {
    vehicleLights.turnOnHeadlights();
}

void Motorcycle::turnOnBrakeLights() {
    vehicleLights.turnOnBrakeLights();
}

void Motorcycle::useTurnSignals() {
    vehicleLights.useTurnSignals();
}

Bicycle::Bicycle(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, const std::string& type, int speeds)
    : Vehicle(speed, capacity, wheel, engine, lights), bikeType(type), numberOfSpeeds(speeds) {}

void Bicycle::pedal() {
    std::cout << "Pedaling the bicycle.\n";
}

Bus::Bus(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, int seats, const std::string& busSchedule, const std::string& transportType)
    : Vehicle(speed, capacity, wheel, engine, lights), numberOfSeats(seats), schedule(busSchedule), transportationType(transportType) {}

void Bus::boardPassengers() {
    std::cout << "Boarding passengers onto the bus.\n";
}

void Bus::followSchedule() {
    std::cout << "Following the bus schedule.\n";
}

void Bus::turnOnHeadlights() {
    vehicleLights.turnOnHeadlights();
}

void Bus::turnOnBrakeLights() {
    vehicleLights.turnOnBrakeLights();
}

void Bus::useTurnSignals() {
    vehicleLights.useTurnSignals();
}
