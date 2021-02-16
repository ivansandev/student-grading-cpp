//
// Created by Ivan Sandev on 2/14/21.
//

#include "Student.h"

// Default constructor, initializes wizard for inputting data through the console
Student::Student() {
    // Verifies name until it's entered correctly
    while (true) {
        cout << "Name: ";
        std::string newName;
        getline(cin, newName);
        if (setName(newName))
            break;
    }

    // Verifies faculty until it's entered correctly
    while (true) {
        cout << "Faculty: ";
        std::string newFaculty;
        getline(cin, newFaculty);
        if (setFaculty(newFaculty))
            break;
    }

    // Verifies faculty number until it's entered correctly
    while (true) {
        cout << "Faculty number: ";
        unsigned int newFacultyNumber;
        cin >> newFacultyNumber;
        if (setFacultyNumber(newFacultyNumber))
            break;
    }

    // Verifies group until it's entered correctly
    while (true) {
        cout << "Group: ";
        unsigned short newGroup;
        cin >> newGroup;
        if (setGroup(newGroup))
            break;
    }
}

Student::Student(const std::string &name, const std::string &faculty, int facultyNumber, short groupNumber) : name(
        name), faculty(faculty), facultyNumber(facultyNumber), group(groupNumber) {}

// Overloading operator <<
std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << student.name << " | " << student.faculty << " | " << student.facultyNumber << " | " << student.group;
    return os;
}

Student::Student(std::ifstream &file) {
    Student::loadBinary(file);
}

Student::~Student() = default;

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
    for (char ch:name) {
        if (ch == ' ') countSpaces++;
        if (!isalpha(ch) and !isspace(ch)) errorInName = true;
    }
    // Returns false if only the first name is given (no spaces found)
    if (countSpaces == 0) {
        cout << "[ERROR] Please enter full name. No name or only first name was given." << endl;
        return false;
    }
    // Returns false if there are special characters in the name
    if (errorInName) {
        cout << "[ERROR] Numbers or other special symbols were found in name. Name can contain only letters and spaces."
             << endl;
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
    // Returns TRUE if group number is set between 1 and MAX_GROUP_NUMBER
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
    // Returns TRUE only if facultyNumber is set above 0
    if (facultyNumber <= 0) {
        cout << "[ERROR] Faculty number cannot be smaller than 0" << endl;
        return false;
    }

    Student::facultyNumber = facultyNumber;
    return true;
}

void Student::saveBinary(std::ofstream &file) {
    int size;

    // Writes size of 'name' string and writes string to file
    size = name.size();
    file.write(reinterpret_cast<const char *>(&size), sizeof(int));
    file.write(name.c_str(), size * sizeof(char));

    // Writes size of 'faculty' string and writes string to file
    size = faculty.size();
    file.write(reinterpret_cast<const char *>(&size), sizeof(int));
    file.write(faculty.c_str(), size * sizeof(char));

    // Writes 'facultyNumber' to file
    file.write(reinterpret_cast<char *>(&facultyNumber), sizeof(facultyNumber));

    // Writes 'group' to file
    file.write(reinterpret_cast<char *>(&group), sizeof(group));
}

void Student::loadBinary(std::ifstream &file) {
    // Gets data from open binary file to the object members
    int size;

    // Loads size of 'name' string and loads 'name' from file
    file.read(reinterpret_cast<char *> (&size), sizeof(int));
    name.resize(size);
    file.read(&name[0], size * sizeof(char));

    // Loads size of 'faculty' string and loads 'faculty' from file
    file.read(reinterpret_cast<char *> (&size), sizeof(int));
    faculty.resize(size);
    file.read(&faculty[0], size * sizeof(char));

    // Loads 'facultyNumber' from file
    file.read(reinterpret_cast<char *>(&facultyNumber), sizeof(facultyNumber));

    // Loads 'group' from file
    file.read(reinterpret_cast<char *>(&group), sizeof(group));
}



