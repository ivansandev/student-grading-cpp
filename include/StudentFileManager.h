//
// Created by Ivan Sandev on 2/16/21.
//

#ifndef EXERCISE_STUDENTFILEMANAGER_H
#define EXERCISE_STUDENTFILEMANAGER_H
#include <vector>
#include <fstream>
#include "StudentGrading.h"

using std::cout;
using std::cin;
using std::endl;


class StudentFileManager {
public:
    // ----------------------------------------------
    // ------- SAVE / LOAD DATA FROM BIN FILE -------
    // ----------------------------------------------
    static void save(std::vector<StudentGrading *> &students, std::string filename);
    static void load(std::vector<StudentGrading *> &students, std::string filename);
};

#endif //EXERCISE_STUDENTFILEMANAGER_H
