#pragma once
#include "Car.h"

class BMW : public Car {
public:
    BMW();
    double GetFuelCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather weather) const override;
    const char* GetName() const override;
};
