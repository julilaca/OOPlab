#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    void setName(std::string newName);
    std::string getName();

    void setMathGrade(float grade);
    float getMathGrade();

    void setEnglishGrade(float grade);
    float getEnglishGrade();

    void setHistoryGrade(float grade);
    float getHistoryGrade();

    float getAverageGrade();
};

int compareByName(Student& s1, Student& s2);
int compareByMathGrade(Student& s1, Student& s2);
int compareByEnglishGrade(Student& s1, Student& s2);
int compareByHistoryGrade(Student& s1, Student& s2);
int compareByAverageGrade(Student& s1, Student& s2);

#endif
