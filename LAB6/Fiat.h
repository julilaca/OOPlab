#ifndef FIAT_H
#define FIAT_H

#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    float GetFuelCapacity()  ;
    float GetFuelConsumption()  ;
    float GetAverageSpeed(Weather weather)  ;
    const char* GetCarName()  ;
};

#endif 
