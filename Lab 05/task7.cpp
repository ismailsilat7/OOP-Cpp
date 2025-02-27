#include <iostream>
using namespace std;

class Product {
    private:
        static int IDCounter;
        int productID;
        string name;
        float price;
    public:
        Product(string n, float p) :name(n), price(p), productID(IDCounter++) {}
        int getID() { return productID; }
        string getName() { return name; }
        float getPrice() { return price; }
};

int Product::IDCounter = 0;

class GroceryStore {
    private:
        int numProducts;
        Product** products;
    public:
        GroceryStore() {
            numProducts = 0;
            products = nullptr;
        }
        void addProduct(Product* product) {
            cout << endl << "Adding product..." << endl;
            Product ** tempProducts = new Product* [numProducts + 1];
            for(int i = 0; i < numProducts; i++) {
                tempProducts[i] = products[i];
            }
            tempProducts[numProducts] = product;
            delete[] products;
            products = tempProducts;
            numProducts++;
            cout << "Product " << product->getName() << " added!" << endl;
        }
        void displayProducts() {
            if (numProducts == 0) {
                cout << "No products in the store." << endl;
                return;
            }
    
            cout << "\nDisplaying Products:\n";
            for (int i = 0; i < numProducts; i++) {
                cout << i + 1 << ". ID: " << products[i]->getID() << ", Name: " << products[i]->getName()  << ", Price: $" << products[i]->getPrice() << endl;
            }
            cout << endl;
        }    
        void removeProduct() {
            int ID;
            cout << "Enter ID of product to be removed: ";
            cin >> ID;
            cin.ignore();
            int index = -1;
            for (int i = 0; i < numProducts; i++) {
                if (products[i]->getID() == ID) {
                    index = i;
                    break;
                }
            }
    
            if (index == -1) {
                cout << "Product " << ID << " not found! Cannot remove." << endl;
                return;
            }
    
            cout << "Removing product " << ID << ": " << products[index]->getName() << "..." << endl;
    
            Product** tempProducts = new Product* [numProducts - 1];
            for (int i = 0; i < index; i++) {
                tempProducts[i] = products[i];
            }
            for (int i = index; i < numProducts - 1; i++) {
                tempProducts[i] = products[i + 1];
            }
            delete[] products;
            products = tempProducts;
            numProducts--;
    
            cout << "Product " << ID << " removed!" << endl << endl;
        }
        void searchProduct() {
            cout << endl << "Searching for product..." << endl;
            string name;
            cout << "Enter name of product: ";
            getline(cin, name);
            bool found = false;
            int index;
            for(int i = 0; i < numProducts; i++) {
                if(name == products[i]->getName()) {
                    found = true;
                    index = i;
                }
            }
            if(!found) {
                cout << "Product " << name << " not found!" << endl;
                return;
            }
            cout << "Product Found!" << endl;
            cout << "ID: " << products[index]->getID() << ", Name: " << products[index]->getName() << ", Price: $" << products[index]->getPrice() << endl;
        }
        void sortProducts() {
            cout << "Sorting products as per price..." << endl;
            for(int i = 0; i < numProducts - 1; i++) {
                for(int j = 0; j < numProducts - i - 1; j++) {
                    if(products[j]->getPrice() > products[j+1]->getPrice()) {
                        Product * temp = products[j];
                        products[j] = products[j+1];
                        products[j+1] = temp;
                    }
                }
            }
            cout << "Products sorted!" << endl;
            cout << "Cheapest Product; " << "ID: " << products[0]->getID() << ", Name: " << products[0]->getName() << ", Price: $" << products[0]->getPrice() << endl;
        }
        ~GroceryStore() {
            delete[] products;
        }
};

int main() {
    GroceryStore store;

    Product* AC = new Product("AC", 500.0);
    Product* sugar = new Product("Sugar", 2.0);
    Product* rice = new Product("Rice", 3.5);
    Product* milk = new Product("Milk", 1.8);
    Product* drinks = new Product("Drinks", 2.5);
    Product* chips = new Product("Chips", 1.2);

    store.addProduct(AC);
    store.addProduct(sugar);
    store.addProduct(rice);
    store.addProduct(milk);
    store.addProduct(drinks);
    store.addProduct(chips);

    store.displayProducts();

    store.removeProduct();
    store.searchProduct();
    store.sortProducts();

    store.displayProducts();

    delete AC;
    delete sugar;
    delete rice;
    delete milk;
    delete drinks;
    delete chips;
    return 0;
}