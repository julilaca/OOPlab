#include "Circuit.h"
#include <iostream>
#include <algorithm>

bool CompareRaceResults(const std::pair<Car*, float>& a, const std::pair<Car*, float>& b) {
    return a.second < b.second;
}

Circuit::Circuit() : length(0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (Car* car : cars) {
        delete car;
    }
}

void Circuit::SetLength(int l) {
    length = l;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    results.clear();
    didNotFinish.clear();

    for (Car* car : cars) {
        float speed = car->GetAverageSpeed(weather);
        float maxDistance = car->GetFuelCapacity() / car->GetFuelConsumption() * 100;

        if (maxDistance >= length) {
            float time = length / speed;
            results.push_back({car, time});
        } else {
            didNotFinish.push_back(car);
        }
    }

    std::sort(results.begin(), results.end(), CompareRaceResults);
}

void Circuit::ShowFinalRanks() const {
    std::cout << "final ranks:\n";
    for (size_t i = 0; i < results.size(); i++) {
        std::cout << i + 1 << ". " << results[i].first->GetCarName() 
                  << " finished in " << results[i].second << " hours.\n";
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    std::cout << "cars that did not finish:\n";
    for (Car* car : didNotFinish) {
        std::cout << car->GetCarName() << " ran out of fuel.\n";
    }
}