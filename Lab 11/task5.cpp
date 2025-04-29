#include <iostream>

using namespace std;

class InsufficientFundsException : public exception {

    private:
        double deficit;
        string message;
    public:
        InsufficientFundsException(double def) : deficit(def) {
            message = "InsufficientFundsException - Deficit: $" + to_string(deficit);
        }
        const char* what() const noexcept override {
            return message.c_str();
        }

};

template <typename T>
class BankAccount {
    private:
        T balance;
    public:
        BankAccount(T bal = 1000) : balance(bal) {
            cout << "Balance: $" << balance << endl;
        }
        void withdraw(T amount) {
            if(amount > balance) {
                throw InsufficientFundsException(amount - balance);
            } else {
                balance -= amount;
                cout << "$ " << amount << " withdrawn!" << endl;
            }
        }
};

int main() {

    BankAccount <double>myAccount(509.90);

    try {
        cout << "Withdraw: $" << 800 << endl;
        myAccount.withdraw(800);
    } catch(InsufficientFundsException& e) {
        cout << e.what() << endl;
    }

}

