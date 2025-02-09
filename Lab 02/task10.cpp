#include <iostream>
using namespace std;

int main() {
    int row, col;

    cout << "Enter row size for matrix : ";
    cin >> row;

    cout << "Enter col size for matrix : ";
    cin >> col;

    int **arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    cout << endl;
    cout << "Input values for matrix " << endl;
    for (int i = 0; i < row; i++) {
        cout << "\t Row " << i + 1 << endl;
        for (int j = 0; j < col; j++) {
            cout << "\t \t" << j + 1 << ": ";
            cin >> *(*(arr + i) + j);
        }
    }

    int transposeRow = col, transposeCol = row;
    int **transpose = new int*[transposeRow];
    for (int i = 0; i < transposeRow; i++) {
        transpose[i] = new int[transposeCol];
    }

    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(*(transpose + j) + i) = *(*(arr + i) + j);
        }
    }

    cout << endl;
    cout << "Displaying Original Matrix..." << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << endl;
    cout << "Displaying Transpose of the Matrix..." << endl;
    for (int i = 0; i < transposeRow; i++) {
        for (int j = 0; j < transposeCol; j++) {
            cout << *(*(transpose + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    delete[] arr;
    delete[] transpose;

}

