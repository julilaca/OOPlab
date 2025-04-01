#include "Car.h"

double Car::GetCurrentFuel() const {
    return currentFuel;
}

void Car::SetCurrentFuel(double fuel) {
    currentFuel = fuel;
}

bool Car::CanFinish(double circuitLength) const {
    double fuelNeeded = (circuitLength / 100) * fuelConsumption;
    return currentFuel >= fuelNeeded;
}

double Car::CalculateTime(double circuitLength, Weather weather) const {
    double speed = GetAverageSpeed(weather);
    return circuitLength / speed;
}
