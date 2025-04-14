#include <iostream>
using namespace std;

class Vehicle {

    protected:
        string model;
        double rate;
    public:
        Vehicle(string m, double r) : model(m), rate(r) {}
        virtual double getDailyRate() = 0;
        virtual void displayDetails() = 0;

};

class Car : public Vehicle {

    public:
        Car(string m, double r) : Vehicle(m,r) {}
        double getDailyRate() { return rate * 1.1; }
        void displayDetails() { 
            cout << "Displaying car details..." << endl;
            cout << "Model: " << model << endl << "Rate: " << getDailyRate() << endl;
        }
        
};

class Bike : public Vehicle {

    public:
        Bike(string m, double r) : Vehicle(m,r) {}
        double getDailyRate() { return rate; }
        void displayDetails() { 
            cout << "Displaying Bike details..." << endl;
            cout << "Model: " << model << endl << "Rate: " << getDailyRate() << endl;
        }
        
};

int main() {
    Car c("City", 15.8);
    c.displayDetails();

    Bike b("Honda", 12.9);
    b.displayDetails();
}
