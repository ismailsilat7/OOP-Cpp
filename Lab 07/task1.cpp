#include <iostream>
using namespace std;

class Account {

    protected:
        int accountNumber;
        float balance;
        string accountHolderName;
        string accountType;
    public:
        
        Account(int aN, float b, string n, string t) : accountNumber(aN), balance(b), accountHolderName(n), accountType(t) {}
        void deposit(float amount)  {
            balance += amount;
            cout << "Amount Deposited" << endl;
            cout << "Updated Balance: $" << balance << endl;
        } 
        virtual void withdraw(float amount) {
            if(amount > balance) {
                cout << "Cannot withdraw! Amount > Balance" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn" << endl;
                cout << "Updated Balance: $" << balance << endl;
            }
        }
        virtual void calculateInterest() {
            cout << "Calculating interest..." << endl;
        }
        virtual void printStatement() {
            cout << "Printing transaction history..." << endl;
        }
        void getAccountInfo() {
            cout << "Account Number: " << accountNumber << endl << "Balance: " << balance << endl << "Account Holder Name: " << accountHolderName << endl << "Account Type: " << accountType << endl;
        }

};

class SavingsAccount : public Account {
    private:
        float interestRate;
        float minimumBalance;
    public:
        SavingsAccount(int aN, float b, string n, string t, float iR, float mB) : Account(aN, b, n, t), interestRate(iR), minimumBalance(mB) {}
        void calculateInterest() override {
            cout << "Calculating interest for savings account.." << endl;
            float interest = interestRate * (balance/100);
            cout << "Interest for amount $" << balance << " is $" << interest << endl;
        }
        void printStatement() override {
            cout << "Printing transaction history for savings account..." << endl;
        }
        void withdraw(float amount) override {
            cout << "Withdrawing amount from a savings account" << endl;
            if (amount > balance) {
                cout << "Cannot withdraw! Amount > Balance" << endl;
            } else if (balance - amount < minimumBalance) {
                cout << "Cannot withdraw! Amount will drop below minimum balance" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn" << endl;
                cout << "Updated Balance: $" << balance << endl;
            }
        }
};

class FixedDepositAccount : public Account {
    private:
        float fixedInterestRate;
        string maturityDate;
    public:
        FixedDepositAccount(int aN, float b, string n, string t, float fIR, string mD) : Account(aN, b, n, t), fixedInterestRate(fIR), maturityDate(mD) {}
        void calculateInterest() override {
            cout << "Calculating interest for fixed deposit account.." << endl;
            float interest = fixedInterestRate * (balance/100);
            cout << "Interest for amount $" << balance << " is $" << interest << endl;
        }
        void printStatement() override {
            cout << "Printing transaction histories for fixed deposit account..." << endl;
        }
        
};

class CheckingAccount : public Account {

    private:
        float overDraftLimit;
    public:
        CheckingAccount(int aN, float b, string n, string t, float oDL) : Account(aN, b, n, t), overDraftLimit(oDL) {}
        void calculateInterest() override {
            cout << "Checking accounts do not have interest" << endl;
        }

        void printStatement() override {
            cout << "Printing transaction history for checking account..." << endl;
        }

        void withdraw(float amount) override {
            if(amount > balance + overDraftLimit) {
                cout << "Cannot withdraw! Amount > Balance + over draft limit" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn" << endl;
                cout << "Updated Balance: $" << balance << endl;
            }
        }

};

int main() {
    SavingsAccount savings(1001, 5000, "Ali", "Savings", 3.5, 1000);
    FixedDepositAccount fixed(1002, 10000, "Ismail", "Fixed Deposit", 5.0, "2026-12-31");
    CheckingAccount checking(1003, 2000, "Meow", "Checking", 500);

    cout << "Outputs for Savings Account" << endl;
    savings.getAccountInfo();
    savings.deposit(1000);
    savings.withdraw(2000);
    savings.calculateInterest();
    savings.printStatement();
    cout << endl << endl << "Outputs for Fixed Deposit Account" << endl;
    fixed.getAccountInfo();
    fixed.deposit(2000);
    fixed.withdraw(3000);
    fixed.calculateInterest();
    fixed.printStatement();
    cout << endl << endl << "Outputs for Checking Account" << endl;
    checking.getAccountInfo();
    checking.deposit(500);
    checking.withdraw(3000);
    checking.calculateInterest();
    checking.printStatement();

}