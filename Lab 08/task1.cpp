#include <iostream>
using namespace std;

class Humidity;

class Temperature {

    private:
        float temperature;
    public:
        Temperature(float temp) : temperature(temp) {}
        friend float calculateHeatIndex(Temperature temp, Humidity hum);
};

class Humidity {

    private:
        float humidity;
    public:
        Humidity(float h) : humidity(h) {}
        friend float calculateHeatIndex(Temperature temp, Humidity hum);
};

float calculateHeatIndex(Temperature temp, Humidity hum) {
    return temp.temperature + 0.33 * hum.humidity - 4;
}

int main() {
    Temperature t(32);
    Humidity h(85);
    cout << "Heat Index: " << calculateHeatIndex(t,h);
}

