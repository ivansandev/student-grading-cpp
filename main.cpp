#include <iostream>
#include <vector>
#include <iterator>
#include "include/StudentGrading.h"
#include "include/StudentPrinter.h"
#include "include/StudentFileManager.h"

using std::cout;
using std::cin;
using std::endl;

// ------------------------------
// ------- MENU FUNCTIONS -------
// ------------------------------
void menu(std::vector<StudentGrading *> &students);
void showMenu(std::vector<StudentGrading *> &students);
void removeMenu(std::vector<StudentGrading *> &students);

int main() {
    // Used for storing all data in students
    std::vector<StudentGrading *> students;

    // Loading data from bin file
    StudentFileManager::load(students, "data.bin");

    menu(students);

    // Saving data to bin file
    StudentFileManager::save(students, "data.bin");

    // Freeing up space because we're creating objects dynamically
    for (StudentGrading *student : students) {
        delete student;
    }
    return 0;
}

// -------------------------
// ------- MAIN MENU -------
// -------------------------
void menu(std::vector<StudentGrading *> &students) {
    bool run = true;

    short choice;
    while (run) {
        cout << "1. Show students\n"
                "2. Add student\n"
                "3. Remove student\n"
                "0. Exit\n"
                "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                // SHOW MENU (for displaying data)
                showMenu(students);
                break;
            }
            case 2: {
                // ADD MENU (for adding data, initializes wizard for inputting data)
                cin.ignore();
                students.push_back(new StudentGrading());
                StudentFileManager::save(students, "data.bin");
                break;
            }
            case 3: {
                // REMOVE MENU (for removing data)
                removeMenu(students);
                StudentFileManager::save(students, "data.bin");
                break;
            }
            case 0: {
                // EXIT
                run = false;
                break;
            }
            default: {
                cout << "Wrong choice, please pick between 0-4." << endl;
            }
        }
    }
}

// -------------------------
// ------- SHOW MENU -------
// -------------------------
void showMenu(std::vector<StudentGrading *> &students) {
    cout << "1. Show all students\n"
            "2. Show all students from group\n"
            "3. Show average grades per group\n"
            "4. Show student with minimum average grade for selected group\n"
            "5. Show student with maximum average grade for selected group\n"
            "0. Back\n"
            "Choice: ";
    int choice;
    cin.clear();
    cin.ignore();
    cin >> choice;
    switch (choice) {
        case 1: {
            StudentPrinter::printStudents(students);
            break;
        }
        case 2: {
            StudentPrinter::printGroup(students);
            break;
        }
        case 3: {
            StudentPrinter::printAverageGradePerGroup(students);
            break;
        }
        case 4: {
            cout << "Group: ";
            short group;
            cin >> group;
            StudentPrinter::printMinAverageGrade(students, group);
            break;
        }
        case 5: {
            cout << "Group: ";
            short group;
            cin >> group;
            StudentPrinter::printMaxAverageGrade(students, group);
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << "[ERROR] Wrong choice. Choose between option 0 and 5." << endl;
        }
    }

}

// ---------------------------
// ------- REMOVE MENU -------
// ---------------------------
void removeMenu(std::vector<StudentGrading *> &students) {
    cout << "1. By name\n"
            "2. By faculty number\n"
            "0. Back\n";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            std::string nameToRemove;
            std::vector<int> indexToRemove;
            cout << "Name: ";
            cin.ignore();
            getline(cin, nameToRemove);
            if (nameToRemove.length() > 0) {
                for (int i = 0; i < students.size(); i++) {
                    if (students[i]->getName() == nameToRemove) {
                        indexToRemove.push_back(i);
                    }
                }
            }
            if (!indexToRemove.empty()) {
                for (auto &index : indexToRemove) {
                    students.erase(students.begin() + index);
                }
            } else {
                cout << "No users found with name " << nameToRemove << endl;
            }
            break;
        }
        case 2: {
            int facultyNumberToRemove;
            std::vector<int> indexToRemove;
            cout << "Faculty number: ";
            cin >> facultyNumberToRemove;
            for (int i = 0; i < students.size(); i++) {
                if (students[i]->getFacultyNumber() == facultyNumberToRemove) {
                    indexToRemove.push_back(i);
                }
            }
            if (!indexToRemove.empty()) {
                for (auto &index : indexToRemove) {
                    students.erase(students.begin() + index);
                }
            } else {
                cout << "No users found with faculty number " << facultyNumberToRemove << endl;
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

