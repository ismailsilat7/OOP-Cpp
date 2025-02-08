#include <iostream>
using namespace std;

int getMonth() {
    int choice = -1;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        cout << i + 1 << ". " << months[i] << endl;
    }
    while (choice <= 0 || choice > 12) {
        cout << "Enter month: ";
        cin >> choice;
        if (choice <= 0 || choice > 12) {
            cout << "Out of range... Please enter between 1 & 12 (inclusive)" << endl;
        }
    }
    return choice - 1;
}

int getDay(int month) {
    int choice = -1;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (choice <= 0 || choice >= days[month]) {
        cout << "Enter day: ";
        cin >> choice;
        if (choice <= 0 || choice > days[month]) {
            cout << "Out of range... Please enter between 1 & " << days[month] << " (inclusive)" << endl;
        }
    }
    return choice - 1;
}

class Planner {
    private: 
        string schedule[12][31];
    public: 
        Planner() {
            for(int i = 0; i < 12; i++) {
                for(int j = 0; j < 31; j++) {
                    schedule[i][j] = "";
                }
            }
        }
        void addTask() {
            cout << "Adding task..." << endl;
            int month = getMonth();
            int day = getDay(month);
            cin.ignore();
            string task;
            if(schedule[month][day] != "") {
                cout << "Enter task to replace " << schedule[month][day] << ": ";
            } else {
                cout << "Enter task: ";
            }
            getline(cin, task);
            schedule[month][day] = task;
        }
        void removeTask() {
            cout << "Removing Task..." << endl;
            int month = getMonth();
            int day = getDay(month);
            cin.ignore();
            if(schedule[month][day] == "") {
                cout << "Nothing to remove..." << endl;
            } else {
                schedule[month][day] = "";
                cout << "Task removed" << endl;
            }
        }
        void displayTasks() {
            cout << "Displaying Tasks..." << endl;
            int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
            for (int i = 0; i < 12; i++)
            {
                cout << "Month: " << months[i] << endl;
                bool hasTasks = false;
                for (int j = 0; j < days[i]; j++)
                {
                    if (schedule[i][j] != "") {
                        cout <<"\tDay " << j + 1 << ": " << schedule[i][j] << endl;
                        hasTasks = true;
                    }
                }
                if(!hasTasks) {
                    cout << "No tasks for the month" << endl;
                }
            }
            
        }
};

int main() {
    Planner planner;
    int choice = -1;

    while (choice != 0) {
        cout << "\n--- Planner Menu ---" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                planner.addTask();
                break;
            case 2:
                planner.removeTask();
                break;
            case 3:
                planner.displayTasks();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 3." << endl;
        }
    }

    return 0;
}

