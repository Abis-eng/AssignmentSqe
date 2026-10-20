
#include <iostream>
#include <string>
using namespace std;

int unusedVariable = 100;

class Student {
public:
    string name;
    int roll;
    int marks;
};

Student students[100];
int countStudents = 0;

void addStudent() {
    string n;
    int r, m;
    cout << "Enter name: ";
    cin >> n;
    cout << "Enter roll number: ";
    cin >> r;
    cout << "Enter marks: ";
    cin >> m;

    students[countStudents].name = n;
    students[countStudents].roll = r;
    students[countStudents].marks = m;
    countStudents++;
}

void displayStudents() {
    for (int i = 0; i < countStudents; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Roll: " << students[i].roll << endl;
        cout << "Marks: " << students[i].marks << endl;
    }
}

void searchStudent() {
    int r;
    cout << "Enter roll number: ";
    cin >> r;
    for (int i = 0; i < countStudents; i++) {
        if (students[i].roll == r) {
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
        }
    }
}

void calculateAverage() {
    int total = 0;
    for (int i = 0; i < countStudents; i++)
        total += students[i].marks;
    cout << "Average: " << total / countStudents << endl;
}

void highestMarks() {
    int highest = 0;
    for (int i = 0; i < countStudents; i++) {
        if (students[i].marks > highest)
            highest = students[i].marks;
    }
    cout << "Highest marks: " << highest << endl;
}

int main() {
    int choice;
    int debugValue = 50;

    do {
        cout << "\n1. Add Student\n2. Display Students\n";
        cout << "3. Search Student\n4. Average Marks\n";
        cout << "5. Highest Marks\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            displayStudents();
        else if (choice == 3)
            searchStudent();
        else if (choice == 4)
            calculateAverage();
        else if (choice == 5)
            highestMarks();
        else if (choice != 0)
            cout << "Invalid choice\n";

    } while (choice != 0);

    return 0;
}
