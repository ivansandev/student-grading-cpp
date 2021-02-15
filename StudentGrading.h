//
// Created by Ivan Sandev on 2/14/21.
//

#ifndef EXERCISE_STUDENTGRADING_H
#define EXERCISE_STUDENTGRADING_H
#include "Student.h"

class StudentGrading: public Student {
private:
    int grades_1st_semester[5];
    int grades_2nd_semester[5];

public:
    // Print menu and get parameters for every member of class
    StudentGrading();
    float getAverageGrade();
    void saveBinary();
    void loadBinary();
};


#endif //EXERCISE_STUDENTGRADING_H
