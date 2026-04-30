#ifndef RANGEROVER_H
#define RANGEROVER_H

#include "Car.h"

class RangeRover : public Car {
public:
    RangeRover();
    float GetFuelCapacity()  ;
    float GetFuelConsumption()  ;
    float GetAverageSpeed(Weather weather)  ;
    const char* GetCarName()  ;
};

#endif 
