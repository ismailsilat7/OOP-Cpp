#include <iostream>
using namespace std;

class Battery {
    private:
        int capacity;
        float percentage;
    public:
        Battery() : capacity(1000), percentage(100.0)  { }
        Battery(int c) : capacity(c), percentage(100.0) { }
        int getCapacity() {
            return capacity;
        }
        float getPercentage() {
            return percentage;
        }
        void chargeBattery() {
            if (percentage == 100) {
                cout << "Battery is already 100%...Cannot charge!" << endl;
                return;
            }
            percentage = 100.0;
            cout << "Battery is now 100%." << endl;
        }
        void drainBattery() {
            if(percentage == 0) {
                cout << "Your phone is dead... please charge it to use again!" << endl;
                return;
            }
            if(percentage <=  20) {
                cout << "Charge your phone! it's about to Die... Already at "  << percentage << "%." << endl;
            }
            percentage -= 5;
            cout << "Battery is now at " << percentage << "%." << endl;
        }
};

class SmartPhone {
    private:
        Battery battery;
        string name;
        string model;
    public:
        SmartPhone(string n, string m, int c) : name(n), model(m), battery(c) { }
        void getDetails() {
            cout << "Displaying details..." << endl;
            cout << "Name: " << name << endl;
            cout << "Model: " << model << endl;
            cout << "Battery Capacity: " << battery.getCapacity() << " mAh" << endl;
            cout << "Battery Percentage: " << battery.getPercentage() << "%" << endl;
        }
        void chargePhone() {
            cout << "Charging Phone " << name << "..." << endl;
            battery.chargeBattery();
        }
        void usePhone() {
            cout << "Using phone " << name << "..." << endl;
            battery.drainBattery();
        }
};

int main() {
    SmartPhone phone1("Samsung", "Galaxy S24", 5000);

    phone1.getDetails();
    phone1.usePhone();
    phone1.chargePhone();

    return 0;
}
