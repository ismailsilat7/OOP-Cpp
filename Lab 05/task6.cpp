#include <iostream>
using namespace std;

class Movie {
    private:
        string title, director;
        float duration;
    public:
        Movie(string t, string d, float du) : title(t), director(d), duration(du) {}
        string getTitle() { return title; }
        string getDirector() { return director; }
        float getDuration() { return duration; }
};

class CinemaHall {
    private:
        int numMovies;
        Movie** movies;
        bool* isScreening;
    public:
        CinemaHall() {
            cout << "Enter number of movies: ";
            cin >> numMovies;
            cin.ignore();
            movies = new Movie*[numMovies];
            isScreening = new bool[numMovies];
            for(int i = 0; i < numMovies; i++) {
                string t, d;
                float du;
                cout << "Enter title: ";
                getline(cin, t);
                cout << "Enter director: ";
                getline(cin, d);
                cout << "Enter duration (in hours): ";
                cin >> du;
                cin.ignore();
                movies[i] = new Movie(t,d,du);
                string screening;
                cout << "Is Screening? (yes/no): ";
                getline(cin, screening);
                isScreening[i] = ("yes" == screening) ? true : false;
            }
        }
        ~CinemaHall() {
            for(int i = 0; i < numMovies; i++) {
                delete movies[i];
            }
            delete[] movies;
            delete[] isScreening;
        }
        void displayMovies() {
            cout << endl << "Displaying movies..." << endl;
            for(int i = 0; i < numMovies; i++) {
                cout << i + 1 << ". Title: " << movies[i]->getTitle() << ", Director: " << movies[i]->getDirector() << ", Duration: " << movies[i]->getDuration() << " hours, Is Screening: " << ((isScreening[i]) ? "Yes" : "No") << endl;
            }
            cout << endl;
        }
};

int main() {
    CinemaHall ch;
    ch.displayMovies();
}
