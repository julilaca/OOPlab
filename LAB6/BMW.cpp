#include "BMW.h"

BMW::BMW() {
    fuelCapacity = 60;
    fuelConsumption = 8;
    averageSpeed[0] = 100; // rain
    averageSpeed[1] = 150; // sun
    averageSpeed[2] = 85;  // snow
}

float BMW::GetFuelCapacity()  { return fuelCapacity; }
float BMW::GetFuelConsumption()  { return fuelConsumption; }
float BMW::GetAverageSpeed(Weather weather)  { return averageSpeed[(int)weather]; }
 const char* BMW::GetCarName()  { return "Bmw"; }
