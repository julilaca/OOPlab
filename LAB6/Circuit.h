#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Car.h"
#include <vector>

class Circuit {
private:
    int length;
    Weather weather;
    std::vector<Car*> cars;
    std::vector<std::pair<Car*, float>> results; 
    std::vector<Car*> didNotFinish;

public:
    Circuit();
    ~Circuit();
    void SetLength(int l);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};

#endif 
