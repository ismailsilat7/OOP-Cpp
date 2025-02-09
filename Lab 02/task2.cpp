#include <iostream>
using namespace std;

int main() {

    int row1, col1;

    cout << "Enter row size for matrix 1: ";
    cin >> row1;

    cout << "Enter col size for matrix 1: ";
    cin >> col1;

    int **arr1 = new int*[row1];
    for (int i = 0; i < row1; i++) {
        arr1[i] = new int[col1];
    }

    cout << "Input values for matrix 1" << endl;
    for (int i = 0; i < row1; i++) {
        cout << "\t Row " << i + 1 << endl;
        for (int j = 0; j < col1; j++) {
            cout << "\t \t" << j + 1 << ": ";
            cin >> *(*(arr1 + i) + j);
        }
    }

    int row2, col2;

    cout << "Enter row size for matrix 2: ";
    cin >> row2;

    cout << "Enter col size for matrix 2: ";
    cin >> col2;

    int **arr2 = new int*[row2];
    for (int i = 0; i < row2; i++) {
        arr2[i] = new int[col2];
    }

    cout << "Input values for matrix 2" << endl;
    for (int i = 0; i < row2; i++) {
        cout << "\t Row " << i + 1 << endl;
        for (int j = 0; j < col2; j++) {
            cout << "\t \t" << j + 1 << ": ";
            cin >> *(*(arr2 + i) + j);
        }
    }


    int **addMatrix;
    int **subMatrix;
    bool addsub = true;
    if (row1 == row2 && col1 == col2) {

        addMatrix = new int*[row1];
        subMatrix = new int*[row1];
        for (int i = 0; i < row1; i++) {
            addMatrix[i] = new int[col1];
            subMatrix[i] = new int[col1];
        }

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++) {
                *(*(addMatrix + i) + j) = *(*(arr1 + i) + j) + *(*(arr2 + i) + j);
                *(*(subMatrix + i) + j) = *(*(arr1 + i) + j) - *(*(arr2 + i) + j);
            }
        }

    } else {
        addsub = false;
        cout << "Matrix Addition & Subtraction is not possible" << endl;
    }

    int **mulMatrix;
    int mulRow, mulCol;
    bool multiplication = true;
    if (col1 == row2) {
        mulRow = row1;
        mulCol = col2;

        mulMatrix = new int*[mulRow];
        for (int i = 0; i < mulRow; i++) {
            mulMatrix[i] = new int[mulCol];
        }

        for (int i = 0; i < mulRow; i++) {
            for (int j = 0; j < mulCol; j++) {
                *(*(mulMatrix + i) + j) = 0;
                for (int k = 0; k < col1; k++) {  // col1 == row2
                    *(*(mulMatrix + i) + j) += *(*(arr1 + i) + k) * *(*(arr2 + k) + j);
                }
            }
        }



    } else {
        cout << "Matrix Multiplication is not possible" << endl;
        multiplication = false;
    }

    if(addsub) {
        cout << "Displaying results for Addition between matrix 1 & 2" << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                cout << *(*(addMatrix + i) + j) << " ";
            }
            cout << endl;
        }

        cout << "Displaying results for Subtraction between matrix 1 & 2" << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                cout << *(*(subMatrix + i) + j) << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < row1; i++) {
            delete[] addMatrix[i];
            delete[] subMatrix[i];
        }
        delete[] addMatrix;
        delete[] subMatrix;
    }

    if(multiplication == true) {
        cout << "Displaying results for Multiplication between matrix 1 & 2" << endl;
        for (int i = 0; i < mulRow; i++) {
            for (int j = 0; j < mulCol; j++) {
                cout << *(*(mulMatrix + i) + j) << " ";
            }
            cout << endl;
        }
        
        for (int i = 0; i < mulRow; i++) {
            delete[] mulMatrix[i];
        }
        delete[] mulMatrix;
    }

    for (int i = 0; i < row1; i++) {
        delete[] arr1[i];
    }
    for (int i = 0; i < row2; i++) {
        delete[] arr2[i];
    }
    delete[] arr1;
    delete[] arr2;

}

