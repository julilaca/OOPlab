#include "RangeRover.h"

RangeRover::RangeRover() {
    fuelCapacity = 60;
    fuelConsumption = 8;
    averageSpeed[0] = 120; // rain
    averageSpeed[1] = 130; // sun
    averageSpeed[2] = 90; // snow
}

float RangeRover::GetFuelCapacity()  { return fuelCapacity; }
float RangeRover::GetFuelConsumption()  { return fuelConsumption; }
float RangeRover::GetAverageSpeed(Weather weather)  { return averageSpeed[(int)weather]; }
const char* RangeRover::GetCarName()  { return "RRover"; }
