#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file;

    file.open("large_log.txt", ios::binary);
    char chars[11];

    while(file.read(chars, 10)) {
        cout << "Position: " << file.tellg() << endl;
    }
    
    file.close();


}
