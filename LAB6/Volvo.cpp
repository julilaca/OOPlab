#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 60;
    fuelConsumption = 8;
    averageSpeed[0] = 80; // rain
    averageSpeed[1] = 120; // sun
    averageSpeed[2] = 70; // snow
}

float Volvo::GetFuelCapacity()  { return fuelCapacity; }
float Volvo::GetFuelConsumption()  { return fuelConsumption; }
float Volvo::GetAverageSpeed(Weather weather)  { return averageSpeed[(int)weather]; }
const char* Volvo::GetCarName()  { return "Volvo"; }
