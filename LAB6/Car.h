#ifndef CAR_H
#define CAR_H

#include "Weather.h"

class Car {
protected:
    float fuelCapacity;
    float fuelConsumption;
    float averageSpeed[3];

public:
    virtual ~Car() {}
    virtual float GetFuelCapacity()  = 0;
    virtual float GetFuelConsumption()  = 0;
    virtual float GetAverageSpeed(Weather weather)  = 0;
    virtual const char* GetCarName()  = 0;
};

#endif 
