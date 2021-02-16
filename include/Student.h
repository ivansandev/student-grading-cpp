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
    // Constructor
    Student();
    explicit Student(std::ifstream &file);
    // Destructor
    virtual ~Student();

    Student(const std::string &name, const std::string &faculty, int facultyNumber, short groupNumber);

    virtual float getAverageGrade(bool printMissingGrades) = 0;

    // Overloading << operator
    friend std::ostream &operator<<(std::ostream &os, const Student &student);

    // Reading/writing to file
    virtual void saveBinary(std::ofstream &file);
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