#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "StudentGrading.h"


using std::cout;
using std::cin;
using std::endl;

// MENU FUNCTIONS
void menu(std::vector<StudentGrading*> &students);
void showMenu(std::vector<StudentGrading*> &students);
void addMenu();
void removeMenu(std::vector<StudentGrading*> &students);
void changeMenu();

// REQUIRED FUNCTIONS
void averageGradePerGroup(std::vector<StudentGrading*> &students);
void minAverageGrade(std::vector<StudentGrading*> &students, short group);
void maxAverageGrade(std::vector<StudentGrading*> &students, short group);
void print(std::vector<StudentGrading*> &students);
void printGroup(std::vector<StudentGrading*> &students);

int main() {
    std::vector<StudentGrading*> students;

    menu(students);

    for (StudentGrading* student : students) {
        delete student;
    }
    return 0;
}

void menu(std::vector<StudentGrading*> &students) {
    bool run = true;

    short choice;
    while (run) {
        cout << "1. Show\n"
                "2. Add\n"
                "3. Remove\n"
                "4. Change\n"
                "0. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                showMenu(students);
                break;
            }
            case 2: {
                cin.ignore();
                students.push_back(new StudentGrading());
                break;
            }
            case 3: {
                removeMenu(students);
                break;
            }
            case 4: {
                // TODO
//                changeMenu();
                break;
            }
            case 0: {
                run = false;
                break;
            }
            default: {
                cout << "Wrong choice, please pick between 0-4." << endl;
            }
        }
    }
}

void showMenu(std::vector<StudentGrading*> &students) {
    cout << "1. Show all students\n"
            "2. Show all students from group\n"
            "3. Show average grades per group\n"
            "4. Show student with minimum average grade for selected group\n"
            "5. Show student with maximum average grade for selected group\n"
            "0. Back\n"
            "Choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            print(students);
            break;
        }
        case 2: {
            printGroup(students);
            break;
        }
        case 3: {
            averageGradePerGroup(students);
            break;
        }
        case 4: {
            cout << "Group: ";
            short group;
            cin >> group;
            minAverageGrade(students, group);
            break;
        }
        case 5: {
            cout << "Group: ";
            short group;
            cin >> group;
            maxAverageGrade(students, group);
            break;
        }
        default: {
            cout << "[ERROR] Wrong choice. Choose between option 0 and 5." << endl;
        }
    }

}

void removeMenu(std::vector<StudentGrading*> &students) {
    // TODO : Test removing student
    cout << "1. By name\n"
            "2. By faculty number\n"
            "0. Back\n";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            std::string nameToRemove;
            cout << "Name: ";
            cin.ignore();
            getline(cin, nameToRemove);
            if (nameToRemove.length()>0) {
                for (StudentGrading *student : students) {
                    if (student->getName() == nameToRemove) {
                        delete student;
                        cout << "Student removed.";
                        break;
                    }
                }
            }
            else {
                cout << "No name given. Returning..." << endl;
            }
            break;
        }
        case 2: {
            int facultyNumberToRemove;
            cout << "Faculty number: ";
            cin >> facultyNumberToRemove;
            for (StudentGrading *student : students) {
                if (student->getFacultyNumber() == facultyNumberToRemove) {
                    delete student;
                    cout << "Student removed.";
                    break;
                }
            }
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << "[ERROR] Wrong choice." << endl;
            break;
        }
    }
}

void print(std::vector<StudentGrading*> &students) {
    for (StudentGrading* student : students) {
        cout << *student << endl;
    }
}

void printGroup(std::vector<StudentGrading*> &students) {
    short group;
    cout << "Group to display: ";
    cin >> group;
    for (StudentGrading* student : students) {
        if (group == student->getGroup())
            cout << *student << endl;
    }
}

void averageGradePerGroup(std::vector<StudentGrading*> &students) {
    // TODO : Comments
    std::map<int, float> sumGrades;
    std::map<int, int> numGrades;

    for (StudentGrading *student : students) {
        unsigned short group = student->getGroup();
        sumGrades[group] += student->getAverageGrade();
        ++numGrades[group];
    }

    for (auto const& [key, value] : sumGrades) {
        // key -> group
        // value -> sum of grades for group
        // numGrades[key] -> number of grades per group
        float avgGrade = (float)value/numGrades[key];
        cout << "Group " << key << " has an average grade of " << avgGrade << endl;
    }
}

void minAverageGrade(std::vector<StudentGrading*> &students, short group) {
    // TODO : Comments
    float minAvgGrade = 10;
    int counter = 0;
    StudentGrading* minGradeStudent;

    for (auto& student : students) {
        if (student->getGroup() == group) {
            if (student->getAverageGrade() < minAvgGrade) {
                minAvgGrade = student->getAverageGrade();
                minGradeStudent = student;
                ++counter;
            }
        }
    }

    if (counter > 0) {
        cout << "Student " << minGradeStudent->getName() << " has the lowest average grade of " << minGradeStudent->getAverageGrade() << endl;
    }
    else {
        cout << "No students found in group " << group << endl;
    }
}

void maxAverageGrade(std::vector<StudentGrading*> &students, short group) {
    // TODO : Comments
    float maxAvgGrade = 0;
    int counter = 0;
    StudentGrading* maxGradeStudent;

    for (auto& student : students) {
        if (student->getGroup() == group) {
            if (student->getAverageGrade() > maxAvgGrade) {
                maxAvgGrade = student->getAverageGrade();
                maxGradeStudent = student;
                ++counter;
            }
        }
    }

    if (counter > 0) {
        cout << "Student " << maxGradeStudent->getName() << " has the highest average grade of " << maxGradeStudent->getAverageGrade() << endl;
    }
    else {
        cout << "No students found in group " << group << endl;
    }
}
