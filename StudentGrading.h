//
// Created by Ivan Sandev on 2/14/21.
//

#ifndef EXERCISE_STUDENTGRADING_H
#define EXERCISE_STUDENTGRADING_H

#include "Student.h"
#define SUBJECTS_PER_SEMESTER 5

class StudentGrading: public Student {
private:
    unsigned short grades_1st_semester[SUBJECTS_PER_SEMESTER]{0};
    unsigned short grades_2nd_semester[SUBJECTS_PER_SEMESTER]{0};

public:
    // Print menu and get parameters for every member of class
    StudentGrading();
    StudentGrading(bool wizard);
    virtual ~StudentGrading();

    float getAverageGrade(bool printMissingGrades = false);
    void saveBinary(std::ofstream &file);
    void loadBinary(std::ifstream &file);

    void setGrades(unsigned short *grades);

    friend std::ostream &operator<<(std::ostream &os, const StudentGrading &grading);
};


#endif //EXERCISE_STUDENTGRADING_H
