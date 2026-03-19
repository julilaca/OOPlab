#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    Student student1, student2;

    student1.setName("julia");
    student1.setMathGrade(5.0);
    student1.setEnglishGrade(9.0);
    student1.setHistoryGrade(7.5);

    student2.setName("george");
    student2.setMathGrade(3.5);
    student2.setEnglishGrade(4.0);
    student2.setHistoryGrade(9.5);

    cout << "compare name:" << compareByName(student1, student2) << endl;
    cout << "compare math grade: " << compareByMathGrade(student1, student2) << endl;
    cout << "compare english grade:" << compareByEnglishGrade(student1, student2) << endl;
    cout << "compare history grade: " << compareByHistoryGrade(student1, student2) << endl;
    cout << "compare average grade: " << compareByAverageGrade(student1, student2) << endl;

    return 0;
}

