#pragma once
#include "Car.h"

class Seat : public Car {
public:
    Seat();
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather weather) const override;
    const char* GetName() const override;
};
