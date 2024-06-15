// transport.hpp

#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP

#include <iostream>
#include <string>

#include "vehicle.hpp"

class Car : public Vehicle {
public:
    int numberOfDoors;
    std::string bodyType;

    Car(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, int doors, const std::string& body);
    void openDoors();
    void startEngine();
    void turnOnHeadlights();
    void turnOnBrakeLights();
    void useTurnSignals();
};

class Motorcycle : public Vehicle {
public:
    std::string type;
    int wheels;

    Motorcycle(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, const std::string& bikeType, int numWheels);
    void lean();
    void startEngine();
    void turnOnHeadlights();
    void turnOnBrakeLights();
    void useTurnSignals();
};

class Bicycle : public Vehicle {
public:
    std::string bikeType;
    int numberOfSpeeds;

    Bicycle(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, const std::string& type, int speeds);
    void pedal();
};

class Bus : public Vehicle {
public:
    int numberOfSeats;
    std::string schedule;
    std::string transportationType;

    Bus(int speed, int capacity, const Wheel& wheel, const Engine& engine, const LightingSystem& lights, int seats, const std::string& busSchedule, const std::string& transportType);
    void boardPassengers();
    void followSchedule();
    void turnOnHeadlights();
    void turnOnBrakeLights();
    void useTurnSignals();
};
#include "transport.cpp"

#endif // TRANSPORT_HPP
