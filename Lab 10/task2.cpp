#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {


    ifstream file;

    file.open("vehicles.txt");

    if(!file.is_open()) {
        cout << "Failed to open file"<< endl;
        return 1;
    }

    string line;
    while(getline(file,line)) {
        if(!line.empty() && line[0] != '/') {

            istringstream extract(line);
            string Type, ID, Name, Year, extraData, Certification;
            getline(extract, Type, ',');
            getline(extract, ID, ',');
            getline(extract, Name, ',');
            getline(extract, Year, ',');
            getline(extract, extraData, ',');
            getline(extract, Certification, ',');

            cout << "Type: " <<Type << ", ID: " << ID << ", Name: " << Name << ", Year: " << Year << ", Extra Data: " << extraData << ", Certification: " << Certification << endl;

        }
        
    }

    file.close();

}

