#include<iostream>
using namespace std;

class Patient {
    private:
        int id;
        string name;
        float *results;
        int numTests;         

    public:
        Patient(int i, string n, int num) : id(i), name(n), numTests(num) {
            results = new float[numTests];  
            cout << "Test results:" << endl;
            for (int i = 0; i < numTests; i++) {
                cout << "Test " << i + 1 << ": ";
                cin >> results[i];
            }
        }

        Patient(Patient &obj) {
            id = obj.id;
            name = obj.name;
            numTests = obj.numTests;
            results = new float[numTests];  
            for (int i = 0; i < numTests; i++) {
                results[i] = obj.results[i];  
            }
        }

        ~Patient() {
            delete[] results; 
        }

        void displayDetails() {
            cout << endl << "Patient ID: " << id<< ", Name: " << name << endl << "Test Results: ";
            for (int i = 0; i < numTests; i++) {
                cout << results[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Patient ismail(12, "Ismail Silat", 3);
    ismail.displayDetails();
    Patient patient2 = ismail;  
    patient2.displayDetails();
}