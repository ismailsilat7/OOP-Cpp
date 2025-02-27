#include <iostream>
using namespace std;

class TourGuide {
    private:
        string name;
        int yearsOfExperience;
        string specialization;
    public:
        TourGuide(string n, int y, string s) : name(n), yearsOfExperience(y), specialization(s) {}
        string getName() { return name; }
        int getExperience() { return yearsOfExperience; }
        string getSpecialization() { return specialization; }

};

class TravelAgency {
    private:
        int numTourGuides;
        TourGuide ** tourGuides;
    public:
        TravelAgency() {
            numTourGuides = 0;
            tourGuides = nullptr;
        }

        void addTourGuide(TourGuide* tourGuide) {
            cout << endl << "Adding tour guide..." << endl;
            TourGuide ** tempGuides = new TourGuide* [numTourGuides + 1];
            for(int i = 0; i < numTourGuides; i++) {
                tempGuides[i] = tourGuides[i];
            }
            tempGuides[numTourGuides] = tourGuide;
            delete[] tourGuides;
            tourGuides = tempGuides;
            numTourGuides++;
            cout << "Tour Guide " << tourGuide->getName() << " added!" << endl << endl;
        }

        void removeTourGuide() {
            cout << endl << "Removing tour guide..." << endl;
            string name;
            cout << "Enter name of tour guide to be removed: ";
            getline(cin, name);
            bool found = false;
            int index;
            for(int i = 0; i < numTourGuides; i++) {
                if(name == tourGuides[i]->getName()) {
                    found = true;
                    index = i;
                }
            }
            if(!found) {
                cout << "Tour Guide " << name << " not found! Cannot remove." << endl;
                return;
            }
            if(numTourGuides == 1) {
                delete[] tourGuides;
                tourGuides = nullptr;
            } else{
                TourGuide** tempGuides = new TourGuide*[numTourGuides - 1];
                for(int i = 0; i < index; i++) {
                    tempGuides[i] = tourGuides[i];
                }
                for(int i = index; i < numTourGuides; i++) {
                    tempGuides[i - 1] = tourGuides[i];
                }
                delete[] tourGuides;
                tourGuides = tempGuides;
            }
            numTourGuides--;
            cout << "Tour Guide " << name << " removed!" << endl << endl;

        }

        void displayTourGuides() {
            cout << endl << "Displaying TourGuides..." << endl;
            for(int i = 0; i < numTourGuides; i++) {
                cout << i + 1 << ". Name: " << tourGuides[i]->getName() << ", YearsOfExperience: " << tourGuides[i]->getExperience() << ", Specialization: " << tourGuides[i]->getSpecialization() << endl;
            }
            cout << endl;
        }

};

int main() {

    TravelAgency FASTAgency;

    TourGuide* ismail = new TourGuide("Ismail", 4, "Food Exploration");
    TourGuide* khan = new TourGuide("Khan", 2, "Sea side Exploration");
    TourGuide* ali = new TourGuide("Ali", 8, "Hill sites Exploration");

    FASTAgency.addTourGuide(ismail);
    FASTAgency.addTourGuide(khan);
    FASTAgency.addTourGuide(ali);

    FASTAgency.displayTourGuides();

    FASTAgency.removeTourGuide();

    FASTAgency.displayTourGuides();

    delete ismail, ali, khan;

}



