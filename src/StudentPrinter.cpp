//
// Created by Ivan Sandev on 2/16/21.
//

#include "../include/StudentPrinter.h"

// Prints all students from all groups
void StudentPrinter::printStudents(std::vector<StudentGrading *> &students) {
    cout << "------------------------------------------";
    int counter = 0;
    for (StudentGrading *student : students) {
        cout << endl << *student << endl;
        ++counter;
    }
    if (counter == 0)
        cout << endl << "No students found." << endl;
    cout << "------------------------------------------" << endl;
}

// Prints all students from a given group
void StudentPrinter::printGroup(std::vector<StudentGrading *> &students) {
    cout << "------------------------------------------" << endl;
    unsigned short group;
    int counter = 0;
    cout << "Group to display: ";
    cin >> group;
    for (StudentGrading *student : students) {
        if (group == student->getGroup()) {
            cout << endl << *student << endl;
            ++counter;
        }
    }
    if (counter == 0)
        cout << endl <<  "No students found in group " << group << endl;
    cout << "------------------------------------------" << endl;
}

// Prints the average grade for all groups
void StudentPrinter::printAverageGradePerGroup(std::vector<StudentGrading *> &students) {
    cout << "------------------------------------------" << endl;
    std::map<int, float> sumGrades; // used for getting the sum of all grades per in (<group>, <sum_of_grades>) form
    std::map<int, int> numGrades;   // used for getting the number of grades per group in (<group>, <number_of_grades>) form

    for (StudentGrading *student : students) {
        unsigned short group = student->getGroup();
        if (student->getAverageGrade() != 0) {
            sumGrades[group] += student->getAverageGrade();
            ++numGrades[group];
        }
    }

    for (auto const&[key, value] : sumGrades) {
        // key -> group
        // value -> sum of grades for group
        // numGrades[key] -> number of grades per group
        float avgGrade = (float) value / numGrades[key];
        cout << "Group " << key << " has an average grade of " << avgGrade << endl;
    }
    cout << "------------------------------------------" << endl;
}

// Prints the student with the minimal average grade of a given group
void StudentPrinter::printMinAverageGrade(std::vector<StudentGrading *> &students, short group) {
    cout << "------------------------------------------" << endl;
    float minAvgGrade = 10;
    int counter = 0;
    StudentGrading *minGradeStudent;

    // Goes over all students, checks if the group is the one given in the parameter
    // and compares to see which student has the lowest grade
    for (auto &student : students) {
        if (student->getGroup() == group) {
            if (student->getAverageGrade() < minAvgGrade) {
                minAvgGrade = student->getAverageGrade();
                minGradeStudent = student;
                ++counter;
            }
        }
    }

    if (counter > 0) {
        cout << "Student " << minGradeStudent->getName() << " has the lowest average grade of "
             << minGradeStudent->getAverageGrade() << endl;
        cout << *minGradeStudent << endl;
    } else {
        cout << "No students found in group " << group << endl;
    }
    cout << "------------------------------------------" << endl;
}

// Prints the student with the maximal average grade of a given group
void StudentPrinter::printMaxAverageGrade(std::vector<StudentGrading *> &students, short group) {
    cout << "------------------------------------------" << endl;
    float maxAvgGrade = 0;
    int counter = 0;
    StudentGrading *maxGradeStudent;

    // Goes over all students, checks if the group is the one given in the parameter
    // and compares to see which student has the highest grade
    for (auto &student : students) {
        if (student->getGroup() == group) {
            if (student->getAverageGrade() > maxAvgGrade) {
                maxAvgGrade = student->getAverageGrade();
                maxGradeStudent = student;
                ++counter;
            }
        }
    }

    if (counter > 0) {
        cout << "Student " << maxGradeStudent->getName() << " has the highest average grade of "
             << maxGradeStudent->getAverageGrade() << endl;
        cout << *maxGradeStudent << endl;
    } else {
        cout << "No students found in group " << group << endl;
    }
    cout << "------------------------------------------" << endl;
}