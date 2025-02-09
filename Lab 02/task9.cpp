#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int marks;
};

int main() {

    int numStudents;
    cout << "Enter the number of Students: ";
    cin >> numStudents;
    cin.ignore();

    Student* Students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        cout << endl << "Enter data for Student #" << i + 1 << endl << endl;
        cout << "\tEnter Students's roll number: ";
        cin >> Students[i].rollNumber;
        cin.ignore();
        cout << "\tEnter Student name: ";
        getline(cin, Students[i].name);
        cout << "\tEnter marks: ";
        cin >> Students[i].marks;
        cin.ignore();
    }
    cout << endl;

    int highest = Students[0].marks;
    int index = 0;
    for (int i = 1; i < numStudents; i++) {
        if (Students[i].marks > highest) {
            highest = Students[i].marks;
            index = i;
        }
    }

    cout << endl << "Displaying Student with highest marks" << endl;
    cout << "\tName: " << Students[index].name << endl;
    cout << "\tRoll Number: " << Students[index]. rollNumber << endl;
    cout << "\tHighest Marks: " << Students[index].marks << endl;

    delete[] Students;

}







