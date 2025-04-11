#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int num = 0, int den = 1) {
            if (den == 0) {
                cout << "Denominator can't be zero! Set as 1" << endl;
                den = 1;
            }
            numerator = num;
            denominator = den;
        }

        Fraction operator+(const Fraction& f) const {
            return Fraction(numerator * f.denominator + f.numerator * denominator,denominator * f.denominator);
        }

        Fraction operator-(const Fraction& f) const {
            return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
        }

        Fraction operator*(const Fraction& f) const {
            return Fraction(numerator * f.numerator, denominator * f.denominator);
        }

        Fraction operator/(const Fraction& f) const {
            return Fraction(numerator * f.denominator, denominator * f.numerator);
        }

        friend ostream& operator<<(ostream& out, const Fraction& f);

};

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

int main() {
    Fraction f1(1, 2), f2(1, 4);

    cout << "f1: 1/2, f2: 1/4" << endl;
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    return 0;
}

