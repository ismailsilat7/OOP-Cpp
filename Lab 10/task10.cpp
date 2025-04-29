#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file;

    file.open("data_records.txt", ios::binary);
    char chars[10];

    file.seekg(10*2, ios::beg);
    
    file.read(chars, 10);
    chars[9] = '\0';
    
    cout << "Extracted line: " << chars << endl;

    file.close();

}
