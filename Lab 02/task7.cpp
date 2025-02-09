#include <iostream>
using namespace std;

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void reverse(int* arr, int numItems) {
    
    for (int i = 0; i < numItems/2; i++) {
        swap(&arr[numItems-i-1], &arr[i]);
    }

}

void displayArray(int* arr, int numItems) {
    cout << "Displaying Array..." << endl;
    for (int i = 0; i < numItems; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

int main() {

    int num1 = 5;
    int num2 = 9;
    cout << "num1 is " << num1 << " and num2 is " << num2 << endl;
    swap(&num1, &num2);
    cout << "num1 is " << num1 << " and num2 is " << num2 << endl;

    int numItems;
    cout << "Enter number of values to enter in the array: ";
    cin >> numItems;
    int* arr = new int[numItems];
    for (int i  = 0; i < numItems; i++) {
        cout << "Enter value for index " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Calling displayArray Before Reversing" << endl;
    displayArray(arr, numItems);
    cout << "Calling displayArray After Reversing" << endl;
    reverse(arr, numItems);
    displayArray(arr, numItems);

    delete[] arr;
}



