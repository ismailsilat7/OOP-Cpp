#include <iostream>
using namespace std;

// Task 2: Identify Critical Pollution Days - Functionality implemented in main function
void findCriticalDays(int AQI[4][7], int city) {
    cout << endl;
    cout << "Identifying Critical Pollution Days for City " << city + 1 << endl;
    bool found = false;
    for (int j = 0; j < 7; j++) {
        if (AQI[city][j] > 150) {
            found = true;
            cout << "Day: " << j + 1 << endl;
        }
    }
    if (!found) {
        cout << "No Critical Polution Days found" << endl;
    }
    cout << endl;
}

// Task 3: Data Visualization - Functionality implemented in main function
void dataVisualization(int AQI[4][7], int city) {
    cout << endl;
    cout << "Visual Representation of AQI Level for city " << city + 1 << endl;

    int maxAQI = AQI[city][0];
    for (int i = 1; i < 7; i++) {
        if (maxAQI < AQI[city][i]) {
            maxAQI = AQI[city][i];
        }
    }

    
    for (int currMaxAQI = maxAQI - (maxAQI % 50); currMaxAQI > 0; currMaxAQI -= 50) {
        cout << "     ";
        for (int i = 0; i < 7; i++) {
            if (currMaxAQI > AQI[city][i]) {
                cout << " ";
            } else {
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "Week ";
    for (int i = 0; i < 7; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;

}

int main() {

    // Task 1: Weekly Air Quality Index (AQI) Tracker

    int AQI[4][7];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "Enter AQI for city " << i + 1 << " and day " << j + 1<< ": ";
            cin >> AQI[i][j];
        }
    }
    cout << endl;
    bool first = true;
    int highest;
    int city = 0;
    cout << "Average AQI for each city" << endl;
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += AQI[i][j];
        }
        cout << i + 1 << ". " << sum/7.0 << endl;
        if (first) {
            highest = sum/7;
            first =  false;
        } else if (highest < sum/7.0) {
            highest = sum/7.0;
            city = i;
        }
    }
    cout << "City with worst air quality: " << city + 1 << endl;

    // Task 2: Identify Critical Pollution Days - Function made outside main
    for (int i = 0; i < 4; i++) {
        findCriticalDays(AQI, i);
    }

    // Task 3: Data Visualization
    for (int i = 0; i < 4; i++) {
        dataVisualization(AQI, i);
    }


}



