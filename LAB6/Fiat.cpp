#include "Fiat.h"

Fiat::Fiat() {
    fuelCapacity = 60;
    fuelConsumption = 8;
    averageSpeed[0] = 30; // rain
    averageSpeed[1] = 50; // sun
    averageSpeed[2] = 20; // snow
}

float Fiat::GetFuelCapacity() { return fuelCapacity; }
float Fiat::GetFuelConsumption() { return fuelConsumption; }
float Fiat::GetAverageSpeed(Weather weather) { return averageSpeed[(int)weather]; }
const char* Fiat::GetCarName() { return "Fiat"; }
