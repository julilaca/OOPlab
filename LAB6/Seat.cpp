#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 45.0;
    fuelConsumption = 7.5;
    avgSpeedRain = 65.0;
    avgSpeedSunny = 95.0;
    avgSpeedSnow = 55.0;
    currentFuel = fuelCapacity;
}

double Seat::GetFuelCapacity() const { return fuelCapacity; }
double Seat::GetFuelConsumption() const { return fuelConsumption; }

double Seat::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return avgSpeedRain;
        case Weather::Sunny: return avgSpeedSunny;
        case Weather::Snow: return avgSpeedSnow;
    }
    return 0;
}

const char* Seat::GetName() const { return "Seat"; }
