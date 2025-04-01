#pragma once
#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather weather) const override;
    const char* GetName() const override;
};
