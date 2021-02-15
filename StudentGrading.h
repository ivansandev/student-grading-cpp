//
// Created by Ivan Sandev on 2/14/21.
//

#ifndef EXERCISE_STUDENTGRADING_H
#define EXERCISE_STUDENTGRADING_H

#include <ostream>
#include <algorithm>
#include <iterator>
#include "Student.h"
#define SUBJECTS_PER_SEMESTER 5

class StudentGrading: public Student {
private:
    int grades_1st_semester[SUBJECTS_PER_SEMESTER]{};
    int grades_2nd_semester[SUBJECTS_PER_SEMESTER]{};

public:
    // Print menu and get parameters for every member of class
    StudentGrading();

    float getAverageGrade(bool printMissingGrades = false);
    void saveBinary();
    void loadBinary();

    void setGrades(int *grades);

    friend std::ostream &operator<<(std::ostream &os, const StudentGrading &grading);
};


#endif //EXERCISE_STUDENTGRADING_H
