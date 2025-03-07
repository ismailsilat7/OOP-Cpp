#include <iostream>
using namespace std;

class Employee {
    private:
        string name;
        float salary;
    public:
        Employee(string n, float s) : name(n), salary(s) {}
        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Manager : public Employee {
    private:
        float bonus;
    public:
        Manager(string n, float f, float b) : Employee(n, f), bonus(b) {}
        void displayDetails() {
            Employee::displayDetails();
            cout << "Bonus: " << bonus << endl;
        }
};

int main() {
    Manager ismail("Ismail Silat", 25000.95, 555.8);
    ismail.displayDetails();
}

