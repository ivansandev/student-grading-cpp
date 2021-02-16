//
// Created by Ivan Sandev on 2/16/21.
//

#ifndef EXERCISE_STUDENTPRINTER_H
#define EXERCISE_STUDENTPRINTER_H
#include <vector>
#include <map>
#include "StudentGrading.h"

using std::cout;
using std::cin;
using std::endl;

class StudentPrinter {
public:
    // ----------------------------------
    // ------- REQUIRED FUNCTIONS -------
    // ----------------------------------

    // Prints the average grade for all groups
    static void printAverageGradePerGroup(std::vector<StudentGrading *> &students);

    // Prints the student with the minimal average grade of a given group
    static void printMinAverageGrade(std::vector<StudentGrading *> &students, short group);

    // Prints the student with the maximal average grade of a given group
    static void printMaxAverageGrade(std::vector<StudentGrading *> &students, short group);

    // Prints all students from all groups
    static void printStudents(std::vector<StudentGrading *> &students);

    // Prints all students from a given group
    static void printGroup(std::vector<StudentGrading *> &students);
};


#endif //EXERCISE_STUDENTPRINTER_H
