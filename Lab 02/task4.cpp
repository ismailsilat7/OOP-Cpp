#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int marks[5];
};

struct Result {
    float avgMarks;
    char grade;
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
        for (int j = 0; j < 5; j++) {
            cout << "\tEnter marks for Subject " << j + 1 << ": ";
            cin >> Students[i].marks[j];
        }
        cin.ignore();
    }
    cout << endl;

    Result* Results = new Result[numStudents];

    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += Students[i].marks[j];
        }
        Results[i].avgMarks = sum/5;
        if (Results[i].avgMarks >= 80) {
            Results[i].grade = 'A';
        } else if(Results[i].avgMarks >= 70) {
            Results[i].grade = 'B';
        } else if(Results[i].avgMarks >= 60) {
            Results[i].grade = 'C';
        } else if(Results[i].avgMarks >= 50) {
            Results[i].grade = 'D';
        } else {
            Results[i].grade = 'F';
        }
    }

    cout << endl << "Displaying Results" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << endl << "Student #" << i + 1 << endl << endl;;
        cout << "\tName: " << Students[i].name << endl;
        cout << "\tRoll Number: " << Students[i]. rollNumber << endl;
        cout << "\tAverage Marks: " << Results[i].avgMarks << endl;
        cout << "\tGrade: " << Results[i].grade << endl;
    }

    delete[] Students;
    delete[] Results;

}


