#include <iostream>
using namespace std;

class Activity {

    public:
        virtual double calculateCalories() = 0;

};

class Running : public Activity {
    private:
        double distance;
        double time;
    public:
        Running(double d, double t) : distance(d), time(t) {}
        double calculateCalories() {
            return distance * 60;
        }
};

class Cycling : public Activity {
    private:
        double speed;
        double time;
    public:
        Cycling(double s, double t) : speed(s), time(t) {}
        double calculateCalories() {
            return speed * time * 40;
        }
};

int main() {

    Running r(50, 5);
    Cycling c(30,15);

    cout << "Calories burnt via running: " << r.calculateCalories() << endl;
    cout << "Calories burnt via cycling: " << c.calculateCalories() << endl;
    
}

