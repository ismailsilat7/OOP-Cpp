#include <iostream>
using namespace std;

class Account {

    private:
        int accountNumber;
        float balance;
    public:
        Account(int aN, float b) : accountNumber(aN), balance(b) {}
        void displayDetails() {
            cout << "Account Number: " << accountNumber << endl << "Balance: $" << balance << endl;
        }

};

class SavingsAccount : public Account {

    private:
        float interestRate;
    public:
        SavingsAccount(int aN, float b, float iR) : Account::Account(aN, b), interestRate(iR) {}
        void displayDetails() {
            Account::displayDetails();
            cout << "Interest Rate: " << interestRate << endl;
        }

};


class CheckingAccount : public Account {

    private:
        float overDraftLimit;
    public:
        CheckingAccount(int aN, float b, float oDL) : Account::Account(aN, b), overDraftLimit(oDL) {}
        void displayDetails() {
            Account::displayDetails();
            cout << "Over Draft Limit: " << overDraftLimit << endl;
        }

};

int main() {
    SavingsAccount acc1(1, 1900.00, 5);
    CheckingAccount acc2(2, 1800.05, 2000);
    acc1.displayDetails();
    acc2.displayDetails();
}
