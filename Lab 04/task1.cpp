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
            if(*stock <= 0) {
                cout << "No stock left... Cannot make a purchase" << endl;
            }
            else {
                *stock--;
                cout << "Book " << title << " purchased!" << endl;
                if(*stock < 5) {
                    cout << "WARNING: LOW STOCK!" << endl; 
                }
            }
        }
};

int main() {
    Book thisBook;
    thisBook.updateBookDetails();
    thisBook.purchaseBook();
}
