#include <iostream>
using namespace std;

class Student;
class Professor;

class Course {
    private:
        int courseID;
        string name;
        int credits;
        Professor* instructor;
        string schedule;
    public:
        Course(int cID, string n, int cr, Professor* instr, string sched) : courseID(cID), name(n), credits(cr), instructor(instr), schedule(sched) {
            assignProfessor();
        }
        void registerStudent(Student * s);
        void assignProfessor();
        void displayDetails() {
            cout << "CourseID: " << courseID << endl << "CourseName: " << name << endl << "Credit Hours: " << credits << endl << "Schedule: " << schedule << endl;
        }
        string getName() { return name; }
};

class Person {
    protected:
        string name;
        int id;
        string address;
        string phoneNumber;
        string email;
    public:
        Person(string n, int i, string a, string pN, string e) : name(n), id(i), address(a), phoneNumber(pN), email(e) {}
        virtual void displayInfo() {
            cout<< "ID: " << id << endl << "Name: " << name << endl << "Address: " << address << endl << "Phone Number: " << phoneNumber << endl << "Email: " << email << endl;
        }
        void updateInfo(string a, string pN, string e) {
            address = a;
            phoneNumber = pN;
            email = e;
        }
};

class Student : public Person {

    private:
        Course** coursesEnrolled;
        float GPA;
        int enrollmentYear;
        int numCourses;
    public:
        Student(string n, int i, string a, string pN, string e, float g, int year) : Person(n, i, a, pN, e), GPA(g), enrollmentYear(year), numCourses(0), coursesEnrolled(nullptr) {}
        void displayInfo() override {
            cout<< "ID: " << id << endl << "Name: " << name << endl << "GPA: " << GPA << endl << "Enrollment Year: " << enrollmentYear << endl << "Courses Enrolled:" << endl;
            for(int i = 0; i < numCourses; i++) {
                coursesEnrolled[i]->displayDetails();
                cout << endl;
            }
        }
        void enrollInCourse(Course *c ) {
            Course** tempEnrolled = new Course*[numCourses + 1];
            for(int i = 0; i < numCourses; i++) {
                tempEnrolled[i] = coursesEnrolled[i];
            }
            tempEnrolled[numCourses] = c;
            delete[] coursesEnrolled;
            coursesEnrolled = tempEnrolled;
            numCourses++;
            cout << name << " enrolled in course " << c->getName() << endl;
        }
};

void Course::registerStudent(Student * s) {
    s->enrollInCourse(this);
}

class Professor : public Person {
    private:
        string department;
        Course** coursesTaught;
        int numCourses;
        float salary;
    public:
        Professor(string n, int i, string a, string pN, string e, string dept, float sal) : Person(n, i, a, pN, e), department(dept), salary(sal), numCourses(0), coursesTaught(nullptr) {}
        void displayInfo() override {
            cout<< "ID: " << id << endl << "Name: " << name << endl << "Department: " << department << endl << "Salary: " << salary << endl << "Courses Taught: " << endl;
            for(int i = 0; i < numCourses; i++) {
                coursesTaught[i]->displayDetails();
                cout << endl;
            }
        }
        void assignCourse(Course* c) {
            Course** tempCourses = new Course * [numCourses + 1];
            for (int i = 0; i < numCourses; i++) {
                tempCourses[i] = coursesTaught[i];
            }
            tempCourses[numCourses] = c;
            delete[] coursesTaught;
            coursesTaught = tempCourses;
            numCourses++;
            cout << name << " assigned to course " << c->getName() << endl;
        }
};

void Course::assignProfessor() {
    instructor->assignCourse(this);
}

class Staff : public Person {
    private:
        string department;
        string position;
        float salary;
    public:
        Staff(string n, int i, string a, string pN, string e, string dept, string pos, float sal) : Person(n, i, a, pN, e), department(dept), position(pos), salary(sal) {}
        void displayInfo() override {
            cout << "ID: " << id << endl << "Name: " << name << endl << "Department: " << department << endl << "Salary: " << salary << endl << "Position: " << position << endl;
        }
};


int main() {
    Professor prof1("Talha Shahid", 1, "North Karachi", "123-456-7890", "talha@nu.edu.pk", "Computer Science", 150000);
    Professor prof2("Arif Khan", 2, "East Karachi", "987-654-3210", "arif@nu.edu.pk", "Humanities", 140000);

    Staff staff1("Khan Afzal", 1, "Gulshan", "0-900-786-01", "afzal@nu.edu.pk", "Computer Science", "Head", 145000);

    Student student1("Ismail", 1, "Khalid Bin Waleed Road", "111-222-3333", "ismail@nu.edu.pk", 3.8, 2022);
    Student student2("Ali", 2, "Maripur", "444-555-6666", "ali@nu.edu.pk", 3.8, 2022);

    Course course1(1, "OOP", 4, &prof1, "Monday 10:00-11:30 AM");
    Course course2(2, "Applied Physics", 3, &prof2, "Tuesday 9:00-10:30 AM");

    student1.enrollInCourse(&course1);
    student2.enrollInCourse(&course1);
    student1.enrollInCourse(&course2);

    cout << "\n--- Professor Details ---\n";
    prof1.displayInfo();
    prof2.displayInfo();

    cout << "\n--- Student Details ---\n";
    student1.displayInfo();
    student2.displayInfo();

}
