#ifndef BMW_H
#define BMW_H

#include "Car.h"

class BMW : public Car {
public:
    BMW();
    float GetFuelCapacity() ;
    float GetFuelConsumption();
    float GetAverageSpeed(Weather weather);
 const char* GetCarName();
};

#endif
