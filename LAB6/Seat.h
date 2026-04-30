#ifndef SEAT_H
#define SEAT_H

#include "Car.h"

class Seat : public Car {
public:
    Seat();
    float GetFuelCapacity() ;
    float GetFuelConsumption() ;
    float GetAverageSpeed(Weather weather) ;
 const char* GetCarName() ;
};

#endif 
