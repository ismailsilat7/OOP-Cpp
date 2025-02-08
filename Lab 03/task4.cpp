#include <iostream>
using namespace std;

class Laptop {
    private:
        string brand;
        string model;
        string processor;
        int ram; // in GB
        int storage; // in GB
        bool power = false;
    public: 
        Laptop(string b, string m, string p, int r, int s) {
            brand = b;
            model = m;
            processor = p;
            ram = r;
            storage = s;
        }
        void pressPowerButton() {
            if(power) {
                cout << brand << ", " << model << " is shutting Down..." << endl;
            } else {
                cout << brand << ", " << model << "is powering on..." << endl;
            }
            power = !power;
        }
        void runProgram(string p) {
            if(!power) {
                cout << "Please power on to run " << p << endl;
            } else {
                cout << "Running " << p << "..." << endl;
            }
        }
        void checkSpecifications() {
            cout << endl << "Displaying Specs for " << brand << ", " << model << endl;
            cout << "\tProcessor: " << processor << "\n\tRAM: " << ram << "\n\tStorage: " << storage << endl << endl; 
        }
};

int main() {
    Laptop bilalLaptop("Dell", "Inspiron 15", "Intel Core i5", 8, 512);
    Laptop ayeshaLaptop("HP", "Pavilion x360", "AMD Ryzen 7", 16, 1024);

    bilalLaptop.checkSpecifications();
    ayeshaLaptop.checkSpecifications();

    bilalLaptop.pressPowerButton();
    bilalLaptop.runProgram("Microsoft Word");
    bilalLaptop.pressPowerButton();

    cout << endl; 
    
    ayeshaLaptop.pressPowerButton();
    ayeshaLaptop.runProgram("Adobe Photoshop");
    ayeshaLaptop.pressPowerButton();

    return 0;
}

