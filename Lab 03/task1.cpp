#include <iostream>
using namespace std;

class MarkerPen {

    private:
        string brand;
        string color;
        float inkLevel;
        bool refillability;
    
    public: 
        MarkerPen(string b, string c, bool r) {
            brand = b;
            color = c;
            inkLevel = 100.0;
            refillability = r;
        }
        void write() {
            if(inkLevel > 0) {
                inkLevel -= 5.0;
                cout << "Writing..." << endl;
                cout << "Done writing" << endl;
            } else {
                cout << "Marker has run out of ink" << endl;
            }
        }
        void refill() {
            if(refillability) {
                cout << "Ink Level set to 100";
                inkLevel = 100.0;
            } else {
                cout << "The marker cannot be refilled" << endl;
            }
        }
        void checkStatus() {
            cout << endl;
            cout << "Brand: " << brand << "\nColor: " << color << "\nInk Level: " << inkLevel << "/100\nRefillable: " <<((refillability) ? "Yes" : "No") << endl << endl;
        }

};

int main() {

    MarkerPen ahmedsPen("Dollar", "Blue", true);
    ahmedsPen.checkStatus();
    ahmedsPen.write();
    ahmedsPen.checkStatus();
    ahmedsPen.refill();

}
