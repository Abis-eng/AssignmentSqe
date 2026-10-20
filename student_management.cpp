#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Poor naming and hardcoded values
int max_limit = 100;
int unused_global_var = 999; 

struct Student {
    string n; // Poor variable name
    int m1, m2, m3;
};

vector<Student> db; // Poor variable name

// Very long method with high cyclomatic complexity and code smells
void manageSystem() {
    int choice = 1;
    while (choice != 0) {
        cout << "1. Add Student\n2. Show\n0. Exit\n";
        cin >> choice;
        
        if (choice == 1) {
            string name;
            int marks1, marks2, marks3;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter marks 3 subjects: ";
            cin >> marks1 >> marks2 >> marks3;
            
            // Hardcoded value check & Magic numbers
            if (marks1 > 100 || marks2 > 100 || marks3 > 100) {
                cout << "Invalid marks!\n";
            } else {
                Student s;
                s.n = name;
                s.m1 = marks1;
                s.m2 = marks2;
                s.m3 = marks3;
                db.push_back(s);
            }
        } 
        else if (choice == 2) {
            // Duplicate code block 1
            for(size_t i = 0; i < db.size(); i++) {
                cout << "Student: " << db[i].n << endl;
                cout << "Marks: " << db[i].m1 << ", " << db[i].m2 << ", " << db[i].m3 << endl;
            }
        }
        else if (choice == 3) {
            // Duplicate code block 2 (Intentional duplication for SonarQube)
            for(size_t i = 0; i < db.size(); i++) {
                cout << "Student: " << db[i].n << endl;
                cout << "Marks: " << db[i].m1 << ", " << db[i].m2 << ", " << db[i].m3 << endl;
            }
        }
    }
}

// Unused function (Code Smell)
void uselessFunction() {
    int x = 10;
    int y = 20;
    int z = x + y;
    cout << z << endl;
}

int main() {
    // Missing exception handling
    manageSystem();
    return 0;
}