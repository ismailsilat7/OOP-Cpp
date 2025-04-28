#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    ifstream file;

    file.open("vehicles.txt");

    if(!file.is_open()) {
        cout << "Failed to open file"<< endl;
        return 1;
    }

    string line;
    while(getline(file,line)) {
        if(!line.empty() && line[0] != '/') {

            istringstream extract(line);
            string Type, ID, Name, Year, extraData, Certification;
            getline(extract, Type, ',');
            getline(extract, ID, ',');
            getline(extract, Name, ',');
            getline(extract, Year, ',');
            getline(extract, extraData, ',');
            getline(extract, Certification, ',');

            int intYear = stoi(Year);

            cout << "Type: " <<Type << ", ID: " << ID << ", Name: " << Name << ", Year: " << intYear << ", Extra Data: " << extraData << ", Certification: " << Certification << endl;

            if(Type == "AutonomousCar") {

                size_t pos = extraData.find(':');
                if (pos != string::npos) {
                    float num = stof(extraData.substr(pos + 1));
                    cout << "SW: " << num << endl;
                }

            } else if (Type == "ElectricVehicle") {

                size_t pos = extraData.find(':');
                if(pos != string::npos) {
                    int batteryCapacity = stoi(extraData.substr(pos + 1));
                    cout << "Battery Capacity : " << batteryCapacity << endl;
                }

            } else {


                size_t posCargo = extraData.find(':');
                size_t posSeparator = extraData.find('|');
                if(posCargo != string::npos && posSeparator != string::npos) {
                    string cargoStr = extraData.substr(posCargo + 1, posSeparator - posCargo - 1);
                    int cargo = stoi(cargoStr);
                    size_t posBattery = extraData.find(':', posSeparator);
                    if (posBattery != string::npos) {
                        string batteryStr = extraData.substr(posBattery + 1);
                        int battery = stoi(batteryStr);
                        cout << "Cargo Capacity: " << cargo << endl;
                        cout << "Battery Capacity: " << battery << endl;
                    }
                }

            }

        }
        
    }

    file.close();

}

