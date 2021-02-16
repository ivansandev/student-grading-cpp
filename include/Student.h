//
// Created by Ivan Sandev on 2/14/21.
//

#include <iostream>
#include <string>
#include <ostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

#ifndef EXERCISE_STUDENT_H
#define EXERCISE_STUDENT_H
#define MAX_GROUP_NUMBER 300

class Student {
private:
    std::string name;
    std::string faculty;
    unsigned int facultyNumber;
    unsigned short group;
public:
    // DEFAULT CONSTRUCTOR - initializes wizard for inputting values through the command line
    Student();
    // CONSTRUCTOR - used for initializing data from binary file
    explicit Student(std::ifstream &file);
    // DESTRUCTOR
    virtual ~Student();

    // PURE VIRTUAL FUNCTION - Student class is virtual
    virtual float getAverageGrade(bool printMissingGrades) = 0;

    // OVERLOADING OPERATOR <<
    friend std::ostream &operator<<(std::ostream &os, const Student &student);

    // WRITE CLASS DATA TO FILE
    virtual void saveBinary(std::ofstream &file);
    // READ CLASS DATA FROM FILE
    virtual void loadBinary(std::ifstream &file);

    // GETTERS / SETTERS
    const std::string &getName() const;
    bool setName(const std::string &name);
    const std::string &getFaculty() const;
    bool setFaculty(const std::string &faculty);
    unsigned short getGroup() const;
    bool setGroup(unsigned short group);
    unsigned int getFacultyNumber() const;
    bool setFacultyNumber(unsigned int facultyNumber);
};


#endif //EXERCISE_STUDENT_H
