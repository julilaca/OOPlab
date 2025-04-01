#include "Circuit.h"
#include <algorithm>
#include <iostream>

void Circuit::SetLength(double length) { this->length = length; }
void Circuit::SetWeather(Weather weather) { this->weather = weather; }
void Circuit::AddCar(Car* car) { cars.push_back(car); }

void Circuit::Race() {
    raceResults.clear();
    didNotFinish.clear();

    for (Car* car : cars) {
        if (car->CanFinish(length)) {
            double time = car->CalculateTime(length, weather);
            raceResults.emplace_back(car, time);
        } else {
            didNotFinish.push_back(car);
        }
    }

    std::sort(raceResults.begin(), raceResults.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
}

void Circuit::ShowFinalRanks() const {
    std::cout << "final rankings:\n";
    for (size_t i = 0; i < raceResults.size(); ++i) {
        std::cout << i + 1 << ". " << raceResults[i].first->GetName()
                  << " time: " << raceResults[i].second << " hours\n";
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    if (didNotFinish.empty()) {
        std::cout << "all cars finished the race\n";
        return;
    }

    std::cout << "cars that did not finish\n";
    for (const Car* car : didNotFinish) {
        std::cout << "- " << car->GetName() << "\n";
    }
}
