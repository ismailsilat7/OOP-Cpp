#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream outfile;
    outfile.open("sensor_log.txt", ios::app);

    string data[5] = {
        "Sensor 3: 85 kWH",
        "Sensor 4: 20 V",
        "Sensor 5: 75 C",
        "Sensor 6: 80 %RH",
        "Sensor 7: 45 W"
    };

    for(int i = 0;i < 5; i++) {
        //outfile.write(data[i].c_str(), data[i].length());
        outfile << data[i] << endl;
        cout << "Position: " << outfile.tellp() << endl;
    }

    outfile.close();

}