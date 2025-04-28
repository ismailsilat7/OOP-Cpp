#include <iostream>
#include <fstream>
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
            cout << line << endl;
        }
        
    }

    file.close();

}

