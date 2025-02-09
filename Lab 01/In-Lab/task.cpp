#include <iostream>
using namespace std;

#define MAX 5

int main() {

    // Task 1: Register Event Participants
    

    // For event 1
    int numPart1 = 6;
    while(numPart1 > MAX || numPart1 < 1) {
        cout << "Enter number of particpants (1-5) in event 1: ";
        cin >> numPart1;
    } 
    string participants1[numPart1];
    for (int i = 0; i < numPart1; i++) {
        cout << "Enter name for particpant " << i + 1 << " in event 1: ";
        cin >> participants1[i];
    }

    // For event 2
    int numPart2 = 6;
    while(numPart2 > MAX || numPart2 < 1) {
        cout << "Enter number of particpants (1-5) in event 2: ";
        cin >> numPart2;
    } 
    string participants2[numPart2];
    for (int i = 0; i < numPart2; i++) {
        cout << "Enter name for particpant " << i + 1 << " in event 2: ";
        cin >> participants2[i];
    }

    
    // Task 2: Attendance Checker
    string check;   
    cout << "Enter name to search for attendance: ";
    cin >> check;
    bool found = false;
    for (int i = 0; i < numPart1; i++) {
        if (check == participants1[i])
        {
            cout << "Participant found in event 1 at index: " << i+1;
            found = true;
            break;
        }
    }
    if (!found) {
        for (int i = 0; i < numPart2; i++) {
            if (check == participants2[i])
            {
                cout << "Participant found in event 2 at index: " << i+1;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Participant not found in either events";
        }
    }
    cout << endl;
    
    // Task 3: Calculate Total Donations
    int total = (numPart1 + numPart2)*10;
    cout << "Total donations: " << total << endl;

    // Task 4: Display Particpant names in Reverse
    cout << "Displaying names in reverse order" << endl;
    cout << "Event 1" << endl;
    for (int i = numPart1 - 1; i >= 0; i--) {
        cout << i + 1 << ". " <<  participants1[i] << endl;
    }
    cout << "Event 2" << endl;
    for (int i = numPart2 - 1; i >= 0; i--) {
        cout << i + 1 << ". " << participants2[i] << endl;
    }

    // Task 5: Event Popularity Bar Chart
    cout << "Bar Chart for Event Popularity" << endl;
    int maxNumPart = (numPart1 > numPart2) ? numPart1 : numPart2;
    for (int i = maxNumPart - 1; i >= 0; i--) {
        cout << "      ";
        if (i >= numPart1) {
            cout << " ";
        } else {
            cout << "*";
        }
        cout << " ";
        if (i >= numPart2) {
            cout << " ";
        } else {
            cout << "*";
        }
        cout << endl;
    }
    cout << "Event 1 2";

}




