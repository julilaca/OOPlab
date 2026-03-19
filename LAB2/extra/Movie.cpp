#include "Movie.h"
#include <cstring>
#include <ctime>


void Movie::set_name(const std::string& n) {
    strncpy(name, n.c_str(), sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

std::string Movie::get_name() const {
    return std::string(name);
}

void Movie::set_year(int y) {
    year = y;
}

int Movie::get_year() const {
    return year;
}

void Movie::set_score(double s) {
    if (s >= 1.0 && s <= 10.0) {
        score = s;
    }
}

double Movie::get_score() const {
    return score;
}

void Movie::set_length(int l) {
    length = l;
}

int Movie::get_length() const {
    return length;
}

int Movie::get_passed_years() const {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return now->tm_year + 1900 - year;
}
