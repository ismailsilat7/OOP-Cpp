#include <iostream>
using namespace std;

struct Product {
    int productId;
    string name;
    int quantity;
    float price;
};

int addProduct(Product *& Products, int numProducts) {

    cout << "Allocating memory to add new Product..." << endl;
    
    Product* temp = new Product[numProducts + 1];
    for (int i = 0; i < numProducts; i++) {
        temp[i] = Products[i];
    }

    delete[] Products;
    Products = temp;

    cout << "Enter Product Details" << endl;
    cout << "Enter Product ID: ";
    cin >> Products[numProducts].productId;
    cin.ignore();
    cout << "Enter Product name: ";
    getline(cin, Products[numProducts].name);
    cout << "Enter Quantity: ";
    cin >> Products[numProducts].quantity;
    cout << "Enter price: $";
    cin >> Products[numProducts].price;
    cin.ignore();

    cout << "Product Added Successfully" << endl;
    return numProducts + 1;

}

int removeProduct(Product *& Products, int numProducts, int index) {

    if (index == -1) {
        return numProducts;
    }

    if (numProducts == 0) {
        cout << "The Product array is already empty, nothing to remove" << endl;
        return numProducts;
    }

    if (!(index >= 0 && index < numProducts)) {
        cout << "Invalid index, must be between 0 & " << numProducts - 1 << " inclusive" << endl;
        return numProducts;
    }

    cout << "Resizing Array to remove Product..." << endl;
    Product* temp = new Product[numProducts - 1];
    for (int i = 0, j = 0; i < numProducts; i++) {
        if (i != index) {
            temp[j] = Products[i];
            j++;
        }
    }
    delete[] Products;
    Products = temp;
    cout << "Product removed successfully" << endl;

    return numProducts - 1;

}

int searchProduct(Product* Products, int numProducts, int ID) {
    cout << "Searching for Product with id " << ID << "..." << endl;
    for (int i = 0; i < numProducts; i++) {
        if (Products[i].productId == ID) {
            cout << "Product found at index: " << i << endl;
            return i;
        }
    }
    cout << "Product not found" << endl;
    return -1;
}

void displayProducts(Product* Products, int numProducts) {

    cout << "Displaying Products..." << endl;

    if (numProducts == 0) {
        cout << "No products available." << endl;
        return;
    }

    float sum = 0;
    for (int i = 0; i < numProducts; i++) {
        sum += Products[i].quantity * Products[i].price;
        cout << "Product index: " << i << endl << endl;
        cout << "\tProduct ID: " << Products[i].productId << endl;
        cout << "\tName: " << Products[i].name << endl;
        cout << "\tTotal value of product in inventory: $" << Products[i].quantity * Products[i].price << endl;
        cout << endl; 
    }

    cout << "Total inventory value: $" << sum << endl << endl;

}

void updateProduct(Product* Products, int numProducts, int index) {

    if (index == -1) {
        return;
    }

    if (numProducts == 0) {
        cout << "The Product array is already empty, nothing to update" << endl;
        return;
    }

    if (!(index >= 0 && index < numProducts)) {
        cout << "Invalid index, must be between 0 & " << numProducts - 1 << " inclusive" << endl;
        return;
    }

    cout << "Enter Updated Product Details for ProductID " << Products[index].productId << endl;
    cin.ignore();
    cout << "Enter Product name: ";
    getline(cin, Products[index].name);
    cout << "Enter Quantity: ";
    cin >> Products[index].quantity;
    cout << "Enter price: $";
    cin >> Products[index].price;
    cin.ignore();

    cout << "Product Updated Successfully" << endl;  

}

int main() {

    Product* Products = nullptr;
    int numProducts = 0;

    int choice = 0;
    cout << "Inventory Management\n1. Add Product\n2. Remove Product by ProductID\n3. Update Product by ProductID\n4. Display Products value\n5. Exit\n" << endl;

    while(choice != 5) {

        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        int ID;
        switch (choice)
        {
            case 1:
                numProducts = addProduct(Products, numProducts);
                break;
            case 2: 
                cout << "Enter Product ID: ";
                cin >> ID;
                numProducts = removeProduct(Products, numProducts, searchProduct(Products, numProducts, ID));
                break;
            case 3:
                cout << "Enter Product ID: ";
                cin >> ID;
                updateProduct(Products, numProducts, searchProduct(Products, numProducts, ID));
                break;
            case 4:
                displayProducts(Products, numProducts);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice... Choose between 1 & 5" << endl;
                break;
        }

    }
    delete[] Products;
}





