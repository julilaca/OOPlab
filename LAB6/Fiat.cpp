#include "Fiat.h"

Fiat::Fiat() {
    fuelCapacity = 40.0;
    fuelConsumption = 6.5;
    avgSpeedRain = 60.0;
    avgSpeedSunny = 85.0;
    avgSpeedSnow = 50.0;
    currentFuel = fuelCapacity;
}

double Fiat::GetFuelCapacity() const { return fuelCapacity; }
double Fiat::GetFuelConsumption() const { return fuelConsumption; }

double Fiat::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return avgSpeedRain;
        case Weather::Sunny: return avgSpeedSunny;
        case Weather::Snow: return avgSpeedSnow;
    }
    return 0;
}

const char* Fiat::GetName() const { return "Fiat"; }
