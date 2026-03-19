#include "MovieCompare.h"

int movie_compare_name(Movie& m1, Movie& m2) {
    return m1.get_name().compare(m2.get_name());
}

int movie_compare_year(Movie& m1, Movie& m2) {
    return (m1.get_year() < m2.get_year()) ? -1 : (m1.get_year() > m2.get_year());
}

int movie_compare_score(Movie& m1, Movie& m2) {
    return (m1.get_score() < m2.get_score()) ? -1 : (m1.get_score() > m2.get_score());
}

int movie_compare_length(Movie& m1, Movie& m2) {
    return (m1.get_length() < m2.get_length()) ? -1 : (m1.get_length() > m2.get_length());
}

int movie_compare_passed_years(Movie& m1, Movie& m2) {
    return (m1.get_passed_years() < m2.get_passed_years()) ? -1 : (m1.get_passed_years() > m2.get_passed_years());
}
