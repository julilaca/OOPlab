#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std; 

class Movie {
private:
    char name[256];
    int year;
    double score;
    int length;

public:
    void set_name(const string& n);
    string get_name();

    void set_year(int y);
    int get_year();

    void set_score(double s);
    double get_score();

    void set_length(int l);
    int get_length();

    int get_passed_years();
};

#endif
