#include <iostream>
using namespace std;

class Car {
    private:
        int registrationNumber;
        string model;
        string owner;
    public:
        Car(int r, string m, string o) : registrationNumber(r), model(m), owner(o) {}
        Car(const Car& c) {
            registrationNumber = c.registrationNumber;
            model = c.model;
            cout << "Enter New Owner: ";
			getline(cin, owner);
        }
        void display() {
            cout << "Car Details; Registration Number: " << registrationNumber << ", Model: " << model << ", Owner: " << owner << endl << endl;
        }
};

int main() {
    Car c1(101, "BMW M5 Sedan", "Ismail");
    c1.display();

    Car c2 = Car(c1);
    c2.display();

    return 0;
}


