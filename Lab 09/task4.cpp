#include <iostream>
using namespace std;

class PaymentMethod {

    public:
        virtual void processPayment(double amount) = 0;

};

class CreditCard : public PaymentMethod {

    private:
        string cardNumber;
    public:
        CreditCard(string cN) : cardNumber(cN) {}
        void processPayment(double amount) {
            if(amount < 0 || amount > 5000) {
                cout << "Amount out of range(0-5000)... Cannot proceed transaction" << endl;
                return;
            }
            cout << "Transaction processed for amount " << amount << " via credit card" << endl;
        }

};

class DebitCard : public PaymentMethod {

    private:
        double balance;
    public:
        DebitCard(double b=5000) : balance(b) {}
        void processPayment(double amount) {
            if(amount > balance) {
                cout << "Amount exceeds the balance.. Cannot process transaction" << endl;
                return;
            } else if(amount < 0) {
                cout << "Amount cannot be negative.. Cannot process transaction" << endl;
                return;
            }

            balance -= amount;
            cout << "Transaction processed via debit card for the amount " << amount << ", Updated Balance: " << balance << endl;

        }

};

int main() {
    CreditCard c("987-654-321");
    DebitCard d(14000);
    c.processPayment(1500);
    d.processPayment(800);

    c.processPayment(8000);
    d.processPayment(15000);
}
