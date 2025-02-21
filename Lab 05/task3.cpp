#include <iostream>
using namespace std;

class Professor {

    private:
        string name;
        int id;
        string department;
    public:
        Professor(string n, int i, string d) : name(n), id(i), department(d) {}
        string getName() {
            return name;
        }
        string getDepartment() {
            return department;
        }
        int getID() {
            return id;
        }

};

class University {

    private:
        string name;
        string address;
        string* departments;
        int numDepartments;
        Professor **professors;
        int numProfessors;
    public:
        University(string n, string a) : name(n), address(a) {
            numProfessors = 0;
            professors = nullptr;

            cout << "Enter number of departments for university " << n << ": ";
            cin >> numDepartments;
            cin.ignore();
            departments = new string[numDepartments];
            for(int i = 0; i < numDepartments; i++) {
                cout << "Enter department #" << i + 1 << ": ";
                getline(cin, departments[i]);
            }
        }
        void displayProfessors() {
            if (numProfessors < 0) {
                cout << "No professors in university " << name << endl;
                return;
            }
            cout  << endl << "Displaying professors in university " << name << "..." << endl;
            for (int i = 0; i < numProfessors; i++) {
                cout << "ID: " << professors[i]->getID() << endl << "Name: " << professors[i]->getName() << endl << "Department: " << professors[i]->getDepartment() << endl;
            }
            cout << endl;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        void addProfessor(Professor * newProfessor) {
            string department = newProfessor->getDepartment();
            bool found = false;
            for(int i = 0; i < numDepartments; i++) {
                if (department == departments[i]) {
                    found = true;
                }
            }
            if(!found) {
                cout << "Department of professor " << newProfessor->getName() << " doesn't match with any in univeristy " << name << ", Cannot add!" << endl;
            }
            Professor** tempProfessors = new Professor*[numProfessors + 1];
            for (int i = 0; i < numProfessors; i++){
                tempProfessors[i] =  professors[i];
            }
            delete[] professors;
            tempProfessors[numProfessors] = newProfessor;
            professors = tempProfessors;
            numProfessors++;
        }
        void removeProfessor() {
            int ID;
            cout << "Enter ID for professor to be removed from university " << name << ": ";
            cin >> ID;
            cin.ignore();
            int index;
            bool found = false;
            for(int i = 0; i < numProfessors; i++) {
                if(professors[i]->getID() == ID) {
                    index = i;
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Professor with ID " << ID << " not found." << endl;
                return;
            }
            Professor** tempProfessors = new Professor*[numProfessors - 1];
            for (int i = 0; i < index; i++) {
                tempProfessors[i] = professors[i];
            }
            for (int i  = index + 1; i < numProfessors; i++) {
                tempProfessors[i - 1] = professors [i];
            }
            delete[] professors;
            professors = tempProfessors;
            numProfessors--;
        }
};


int main() {
    University fast("FAST-NUCES", "Shah Latif Town, Karachi");
    University iba("IBA", "Inside Karachi University, Karachi");
    
    Professor* atif = new Professor("Atif Tahir", 101, "Computer Science");
    Professor* talha = new Professor("Talha Shahid", 102, "Computer Science");
    Professor* sarah = new Professor("Sarah Ahmed", 103, "AI & DS");
    Professor* usman = new Professor("Usman Raza", 104, "SE");
    Professor* hina = new Professor("Hina Aslam", 105, "Management");
    Professor* ali = new Professor("Ali Haider", 106, "Accounting");
    Professor* zara = new Professor("Zara Khan", 107, "Finance");
    Professor* bilal = new Professor("Bilal Saeed", 108, "Economics");
    
    fast.addProfessor(atif);
    fast.addProfessor(talha);
    fast.addProfessor(sarah);
    fast.addProfessor(usman);
    fast.addProfessor(hina);
    
    iba.addProfessor(ali);
    iba.addProfessor(zara);
    iba.addProfessor(bilal);
    
    cout << "Displaying initial professors..." << endl;
    fast.displayProfessors();
    iba.displayProfessors();

    cout << "Professor leaving fast & joining IBA..." << endl;
    fast.removeProfessor();
    iba.addProfessor(atif);

    cout << "DIsplaying professors after transfer of one..." << endl;
    fast.displayProfessors();
    iba.displayProfessors();
    
    return 0;
}








