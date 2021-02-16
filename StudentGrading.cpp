//
// Created by Ivan Sandev on 2/14/21.
//

#include "StudentGrading.h"

StudentGrading::StudentGrading() : Student() {
    cout << "Enter grades for 1st semester" << endl;
    setGrades(grades_1st_semester);
    cout << "Enter grades for 2nd semester" << endl;
    setGrades(grades_2nd_semester);
}

void StudentGrading::setGrades(unsigned short *grades) {
    // Input wizard that goes over every grade for a semester
    // Checks if value entered by user is between 2 and 6 (or 0 for 'still not graded subject')
    for (int i=0; i<SUBJECTS_PER_SEMESTER; i++) {
        cout << "Enter grade for subject " << i+1 << ": ";
        int grade = 0;
        while (true) {
            cin >> grade;
            if ((grade >= 2 && grade <= 6) || grade == 0) {
                grades[i] = grade;
                break;
            }
            else {
                cout << "Grade should be between 2 and 6 (or 0 for 'still not graded'). Please try again.\nGrade: ";
            }
        }
    }
}

float StudentGrading::getAverageGrade(bool printMissingGrades) {
    // printMissingGrades is OPTIONAL:
    //     If it's true, it checks how many grades a student is missing
    //     (use case: when applying for scholarship, there should be no missing grades)
    if (printMissingGrades) {
        int count = 0;
        for (int grade : grades_1st_semester) {
            if (grade != 0) {
                count++;
            }
        }
        if (count < SUBJECTS_PER_SEMESTER) {
            cout << "Student " << this->getName() << " is missing " << count << " grades for 1st semester." << endl;
        }
        count = 0;
        for (int grade : grades_2nd_semester) {
            if (grade != 0) {
                count++;
            }
        }
        if (count < SUBJECTS_PER_SEMESTER) {
            cout << "Student " << this->getName() << " is missing " << count << " grades for 2nd semester." << endl;
        }
    }

    // Getting the sum of all grades and excluding values '0' which means the subject is still not graded
    int total = 0;
    int numGrades = 0;
    for (int i = 0; i < SUBJECTS_PER_SEMESTER; i++) {
        total += grades_1st_semester[i];
        if (grades_1st_semester[i] != 0) numGrades++;
        total += grades_2nd_semester[i];
        if (grades_2nd_semester[i] != 0) numGrades++;
    }
    // Returning the average grade for both semesters
    if (numGrades > 0)
        return (float) total / (float) numGrades;
    else
        return 0;
}

std::ostream &operator<<(std::ostream &os, const StudentGrading &grading) {
    // Operator << is overloaded in parent class
    os << static_cast<const Student &>(grading);

    // Printing grades for first semester
    os << "\n\tGrades (1st semester): ";
    for (int grade : grading.grades_1st_semester) {
        os << grade << " ";
    }

    // Printing grades for second semester
    os << "\n\tGrades (2nd semester): ";
    for (int grade : grading.grades_2nd_semester) {
        os << grade << " ";
    }

    return os;
}

void StudentGrading::saveBinary(std::ofstream &file) {
    Student::saveBinary(file);

    for (auto& grade : grades_1st_semester) {
        file.write(reinterpret_cast<const char *>(&grade), sizeof(unsigned short));
    }
    for (auto& grade : grades_2nd_semester) {
        file.write(reinterpret_cast<const char *>(&grade), sizeof(unsigned short));
    }
}

void StudentGrading::loadBinary(std::ifstream &file) {
    // parent constructor calls for Student::loadBinary(file) so there's no need to call here
    for (auto& grade : grades_1st_semester) {
        file.read(reinterpret_cast<char *>(&grade), sizeof(unsigned short));
    }
    for (auto& grade : grades_2nd_semester) {
        file.read(reinterpret_cast<char *>(&grade), sizeof(unsigned short));
    }
}

StudentGrading::StudentGrading(std::ifstream &file) : Student(file) {
    StudentGrading::loadBinary(file);
}

StudentGrading::~StudentGrading() = default;



