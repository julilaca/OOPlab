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
    void setName(const std::string& newName);
    std::string getName() const;

    void setMathGrade(float grade);
    float getMathGrade() const;

    void setEnglishGrade(float grade);
    float getEnglishGrade() const;

    void setHistoryGrade(float grade);
    float getHistoryGrade() const;

    float getAverageGrade() const;
};

int compareByName(const Student& s1, const Student& s2);
int compareByMathGrade(const Student& s1, const Student& s2);
int compareByEnglishGrade(const Student& s1, const Student& s2);
int compareByHistoryGrade(const Student& s1, const Student& s2);
int compareByAverageGrade(const Student& s1, const Student& s2);

#endif

