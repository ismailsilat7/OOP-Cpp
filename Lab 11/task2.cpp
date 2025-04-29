#include <iostream>
using namespace std;

#define NUM_ELEMENTS 4

class StackOverflowException : public exception {
  
    public:
        const char* what() const noexcept override {
            return "StackOverflowException - Stack is full!";
        }

};

class StackUnderflowException : public exception {
  
    public:
        const char* what() const noexcept override {
            return "StackUnderflowException - Stack is empty!";
        }

};

template <typename T>
class Stack {
    private:
        T elements[NUM_ELEMENTS];
        int currentIndex;
    public:
        Stack() : currentIndex(-1) {}
        void push( T element) {
            if(currentIndex < NUM_ELEMENTS - 1) {
                currentIndex ++;
                elements[currentIndex] = element;
                cout << "Element: " << elements[currentIndex] << " pushed to stack at index " << currentIndex << endl;
            } else {
                throw StackOverflowException();
            }
        }

        void pop() {
            if(currentIndex > -1) {
                cout << "Element: " << elements[currentIndex] << " popped from stack at index " << currentIndex << endl;
                currentIndex--;
            } else {
                throw StackUnderflowException();
            } 
        }
};

int main() {

    Stack <double>stack;

    try {
        for(int i = 0; i < NUM_ELEMENTS + 2; i++) {
            stack.push(i * 0.1);
        }       
    } catch(const StackOverflowException& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        for(int i = 0; i < NUM_ELEMENTS + 2; i++) {
            stack.pop();
        }
    } catch(const StackUnderflowException& e) {
        cout << "Error: " << e.what() << endl;
    }
    
}




