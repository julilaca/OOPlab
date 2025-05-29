#include "MovieSeries.h"
#include <iostream>
#include <algorithm>

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count < 16) {
        movies[count++] = movie;
    }
}

void MovieSeries::print() const {
    for (int i = 0; i < count; ++i) {
        std::cout << movies[i]->get_name() << " | "
                  << "Year: " << movies[i]->get_year() << " | "
                  << "Score: " << movies[i]->get_score() << " | "
                  << "Length: " << movies[i]->get_length() << "min | "
                  << "Passed Years: " << movies[i]->get_passed_years()
                  << std::endl;
    }
}

void MovieSeries::sort() {
    std::sort(movies, movies + count, [](Movie* a, Movie* b) {
        return a->get_passed_years() > b->get_passed_years();
    });
}
