//
// Created by Ivan Sandev on 2/14/21.
//

#include <iostream>
#include <string>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;

#ifndef EXERCISE_STUDENT_H
#define EXERCISE_STUDENT_H

class Student {
private:
    std::string name;
    std::string faculty;
    int facultyNumber;
    short group;
public:
    Student();
    Student(const std::string &name, const std::string &faculty, int facultyNumber, short groupNumber);

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};


#endif //EXERCISE_STUDENT_H
