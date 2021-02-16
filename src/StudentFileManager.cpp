//
// Created by Ivan Sandev on 2/16/21.
//

#include "../include/StudentFileManager.h"

// Save data to binary file
void StudentFileManager::save(std::vector<StudentGrading *> &students, std::string filename) {
    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::binary);

    // Verifies binary file
    if (file.good()) {
        int size = students.size();
        file.write(reinterpret_cast<char *> (&size), sizeof(int));
        for (auto &student : students) {
            student->saveBinary(file);
        }
        file.close();
    } else {
        cout << "[ERROR] Cannot open file " << filename << " for writing." << endl;
    }
}

// Load data from binary file
void StudentFileManager::load(std::vector<StudentGrading *> &students, std::string filename) {
    std::ifstream file;
    file.open(filename, std::ios::in | std::ios::binary);

    // Verifies bin file
    if (file.good()) {
        int size = 0;
        file.read(reinterpret_cast<char *> (&size), sizeof(int));
        for (int i = 0; i < size; i++) {
            students.push_back(new StudentGrading(file));
        }
        file.close();
    } else {
        cout << "[WARNING] Data file " << filename << " not found." << endl;
        cout << "          If it's the first the running the program, please ignore this message." << endl << endl;
    }
}