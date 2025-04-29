#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream file;

    file.open("config.txt", ios::in | ios::out);

    file.seekp(5, ios::beg);

    file.write("XXXXX", 5);

    file.close();

}
