#include <iostream>
using namespace std;

// Task 5: Generating report
void generateReport(int AQI[4][7], int city) {

    float weeklyAvg[4];
    cout << endl;
    cout << "Identifying Critical Pollution Days for City " << city + 1 << endl;
    bool found = false;
    int highest;
    int lowest;
    bool first = true;
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += AQI[i][j];
            if (AQI[i][j] > 150) {
                found = true;
                cout << "Week: " << i + 1 << ", Day: " << j + 1 << endl;
            }
            if(i == 0 && j == 0) {
                first = false;
                highest = AQI[i][j];
                lowest =  AQI[i][j];
            }
            if (!first) {
                if (AQI[i][j] > highest) {
                    highest = AQI[i][j];
                } if (AQI[i][j] < lowest) {
                    lowest =  AQI[i][j];
                }
            }
        }
        weeklyAvg[i] = sum/7.0;
    }
    if (!found) {
        cout << "No Critical Polution Days found" << endl;
    }
    cout << endl;

    cout << endl;
    cout << "Weekly Avg for City " << city + 1 << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Week " << i + 1 << ": " << weeklyAvg[i] << endl;
    }

    cout << endl;
    cout << "A comparison of the highest and lowest AQI values recorded during the month for City " << city + 1 << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;

}


int main() {

    // Task 4: Monthly Air Quality Index (AQI) Tracker

    int AQI[4][4][7];
    for (int i = 0; i < 4; i++) {
        cout << "Enter AQI for city " << i + 1 << endl;
        for (int j = 0; j < 4; j++) {
            cout << "week " << j + 1<< endl;
            for (int k = 0; k < 7; k++) {
                cout << "day " << k + 1 << ": ";
                cin >> AQI[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    bool first = true;
    float highest;
    int city = 0;
    cout << "Monthly Average AQI for each city" << endl;
    for (int i = 0; i < 4; i++) {
        float firstWeekAvg;
        float drop;
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int weekSum = 0;
            for (int k = 0; k < 7; k++) {
                weekSum += AQI[i][j][k];
            }
            sum += weekSum;
            if (j==0) {
                firstWeekAvg = weekSum/7.0;
            } 
            if (j==3) {
                drop = (weekSum / 7.0) - firstWeekAvg;
            }
        }
        cout << i + 1 << ". " << sum/28.0 << endl;
        if (first) {
            highest = drop;
            first =  false;
        } else if (highest < drop) {
            highest = drop;
            city = i;
        }
    }
    cout << endl;
    cout << "City with the most improved air quality: " << city + 1 << endl;

    // Task 5: Generate a Report
    
    for (int i = 0; i < 4; i++) {
        cout << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Generating Report for city " << i + 1 << endl;
        generateReport(AQI[i], i);
        cout << endl;
    }

}



