#pragma once
#include "Weather.h"

class Car {
protected:
    double fuelCapacity;
    double fuelConsumption;
    double avgSpeedRain;
    double avgSpeedSunny;
    double avgSpeedSnow;
    double currentFuel;

public:
    virtual ~Car() = default;
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetAverageSpeed(Weather weather) const = 0;
    virtual const char* GetName() const = 0;

    double GetCurrentFuel() const { return currentFuel; }
    void SetCurrentFuel(double fuel) { currentFuel = fuel; }

    bool CanFinish(double circuitLength) const {
        double fuelNeeded = (circuitLength / 100) * fuelConsumption;
        return currentFuel >= fuelNeeded;
    }

    double CalculateTime(double circuitLength, Weather weather) const {
        double speed = GetAverageSpeed(weather);
        return circuitLength / speed;
    }
};
