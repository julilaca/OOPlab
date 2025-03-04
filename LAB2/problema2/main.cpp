#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    Student student1, student2;

    student1.setName("anna");
    student1.setMathGrade(3.0);
    student1.setEnglishGrade(9.0);
    student1.setHistoryGrade(7.5);

    student2.setName("john");
    student2.setMathGrade(5.5);
    student2.setEnglishGrade(4.0);
    student2.setHistoryGrade(9.5);

    cout << "Compare name: " << compareByName(student1, student2) << endl;
    cout << "Compare math grade: " << compareByMathGrade(student1, student2) << endl;
    cout << "Compare english grade: " << compareByEnglishGrade(student1, student2) << endl;
    cout << "Compare history grade: " << compareByHistoryGrade(student1, student2) << endl;
    cout << "Compare average grade: " << compareByAverageGrade(student1, student2) << endl;

    return 0;
}

