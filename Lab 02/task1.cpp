#include <iostream>
using namespace std;

int main() {

    cout << "Enter size of array: ";
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for index " << i << ": ";
        cin >> arr[i];
    }

    int sum = 0;
    int highest = INT16_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > highest) {
            highest = arr[i];
        }
        sum += arr[i];
    }

    cout << "Sum: " << sum << ", Average: " << sum/size << ", Maximum Value: " << highest << endl;
    
}




