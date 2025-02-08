#include <iostream>
using namespace std;

class TeaMug {

    private:  
        string brand;
        string color;
        float capacity;
        float currentFillLevel;
    
    public:
        TeaMug(string b, string co, float ca, float cfl) {
            brand = b;
            color = co;
            if(ca < 0) {
                capacity = 0.00;
                cout << "Capacity cannot be negative, set as 0" << endl;
            } else {
                capacity = ca;
            }
            if (cfl < 0) {
                cout << "Fill Level cannot be negative, set as 0" << endl;
                currentFillLevel = 0;
            } else {
                currentFillLevel = cfl;
            }
        }
        void sipTea() {
            if(currentFillLevel <= 0) {
                cout << "The cup is empty, please refill" << endl;
                return;
            }
            cout << "Taking a sip..." << endl;
            currentFillLevel -= 5;
            if(currentFillLevel <= 5) {
                cout << "Time for a fresh cup!" << endl;
            }
        }
        void isEmpty() {
            if(currentFillLevel <= 0) {
                cout << "The cup is empty" << endl;
            } else {
                if(currentFillLevel == 5) {
                    cout << "Ahh - One last sip left" << endl;
                } else {
                    cout << "The cup isn't empty, there are still " << currentFillLevel/5 << " sips left :)" << endl;
                }
            }
        }

        void refill() {
            if(currentFillLevel == capacity) {
                cout << "The cup is already full, can't refill" << endl;
            } else {
                currentFillLevel = capacity;
                cout << "Cup refilled!" << endl;
            }
        }
};

int main() {

    TeaMug myMug("Ceramic Co.", "White", 150.0, 15.0);
    myMug.isEmpty();
    myMug.sipTea();
    myMug.sipTea();
    myMug.isEmpty();
    myMug.sipTea();
    myMug.isEmpty();
    myMug.sipTea();
    myMug.refill();
    myMug.isEmpty();
}


