#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 60;
    fuelConsumption = 8;
    averageSpeed[0] = 80; // rain
    averageSpeed[1] = 100; // sun
    averageSpeed[2] = 70; // snow
}

float Seat::GetFuelCapacity() { return fuelCapacity; }
float Seat::GetFuelConsumption() { return fuelConsumption; }
float Seat::GetAverageSpeed(Weather weather) { return averageSpeed[(int)weather]; }
const char* Seat::GetCarName() { return "Seat"; }
