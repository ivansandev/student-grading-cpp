#include <iostream>
#include <vector>
#include "StudentGrading.h"

using std::cout;
using std::cin;
using std::endl;

// MENU FUNCTIONS
void menu();
void showMenu();
void addMenu();
void removeMenu();
void changeMenu();

// REQUIRED FUNCTIONS
void averageGradePerGroup();
void minAverageGrade(short group);
void maxAverageGrade(short group);
void print();
void printGroup(short group);

int main() {
    std::vector<StudentGrading> students;

    menu();

    return 0;
}

void menu() {
    bool run = true;

    short choice;
    while (run) {
        cout << "1. Show\n"
                "2. Add\n"
                "3. Remove\n"
                "4. Change\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                showMenu();
                break;
            }
            case 2: {
                addMenu();
                break;
            }
            case 3: {
                removeMenu();
                break;
            }
            case 4: {
                changeMenu();
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

