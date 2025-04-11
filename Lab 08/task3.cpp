#include <iostream>
using namespace std;

class Student {

    private:
        string name;
        char grades[3];
    public:
        Student(string n, char g1, char g2, char g3) : name(n) {
            grades[0] = g1;
            grades[1] = g2;
            grades[2] = g3;
        }
        friend float computeAverageGrade(Student& s);
        friend class Teacher;
};

class Teacher {

    public:
        void viewStudentGrade(Student s) {
            cout << "Displaying Student " << s.name << "'s grades.." << endl;
            for (int i = 0; i < 3; i++) {
                cout << "Subject " << i + 1 << ": " << s.grades[i] << endl;
            }
        }
        void updateStudentGrade(Student& s, char g1, char g2, char g3) {
            cout << "Updating Student " << s.name << "'s grades.." << endl;
            s.grades[0] = g1;
            s.grades[1] = g2;
            s.grades[2] = g3;
        }

};

float computeAverageGrade(Student& s) {
    float total = 0.0;

    for (int i = 0; i < 3; i++) {
        switch (s.grades[i]) {
            case 'A': total += 4.0; break;
            case 'B': total += 3.0; break;
            case 'C': total += 2.0; break;
            case 'D': total += 1.0; break;
            case 'F': total += 0.0; break;
            default: cout << "Invalid grade: " << s.grades[i] << endl;
        }
    }

    return total / 3.0;
}

int main() {
    Student s1("Ismail Silat", 'A', 'B', 'C');
    Teacher t;

    t.viewStudentGrade(s1);
    cout << "Average Grade Point: " << computeAverageGrade(s1) << endl;

    t.updateStudentGrade(s1, 'A', 'A', 'B');
    t.viewStudentGrade(s1);
    cout << "Updated Average Grade Point: " << computeAverageGrade(s1) << endl;

    return 0;
}

