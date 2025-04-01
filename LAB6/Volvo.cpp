#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 60.0;
    fuelConsumption = 8.5;
    avgSpeedRain = 70.0;
    avgSpeedSunny = 110.0;
    avgSpeedSnow = 60.0;
    currentFuel = fuelCapacity;
}

double Volvo::GetFuelCapacity() const { return fuelCapacity; }
double Volvo::GetFuelConsumption() const { return fuelConsumption; }

double Volvo::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return avgSpeedRain;
        case Weather::Sunny: return avgSpeedSunny;
        case Weather::Snow: return avgSpeedSnow;
    }
    return 0;
}

const char* Volvo::GetName() const { return "Volvo"; }
