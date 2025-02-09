#include <iostream>
using namespace std;

string concat(string str1, string str2) {
    return str1.append(str2);
}

int compare(string str1, string str2) {
    str1.compare(str2);
}

int findLength(string str) {
    return str.length();
}

int main() {

    string* strings = new string[2];

    for (int i = 0; i < 2; i++) {
        cout << "Enter string #" << i + 1 << ": ";
        getline(cin, strings[i]);
    }

    cout << "Concatenating string1 & string 2..." << endl;
    cout << concat(strings[0], strings[1]) << endl;;

    cout << "Comparing string1 & string 2..." << endl;
    int result = compare(strings[0], strings[1]);
    if (result < 0) {
        cout << strings[0] << " is less than " << strings[1] << endl;
    } else if (result > 0) {
        cout << strings[0] << " is greater " << strings[1] << endl;
    } else {
        cout << "Both strings are equivalent" << endl;
    }

    cout << "Finding length for string1..." << endl;
    cout << findLength(strings[0]) << endl;

    cout << "Finding length for string2..." << endl;
    cout << findLength(strings[1]) << endl;

    delete[] strings;
}



