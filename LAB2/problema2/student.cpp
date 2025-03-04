#include "Student.h"

void Student::setName(const std::string& newName) {
    name = newName;
}

std::string Student::getName() const {
    return name;
}

void Student::setMathGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        mathGrade = grade;
    }
}

float Student::getMathGrade() const {
    return mathGrade;
}

void Student::setEnglishGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        englishGrade = grade;
    }
}

float Student::getEnglishGrade() const {
    return englishGrade;
}

void Student::setHistoryGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        historyGrade = grade;
    }
}

float Student::getHistoryGrade() const {
    return historyGrade;
}

float Student::getAverageGrade() const {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}

int compareByName(const Student& s1, const Student& s2) {
    return s1.getName().compare(s2.getName());
}

int compareByMathGrade(const Student& s1, const Student& s2) {
    if (s1.getMathGrade() > s2.getMathGrade()) return 1;
    if (s1.getMathGrade() < s2.getMathGrade()) return -1;
    return 0;
}

int compareByEnglishGrade(const Student& s1, const Student& s2) {
    if (s1.getEnglishGrade() > s2.getEnglishGrade()) return 1;
    if (s1.getEnglishGrade() < s2.getEnglishGrade()) return -1;
    return 0;
}

int compareByHistoryGrade(const Student& s1, const Student& s2) {
    if (s1.getHistoryGrade() > s2.getHistoryGrade()) return 1;
    if (s1.getHistoryGrade() < s2.getHistoryGrade()) return -1;
    return 0;
}

int compareByAverageGrade(const Student& s1, const Student& s2) {
    if (s1.getAverageGrade() > s2.getAverageGrade()) return 1;
    if (s1.getAverageGrade() < s2.getAverageGrade()) return -1;
    return 0;
}

