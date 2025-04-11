#include <iostream>
using namespace std;

class Book {

    private:
        string title;
        float price;
    public:
        Book(string t, float p) : title(t), price(p) {}
        friend class Librarian;

};

class Librarian {
    public:
        void displayBookDetails(Book& b) {
            cout << "Displaying book details..." << endl << "Title: " << b.title << ", Price: " << b.price << endl; 
        }
        void applyBookDiscount(Book& b, float p) {
            if(p <= 100 && p > 0) {
                cout << "Applying "  << p << "% discount on Book " << b.title << "..." << endl;
                b.price = b.price * (100-p)/100;
            } else {
                cout << "Discount " << p << "% out of range!" << endl; 
            }
        }
};

int main() {
    Book b("Meowwwwwwwww", 50.8);
    Librarian ismail;
    ismail.displayBookDetails(b);
    ismail.applyBookDiscount(b, 25);
    ismail.displayBookDetails(b);
}

