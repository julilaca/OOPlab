#include "RangeRover.h"

RangeRover::RangeRover() {
    fuelCapacity = 80.0;
    fuelConsumption = 12.0;
    avgSpeedRain = 75.0;
    avgSpeedSunny = 100.0;
    avgSpeedSnow = 70.0;
    currentFuel = fuelCapacity;
}

double RangeRover::GetFuelCapacity() const { return fuelCapacity; }
double RangeRover::GetFuelConsumption() const { return fuelConsumption; }

double RangeRover::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return avgSpeedRain;
        case Weather::Sunny: return avgSpeedSunny;
        case Weather::Snow: return avgSpeedSnow;
    }
    return 0;
}

const char* RangeRover::GetName() const { return "RangeRover"; }
