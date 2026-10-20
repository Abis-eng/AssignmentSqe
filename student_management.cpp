#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Code Smell: Unused global variables
int global_max_limit = 100;
int unused_variable = 999; 

struct Student {
    string n; // Poor naming convention
    int m1, m2, m3;
};

vector<Student> db; // Poor variable naming

// High Cyclomatic Complexity & Long Method Code Smell
void manageSystem() {
    int choice = 1;
    while (choice != 0) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Show Students (View 1)\n3. Show Students (View 2 - Duplicate)\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string name;
            int marks1, marks2, marks3;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter marks for 3 subjects: ";
            cin >> marks1 >> marks2 >> marks3;
            
            // Magic numbers & lack of validation bounds
            if (marks1 > 100 || marks2 > 100 || marks3 > 100) {
                cout << "Invalid marks entered!\n";
            } else {
                Student s;
                s.n = name;
                s.m1 = marks1;
                s.m2 = marks2;
                s.m3 = marks3;
                db.push_back(s);
                cout << "Student added successfully.\n";
            }
        } 
        else if (choice == 2) {
            // Intentional Code Duplication Block A
            cout << "\n--- Student List A ---\n";
            for(size_t i = 0; i < db.size(); i++) {
                cout << "Name: " << db[i].n << " | Marks: " << db[i].m1 << ", " << db[i].m2 << ", " << db[i].m3 << endl;
            }
        }
        else if (choice == 3) {
            // Intentional Code Duplication Block B (Exact copy for SonarQube Duplication metric)
            cout << "\n--- Student List B ---\n";
            for(size_t i = 0; i < db.size(); i++) {
                cout << "Name: " << db[i].n << " | Marks: " << db[i].m1 << ", " << db[i].m2 << ", " << db[i].m3 << endl;
            }
        }
    }
}

// Code Smell: Dead/Unused Function
void unusedFunctionToClean() {
    int a = 5;
    int b = 10;
    int sum = a + b;
    cout << sum << endl;
}

int main() {
    // Missing try-catch exception handling
    manageSystem();
    return 0;
}
