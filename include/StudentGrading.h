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

    // Wizard for inputting and validating grades for 2 semesters
    void setGrades(unsigned short *grades);
public:
    // DEFAULT CONSTRUCTOR - initializes wizard for inputting values through the command line
    StudentGrading();
    // CONSTRUCTOR - used for initializing data from binary file
    explicit StudentGrading(std::ifstream &file);
    // DESTRUCTOR
    virtual ~StudentGrading();

    // GETS AVERAGE GRADE FOR STUDENT (returns 0 if it still has no grades)
    float getAverageGrade(bool printMissingGrades = false);

    // WRITE CLASS DATA TO BIN FILE (file pointer passed as parameter)
    void saveBinary(std::ofstream &file);
    // READ CLASS DATA FROM BIN FILE (file pointer passed as parameter)
    void loadBinary(std::ifstream &file);

    // OVERLOADING OPERATOR <<
    friend std::ostream &operator<<(std::ostream &os, const StudentGrading &grading);

    // GETTERS / SETTERS
    const unsigned short *getGrades1StSemester() const;
    const unsigned short *getGrades2NdSemester() const;
};


#endif //EXERCISE_STUDENTGRADING_H
