#include "Student.h"

void Student::setName(std::string newName) {
    name = newName;
}

std::string Student::getName() {
    return name; }

void Student::setMathGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        mathGrade = grade;
    }
}
float Student::getMathGrade() {
    return mathGrade;
}
void Student::setEnglishGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        englishGrade = grade;
    }
}

float Student::getEnglishGrade() {
    return englishGrade;
}

void Student::setHistoryGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        historyGrade = grade;
    }
}

float Student::getHistoryGrade() {
    return historyGrade;
}

float Student::getAverageGrade() {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}

int compareByName(Student& s1, Student& s2) {
    if (s1.getName() == s2.getName()) {
        return 0;
    } else if (s1.getName() > s2.getName()) {
        return 1;
    } else {
        return -1;
    }
}

int compareByMathGrade(Student& s1, Student& s2) {
    if (s1.getMathGrade() > s2.getMathGrade()) return 1;
    if (s1.getMathGrade() < s2.getMathGrade()) return -1;
    return 0;
}

int compareByEnglishGrade(Student& s1, Student& s2) {
    if (s1.getEnglishGrade() > s2.getEnglishGrade()) return 1;
    if (s1.getEnglishGrade() < s2.getEnglishGrade()) return -1;
    return 0;
}

int compareByHistoryGrade(Student* s1, Student& s2) {
    if (s1->getHistoryGrade() > s2.getHistoryGrade()) return 1;
    if (s1.getHistoryGrade() < s2.getHistoryGrade()) return -1;
    return 0;
}

int compareByAverageGrade(Student& s1, Student& s2) {
    if (s1.getAverageGrade() > s2.getAverageGrade()) return 1;
    if (s1.getAverageGrade() < s2.getAverageGrade()) return -1;
    return 0;
}
