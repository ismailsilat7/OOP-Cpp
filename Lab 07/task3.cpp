#include <iostream>
using namespace std;


class Currency {
    protected:
        float amount;
        string currencyCode, currencySymbol;
        float exchangeRate;
    public:
        Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
        virtual double convertToBase() {
            cout << "Converting to base..." << endl;
            return 0;
        }
        virtual double convertTo(Currency &targetCurrency) {
            return amount * exchangeRate/targetCurrency.exchangeRate;
        }
        virtual void displayDetails() {
            cout << "Displaying details for generic currency...\nEnd of details..." << endl;
        }
};

class Dollar: public Currency { //considering usd as base
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
        double convertToBase() override {
            cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }
        void displayDetails() override {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

class Euro: public Currency {
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 1.0877) {}
        double convertToBase() override {
            cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }
        void displayDetails() override {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

class Rupee: public Currency {
    public:
        Rupee(double amt) : Currency(amt, "PKR", "Rs", 0.0036) {}
        double convertToBase() override {
            cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }
        void displayDetails() override {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(100);
    
    d.displayDetails();
    e.displayDetails();
    r.displayDetails();
    
    cout << "100 USD to EUR: " << d.convertTo(e) << " EUR" << endl;
    cout << "100 EUR to PKR: " << e.convertTo(r) << " PKR" << endl;
    return 0;
}


