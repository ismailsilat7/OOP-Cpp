#include <iostream>
#include "math.h"
#include <typeinfo>
using namespace std;

class NegativeNumberException : public exception {
  
    public:
        const char* what() const noexcept override {
            return "NegativeNumberException - Number must be non-negative";
        }

};

class InvalidTypeException : public exception {
  
    public:
        const char* what() const noexcept override {
            return "InvalidTypeException - Non-numeric data type detected!";
        }

};

template <typename T>
T squareroot(T num) {
    if(num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(num);
    
}

double squareroot(const char* num) {
    throw InvalidTypeException();
}

double squareroot(string num) {
    throw InvalidTypeException();
}


int main() {

    try {
        cout << "sqrt(-4): ";
        cout << squareroot(-4) << endl;
    }
    catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): ";
        cout << squareroot("hello") << endl;
    }
    catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(9): ";
        cout << squareroot(9) << endl;
    }
    catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
    }


}

