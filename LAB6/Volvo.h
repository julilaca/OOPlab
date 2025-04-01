#pragma once
#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather weather) const override;
    const char* GetName() const override;
};
