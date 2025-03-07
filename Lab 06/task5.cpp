#include <iostream>
using namespace std;

class Device {

    private:
        int deviceID;
        bool status;
    public:
        Device(int ID, bool s) : deviceID(ID), status(s) {}
        void virtual displayDetails() {
            cout << "Device ID: " << deviceID << endl;
            cout << "Status: " << ((status) ? "Yes" : "No") << endl;
        }

};

class SmartPhone : virtual public Device {

    private:
        float screenSize;
    public:
        SmartPhone(int ID, bool s, float sS) : Device(ID, s), screenSize(sS) {}
        float getScreenSize() { return screenSize; }
        void displayDetails() {
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << endl;
        }

};

class SmartWatch : virtual public Device {

    private:
        bool heartRateMonitor;
    public:
        SmartWatch(int ID, bool s, bool hRM) : Device(ID, s), heartRateMonitor(hRM) {}
        bool getHeartRateMonitor() { return heartRateMonitor; }
        void displayDetails() {
            Device::displayDetails();
            cout << "Heart Rate Monitor: " << ((heartRateMonitor) ? "Yes" : "No") << endl;
        }

};

class SmartWearable : public SmartWatch, public SmartPhone {

    private:
        int stepCounter;
    public:
        SmartWearable(int ID, bool s, float sS, bool hRM, int sC) : stepCounter(sC), Device(ID, s), SmartPhone(ID, s, sS), SmartWatch(ID, s, hRM) {}
        void displayDetails() override {
            Device::displayDetails();
            cout << "Screen Size: " << getScreenSize() << endl;
            cout << "Heart Rate Monitor: " << ((getHeartRateMonitor()) ? "Yes" : "No") << endl;
            cout << "Step Counter: " << stepCounter << endl;
        }
};

int main() {
    SmartWearable newWatch(1, true, 150, false, 17);
    newWatch.displayDetails();
}
