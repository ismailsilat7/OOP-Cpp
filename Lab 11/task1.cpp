#include <iostream>
#include <cstdlib>
using namespace std;

class InvalidValueException : public exception {

    public:
        const char* what() const noexcept override {
            return "InvalidValueException - Age cannot be negative or exceed 120";
        }

};

bool validateAge(int age) {
    if(age < 0 || age > 120) {
        throw InvalidValueException();
    } else {
        return true;
    }
}

int main() {

    int age;
    cout << "Enter age: ";
    cin >> age;
    try {
        if(validateAge(age)) {
            cout << "Age is valid" << endl;
        }
    } catch(const InvalidValueException& e) {
        cout << e.what() << endl;
        exit(0);
    }

}


