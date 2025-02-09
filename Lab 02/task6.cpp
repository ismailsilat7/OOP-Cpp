#include <iostream>
using namespace std;

struct Book {
    int bookId;
    string title;
    string author;
    bool isAvailable = false;
};

int addBook(Book*& Books, int numBooks) {

    cout << "Allocating memory to add new Book..." << endl;
    
    Book* temp = new Book[numBooks + 1];
    for (int i = 0; i < numBooks; i++) {
        temp[i] = Books[i];
    }

    delete[] Books;
    Books = temp;

    cout << "Enter Book Details" << endl;
    cout << "Enter Book ID: ";
    cin >> Books[numBooks].bookId;
    cin.ignore();
    cout << "Enter Book title: ";
    getline(cin, Books[numBooks].title);
    cout << "Enter Book author: ";
    getline(cin, Books[numBooks].author);
    cout << "Is Book Avaialble? (y/n): ";
    char response;
    cin >> response;
    Books[numBooks].isAvailable = (response == 'y' || response == 'Y');
    cout << "Book added successfully" << endl;
    return numBooks + 1;

}

int removeBook(Book*& Books, int numBooks, int index) {

    if (index == -1) {
        return numBooks;
    }

    if (numBooks == 0) {
        cout << "The Book array is already empty, nothing to remove" << endl;
        return numBooks;
    }

    if (!(index >= 0 && index < numBooks)) {
        cout << "Invalid index, must be between 0 & " << numBooks - 1 << " inclusive" << endl;
        return numBooks;
    }

    cout << "Resizing Array to remove Book..." << endl;
    Book* temp = new Book[numBooks - 1];
    for (int i = 0, j = 0; i < numBooks; i++) {
        if (i != index) {
            temp[j] = Books[i];
            j++;
        }
    }
    delete[] Books;
    Books = temp;
    cout << "Book removed successfully" << endl;

    return numBooks - 1;

}

int searchBook(Book* Books, int numBooks, int ID) {
    cout << "Searching for Book with id " << ID << "..." << endl;
    for (int i = 0; i < numBooks; i++) {
        if (Books[i].bookId == ID) {
            cout << "Book found at index: " << i << endl;
            return i;
        }
    }
    cout << "Book not found" << endl;
    return -1;
}

void displayBooks(Book* Books, int numBooks) {

    cout << "Displaying Books..." << endl;

    if (numBooks == 0) {
        cout << "No books available." << endl;
        return;
    }

    for (int i = 0; i < numBooks; i++) {
        cout << "Book index: " << i << endl << endl;
        cout << "\tID: " << Books[i].bookId << endl;
        cout << "\tTitle: " << Books[i].title << endl;
        cout << "\tAuthor: " << Books[i].author << endl;
        cout << "\tIs Available: " << (Books[i].isAvailable ? "Yes" : "No") << endl; 
        cout << endl; 
    }   
}




int main() {

    Book* Books = nullptr;
    int numBooks = 0;

    int choice = 0;
    cout << "Library Management System\n1. Add Book\n2. Remove Book by index\n3. Remove Book by BookID\n4. Search Book by BookID\n5. Display Books\n6. Exit\n" << endl;
    while (choice != 6) {
        int id;
        int index;
        cout << "Enter your choice: ";
        cin >> choice; 
        switch (choice)
        {
            case 1:
                numBooks = addBook(Books, numBooks);
                break;
            case 2:
                cout << "Enter index: ";
                cin >> index;
                numBooks = removeBook(Books, numBooks, index);
                break;
            case 3:
                cout << "Enter id: ";
                cin >> id;
                numBooks = removeBook(Books,numBooks, searchBook(Books, numBooks, id));
                break;
            case 4:
                cout << "Enter id: ";
                cin >> id;
                searchBook(Books, numBooks, id);
                break;
            case 5:
                displayBooks(Books, numBooks);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please choose a number between 1 & 5 (inclusive)" << endl;
                break;
        }
    }
    delete[] Books;
}


