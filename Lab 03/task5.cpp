#include <iostream>
using namespace std;

class GroceryStore {

    private:
        int numItems;
        string *items;
        float *prices;
        int getItem() {
            string search;
            cout << "Enter item: ";
            getline(cin, search);
            for(int i = 0; i < numItems; i++) {
                if(search == items[i]) {
                    return i;
                }
            }
            cout << "Item not found" << endl;
            return -1;
        }
    public:
        GroceryStore(int n) {
            numItems = n;
            items = new string[numItems];
            prices = new float[numItems];
            for (int i = 0; i < numItems; i++) {
                cout << "Enter item at index " << i + 1 << ": ";
                getline(cin, items[i]);
                cout << "Enter price: $";
                cin >> prices[i];
                cin.ignore();
            }
        }
        ~GroceryStore() {
            delete[] items;
            delete[] prices;
        }
        void addItems(int n) {
            string* tempItems = new string[numItems + n];
            float* tempPrices = new float[numItems + n];
            for (int i = 0; i < numItems; i++) {
                tempItems[i] = items[i];
                tempPrices[i] = prices[i];
            }
            delete[] items;
            delete[] prices;
            items = tempItems;
            prices = tempPrices;
            for (int i = numItems; i < numItems + n; i++) {
                cout << "Enter item at index " << i + 1 << ": ";
                getline(cin, items[i]);
                cout << "Enter price: $";
                cin >> prices[i];
                cin.ignore();
            }
            numItems += n;
        }
        void updatePrice() {
            int itemIndex = getItem();
            if(itemIndex != -1) {
                cout << "Current price: " << prices[itemIndex] << endl;
                cout << "Enter updated price: $";
                cin >> prices[itemIndex];
                cin.ignore();
            }
        }
        void viewInventory() {
            float total = 0;
            cout << "Displaying Inventory..." << endl;
            for(int i = 0; i < numItems; i++) {
                cout << endl << "Item " << i + 1 << endl;
                cout << "Name: " << items[i] << endl;
                cout << "Price: $" << prices[i] << endl;
                total += prices[i];
            }
            cout << endl;
            cout << "Total Items: " << numItems << endl;
            cout << "Total Inventory cost: $" << total << endl << endl;
        }
        void generateReceipt() {
            string choice = "y";
            float total = 0;
            int ordered = 0;
            string* orderedItems = NULL;
            float* orderedPrices = NULL;
            while(choice != "n") {
                int itemIndex = getItem();
                if(itemIndex != -1) {
                    ordered += 1;
                    string* tempOrderedItems = new string[ordered];
                    float* tempOrderedPrices = new float[ordered];
                    for (int i = 0; i < ordered - 1; i++) {
                        tempOrderedItems[i] = orderedItems[i];
                        tempOrderedPrices[i] = orderedPrices[i];
                    }
                    delete[] orderedItems;
                    delete[] orderedPrices;
                    orderedItems = tempOrderedItems;
                    orderedPrices = tempOrderedPrices;
                    orderedItems[ordered - 1] = items[itemIndex];
                    orderedPrices[ordered - 1] = prices[itemIndex];
                    total += prices[itemIndex];
                    cout << orderedItems[ordered - 1] << " added to cart (+$" << orderedPrices[ordered - 1] << ")" << endl;
                }
                cout << "Do you want to add another item? (y/n): ";
                getline(cin, choice);
            }
            cout << endl << "----- Receipt -----" << endl;
            cout << endl;
            for(int i = 0; i < ordered; i++) {
                cout << orderedItems[i] << ", $" << orderedPrices[i] << endl;
            }
            cout << endl;
            cout << "Items Ordered: " << ordered << endl;
            cout << "Total: $" << total;
            cout << endl;
            cout << endl << "--End of Receipt--" << endl;
            delete[] orderedItems;
            delete[] orderedPrices;
        }
};

int main() {
    int numItems;
    cout << "Enter the number of items in the grocery store: ";
    cin >> numItems;
    cin.ignore();

    GroceryStore store(numItems);

    int choice;
    do {
        cout << "\n---- Grocery Store Menu ----" << endl;
        cout << "1. View Inventory" << endl;
        cout << "2. Add Items" << endl;
        cout << "3. Update Item Price" << endl;
        cout << "4. Generate Receipt" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                store.viewInventory();
                break;
            case 2: {
                int newItems;
                cout << "Enter the number of items to add: ";
                cin >> newItems;
                cin.ignore();
                store.addItems(newItems);
                break;
            }
            case 3:
                store.updatePrice();
                break;
            case 4:
                store.generateReceipt();
                break;
            case 5:
                cout << "Exiting program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

