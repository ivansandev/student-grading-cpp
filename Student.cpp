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

    cout << "Name: ";
    getline(cin, name);

    cout << "Faculty: ";
    getline(cin, faculty);

    cout << "Faculty number: ";
    cin >> faculty;

    cout << "Group: ";
    cin >> group;
}
