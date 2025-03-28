#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string title;
        float price;
        int* stock;
    
    public:
        Book() {
            title = "Unknown";
            price = 0.0;
            stock = new int(30);
        }
        Book(string title, float price, int stock) {
            this->title = title;
            this->price = price;
            this->stock = new int(stock);
        }
        Book(const Book& other) {
            title = other.title;
            price = other.price;
            stock = new int(*other.stock);
        }
        void updateBookDetails() {
            cout << "Enter updated title for Book " << title << ": ";
            getline(cin, title);
            cout << "Enter updated price: $";
            cin >> price;
            cin.ignore();
            cout << "Enter updated stock: ";
            cin >> *stock;
            cin.ignore();
        }
        void purchaseBook() {
            if (*stock == 0) {
                cout << "No stock left... Cannot make a purchase." << endl;
                return;
            }
            int quantity;
            cout << "Enter quantity to purchase: ";
            cin >> quantity;
            if (*stock < quantity) {
                cout << "Quantity exceeds available stock (" << *stock << "), cannot purchase Book " << title << endl;
                return;
            }
            int discount = applyDiscount(quantity);
            float totalPrice = price * quantity * (100 - discount) / 100.0;
            cout << "Purchasing Book " << title << "..." << endl;
            cout << "Total: $" << totalPrice << endl;
            cout << "Discount applied: " << discount << "%" << endl;
            cout << "Book " << title << " purchased." << endl;
            *stock -= quantity;
            if (*stock < 5) {
                cout << "WARNING: LOW STOCK!" << endl;
            }
        }
        int applyDiscount(int quantity) {
            if(quantity > 10) {
                return 10;
            } else if (quantity > 5) {
                return 5;
            }
            return 0;
        }
        ~Book() {
            delete stock;
        }
};

int main() {
    
    Book book1;
    Book book2("C++ Programming", 39.99, 20);
    Book book3 = book2;
    cout << "Updating details for book1 (default constructor):" << endl;
    book1.updateBookDetails();

    cout << "\nPurchasing book2 (parameterized constructor):" << endl;
    book2.purchaseBook();

    cout << "\nPurchasing book3 (copy constructor):" << endl;
    book3.purchaseBook();

    return 0;
}

