// main.cpp

#include "transport.hpp"

int main() {
    Wheel carWheel(16, 205, 55);
    Wheel motorcycleWheel(18, 120, 60);
    Wheel bicycleWheel(26, 2, 1);
    Wheel busWheel(22, 250, 70);

    Engine carEngine(300, "Gasoline", 2000);
    Engine motorcycleEngine(150, "Gasoline", 1000);
    Engine bicycleEngine(1, "Muscle Power", 0);
    Engine busEngine(250, "Diesel", 5000);

    LightingSystem carLights;
    LightingSystem motorcycleLights;
    LightingSystem bicycleLights;
    LightingSystem busLights;

    Car myCar(200, 4, carWheel, carEngine, carLights, 4, "Sedan");
    myCar.move();
    myCar.openDoors();
    myCar.startEngine();
    myCar.turnOnHeadlights();
    myCar.turnOnBrakeLights();
    myCar.useTurnSignals();

    Motorcycle myMotorcycle(120, 2, motorcycleWheel, motorcycleEngine, motorcycleLights, "Sport", 2);
    myMotorcycle.move();
    myMotorcycle.lean();
    myMotorcycle.turnOnHeadlights();
    myMotorcycle.turnOnBrakeLights();
    myMotorcycle.useTurnSignals();
    myMotorcycle.startEngine();

    Bicycle myBicycle(25, 1, bicycleWheel, bicycleEngine, bicycleLights, "Mountain", 21);
    myBicycle.move();
    myBicycle.pedal();

    Bus myBus(80, 40, busWheel, busEngine, busLights, 30, "Regular", "Public");
    myBus.move();
    myBus.boardPassengers();
    myBus.followSchedule();
    myBus.turnOnHeadlights();
    myBus.turnOnBrakeLights();
    myBus.useTurnSignals();

    return 0;
}
