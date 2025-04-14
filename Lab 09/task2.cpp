#include <iostream>
using namespace std;

class SmartDevice {

    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool getStatus() = 0;

};

class LightBulb : public SmartDevice {

    private:
        bool isOn;
        int brightness;
    public:
        LightBulb() : isOn(false), brightness(0) {}
        void turnOn() {
            isOn = true;
            brightness = 75;
            cout << "LightBulb turned on.. Brightness level set as " << brightness << endl;
        }
        void turnOff() {
            isOn = false;
            brightness = 0;
            cout << "LightBulb turned off.. Brightness level set as " << brightness << endl;
        }
        bool getStatus() {
            return isOn; 
        }

};

class Thermostat : public SmartDevice {
    private:
        bool isOn;
        double temperature;
    public:
        Thermostat() : isOn(false), temperature(25) {}
        void turnOn() {
            isOn = true;
            temperature = 30;
            cout << "Thermostat turned on.. Temperature level is now " << temperature << endl;
        }
        void turnOff() {
            isOn = false;
            temperature = 25;
            cout << "Thermostat turned off.. Temperature level is now " << temperature << endl;
        }
        bool getStatus() { return isOn; }
};

int main() {
    LightBulb lb;
    Thermostat t;
    lb.turnOn();
    lb.turnOff();

    t.turnOn();
    t.turnOff();
}

