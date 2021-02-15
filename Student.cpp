//
// Created by Ivan Sandev on 2/14/21.
//

#include "Student.h"

Student::Student(const std::string &name, const std::string &faculty, int facultyNumber, short groupNumber) : name(
        name), faculty(faculty), facultyNumber(facultyNumber), group(groupNumber) {}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << "Name: " << student.name << "; Faculty: " << student.faculty << "; Faculty number: " << student.facultyNumber
       << "; Group: " << student.group;
    return os;
}

Student::Student() {

    while (true) {
        cout << "Name: ";
        std::string newName;
        getline(cin, newName);
        if (setName(newName))
            break;
    }

    while (true) {
        cout << "Faculty: ";
        std::string newFaculty;
        getline(cin, newFaculty);
        if (setFaculty(newFaculty))
            break;
    }

    while (true) {
        cout << "Faculty number: ";
        unsigned int newFacultyNumber;
        cin >> newFacultyNumber;
        if (setFacultyNumber(newFacultyNumber))
            break;
    }

    while (true) {
        cout << "Group: ";
        unsigned short newGroup;
        cin >> newGroup;
        if (setGroup(newGroup))
            break;
    }
}

const std::string &Student::getName() const {
    return name;
}

bool Student::setName(const std::string &name) {
    // returns FALSE if only first name or no name is given
    //     or there is a number or a symbol in name
    // returns TRUE if two or more names are given
    //     and there are only alphabet characters in name
    int countSpaces = 0;
    bool errorInName = false;
    for(char ch:name) {
        if (ch == ' ') countSpaces++;
        if (!isalpha(ch) and !isspace(ch)) errorInName = true;
    }
    if (countSpaces == 0) {
        cout << "[ERROR] Please enter full name. No name or only first name was given." << endl;
        return false;
    }
    if (errorInName) {
        cout << "Numbers or other special symbols were found in name. Name can contain only letters." << endl;
        return false;
    }
    Student::name = name;
    return true;
}

const std::string &Student::getFaculty() const {
    return faculty;
}

bool Student::setFaculty(const std::string &faculty) {
    // Returns TRUE if faculty is not empty
    // otherwise returns FALSE
    if (faculty.empty()) {
        cout << "Faculty cannot be empty." << endl;
        return false;
    }
    Student::faculty = faculty;
    return true;
}

unsigned short Student::getGroup() const {
    return group;
}

bool Student::setGroup(unsigned short group) {
    // Returns TRUE if group number is between 1 and MAX_GROUP_NUMBER
    // otherwise returns FALSE
    if (group <= 0 || group >= MAX_GROUP_NUMBER) {
        cout << "Group number should be between 1 and " << MAX_GROUP_NUMBER << endl;
        return false;
    }
    Student::group = group;
    return true;
}

unsigned int Student::getFacultyNumber() const {
    return facultyNumber;
}

bool Student::setFacultyNumber(unsigned int facultyNumber) {
    // TODO: Check if faculty number is between 100000000 and 999999999
    Student::facultyNumber = facultyNumber;
    return true;
}
