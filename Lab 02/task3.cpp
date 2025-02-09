#include <iostream>
using namespace std;

struct Employee {
    int employeeID;
    string name;
    string department;
    float salary;
};

void displayEmployees(Employee* Employees, int numEmployees) {
    cout << "Displaying Employees Details" << endl;

    for (int i = 0; i < numEmployees; i++) {
        cout << endl;
        cout << "Employee #" << i + 1 << endl;
        cout << "\tID: " << Employees[i].employeeID << endl;
        cout << "\tName: " << Employees[i].name << endl;
        cout << "\tDepartment: " << Employees[i].department << endl;
        cout << "\tSalary: $" << Employees[i].salary << endl;
    }
}

void searchEmployee(Employee* Employees, int numEmployees, int ID) {

    cout << "Searching for Employee with EmployeeID = " << ID << "..." << endl;
    bool found = false;
    int index;
    for (int i = 0; i < numEmployees; i++) {
        if(Employees[i].employeeID == ID) {
            found = true; 
            index = i;
            break;
        }
    }

    if (found) {
        cout << "Employee found at index: " << index + 1 << endl;
    } else {
        cout << "Employee not found" << endl;
    }

}

int main() {

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    cin.ignore();

    Employee* Employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter data for Employee #" << i + 1 << endl;
        cout << "Enter Employee ID: ";
        cin >> Employees[i].employeeID;
        cin.ignore();
        cout << "Enter Employee name: ";
        getline(cin, Employees[i].name);
        cout << "Enter department: ";
        getline(cin, Employees[i].department);
        cout << "Enter Salary: $";
        cin >> Employees[i].salary;
        cin.ignore();
    }
    
    displayEmployees(Employees, numEmployees);

    int searchID;
    cout << "Enter the ID for employee to search: ";
    cin >> searchID;
    cin.ignore();
    searchEmployee(Employees, numEmployees, searchID);

    delete[] Employees;

}





