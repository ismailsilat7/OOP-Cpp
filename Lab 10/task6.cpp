#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {

    public:
        int itemId;
        char itemName[20];
        InventoryItem(int id, string name) : itemId(id) {
            strcpy(itemName, name.c_str()); 
        }

};

int main() {

    ofstream file;
    file.open("inventory.dat", ios::binary);

    InventoryItem item = {1, "IceCream"};

    file.write((char*)&item, sizeof(item));

    file.close();



    ifstream infile;
    infile.open("inventory.dat", ios::binary);

    InventoryItem readItem(0, ""); 
    
    infile.read((char*)&item, sizeof(item));

    cout << "ID: " << item.itemId << ", Name: " << item.itemName << endl;

    infile.close();

}