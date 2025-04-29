#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
using namespace std;

class FileException : public exception {

    public:
        virtual const char* what() const noexcept override {
            return "FileException - File not found or permission denied!";
        }

};

class FileNotFoundException : public FileException {

    public:
        const char* what() const noexcept override {
            return "FileNotFoundException - File not found!";
        }

};

class PermissionDeniedException : public FileException {

    public:
        const char* what() const noexcept override {
            return "PermissionDeniedException - Access denied!";
        }

};

int main() {

    ifstream file;

    try {
        file.open("secret.txt");
        if(!file.is_open()) {
            if (errno == ENOENT) {
                throw FileNotFoundException();
            } else if (errno == EACCES) {
                throw PermissionDeniedException();
            } else {
                throw FileException();
            }
        }
        cout << "File opened!" << endl;
    } catch(FileException& e) {
        cout << e.what() << endl;
        return 0;
    }

    file.close();

}
