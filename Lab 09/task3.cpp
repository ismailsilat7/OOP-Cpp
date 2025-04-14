#include "book.h"
#include <iostream>
using namespace std;

int main() {

    Library lib;

    Book* b1 = new Book("C++ Primer", "Lippman", "123456");
    Book* b2 = new Book("Clean Code", "Robert C. Martin", "789101");
    Book* b3 = new Book("Design Patterns", "Gamma", "112233");

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    cout << "Initial Library:" << endl;
    lib.displayAllBooks();

    lib.removeBook("Clean Code");

    cout << endl << "After removing second book:" << endl;
    lib.displayAllBooks();

}