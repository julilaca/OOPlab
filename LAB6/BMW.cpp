#include "BMW.h"

BMW::BMW() {
    fuelCapacity = 55.0;
    fuelConsumption = 9.0;
    avgSpeedRain = 80.0;
    avgSpeedSunny = 130.0;
    avgSpeedSnow = 65.0;
    currentFuel = fuelCapacity;
}

double BMW::GetFuelCapacity() const { return fuelCapacity; }
double BMW::GetFuelConsumption() const { return fuelConsumption; }

double BMW::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return avgSpeedRain;
        case Weather::Sunny: return avgSpeedSunny;
        case Weather::Snow: return avgSpeedSnow;
    }
    return 0;
}

const char* BMW::GetName() const { return "BMW"; }
