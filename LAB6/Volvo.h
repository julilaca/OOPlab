#ifndef VOLVO_H
#define VOLVO_H

#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    float GetFuelCapacity() ;
    float GetFuelConsumption() ;
    float GetAverageSpeed(Weather weather) ;
    const char* GetCarName() ;
};

#endif 
