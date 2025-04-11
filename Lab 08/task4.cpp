#include <iostream>
using namespace std;

class Currency {

    private:
        float money;
    public:
        Currency(float m) : money(m) {}
        Currency operator-() {
            return Currency(-money);
        }
        Currency operator+(Currency c) {
            return Currency(money + c.money);
        }
        Currency operator-(Currency c) {
            return Currency(money - c.money);
        }
        Currency operator+=(Currency c) {
            money += c.money;
            return *this;
        }
        Currency operator-=(Currency c) {
            money -= c.money;
            return *this;
        }
        void display() {
            cout << "Money: " << money << endl;
        }        
};

int main() {
    Currency c1(100);
    Currency c2(50);
    Currency c3 = -c2;
    Currency c4 = c1 + c3;
    Currency c5 = c3 - c2;

    c1 += c2;
    c2 -= c3;

    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();
}

