#include <iostream>
using namespace std;

class Vehicle {
    private:
        string brand;
        int speed;
    public:
        Vehicle(string b, int s) : brand(b), speed(s) {} 
        void displayDetails() {
            cout << "Brand: " << brand << endl << "Speed: " << speed << "km/h"<< endl;
        }
};

class Car: public Vehicle {
    private:
        int seats;
    public:
        Car(string b, int s, int se) : Vehicle(b, s), seats(se) {}
        void displayDetails() {
            Vehicle::displayDetails();
            cout << "Seats: " << seats << endl;
        }
};

class ElectricCar : public Car {
    private:
        int batteryLife;
    public:
        ElectricCar(string b, int s, int se, int bL) : Car(b, s, se), batteryLife(bL) {}
        void displayDetails() {
            Car::displayDetails();
            cout << "Battery Life: " << batteryLife << "mAH" << endl;
        }
};

int main() {
    ElectricCar tesla("Tesla", 150, 2, 10000);
    tesla.displayDetails();
};

