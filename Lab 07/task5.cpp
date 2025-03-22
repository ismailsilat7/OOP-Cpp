#include <iostream>
using namespace std;

class Media{
    protected:
        string title;
        int publicationDate;
        string uniqueID;
        string publisher;
        bool available;
    public:
        Media(string t, int p, string i, string pu, bool a):title(t),publicationDate(p),uniqueID(i),publisher(pu),available(a){}

        virtual void displayInfo(){
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl << endl;
        }

        void checkout(){
            if(available == 0){
                cout << "Item is not available for checkout." << endl; 
            }
            else{
                available = 0;
                cout << "Item checked out successfully." << endl;
            }
        }

        void returnItem(){
            available = 1;
            cout << "Item returned successfully." << endl;
        }
        string getTitle() { return title; }
        int getDate() { return publicationDate; }
};

class Book: public Media{
    private:
        string author;
        string ISBN;
        int numOfPages;
    public:
        Book(string t, int p, string i, string pu, bool a, string x, string is, int n):Media(t,p,i,pu,a),author(x),ISBN(is),numOfPages(n) {}

        void displayInfo() override{
            cout << "----Book----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Author: " << author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Number Of Pages: " << numOfPages << endl << endl;
        }
};

class DVD: public Media{
    private:
        string director;
        string duration;
        float ratings;
    public:
        DVD(string t, int p, string i, string pu, bool a, string x, string is, float n):Media(t,p,i,pu,a),director(x),duration(is),ratings(n) {}

        void displayInfo() override{
            cout << "----DVD----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << endl;
            cout << "Ratings: " << ratings << endl << endl;
        }
};

class CD: public Media{
    private:
        string artist;
        string genre;
        int numOfTracks;
    public:
        CD(string t, int p, string i, string pu, bool a, string x, string is, int n):Media(t,p,i,pu,a),artist(x),genre(is),numOfTracks(n) {}

        void displayInfo()override{
            cout << "----CD----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Artist: " << artist << endl;
            cout << "Genre: " << genre << endl;
            cout << "Number OF Tracks: " << numOfTracks << endl << endl;
        }
};

class Magazine: public Media{
    private:
        int magazineCode;
    public:
        Magazine(string t, int p, string i, string pu, bool a, int m):Media(t,p,i,pu,a), magazineCode(m) {}

        void displayInfo()override{
            cout << "----Magazine----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Magazine Code: " << magazineCode << endl;
        }
};

class Library {
    private:
        Media ** collection;
        int numItems;
    public:
        Library() : collection(nullptr), numItems(0) {}
        void addMedia(Media *m) {
            Media** tempCollection = new Media*[numItems + 1];
            for(int i = 0; i < numItems; i++) {
                tempCollection[i] = collection[i];
            }
            tempCollection[numItems] = m;
            delete[] collection;
            numItems++;
            collection = tempCollection;
        }
        void searchMedia(string title) {
            cout << endl << "Searching media by title: " << title << endl;
            for(int i = 0; i < numItems; i++) {
                if(collection[i]->getTitle() == title) {
                    cout << "Media Item Found!" << endl;
                    collection[i]->displayInfo();
                    return;
                }
            }
            cout << "No media with matching title found!" << endl;
        }
        void searchMedia(int year) {
            cout << endl << "Searching all media published on year " << year << endl;
            bool found = false;
            for(int i = 0; i < numItems; i++) {
                if(collection[i]->getDate() == year) {
                    found = true;
                    collection[i]->displayInfo();
                }
            }
            if(!found) {
                cout << "No Media with matching publication year found" << endl;
            }
        }
        ~Library() {
            if(numItems > 0) {
                delete[] collection;
            }
        }
};

int main() {
    Library lib;

    Book *b1 = new Book("Pakistan: A Hard Country", 2011, "B001", "Oxford University Press", true, "Anatol Lieven", "978-0199895753", 560);
    DVD *d1 = new DVD("The Legend of Maula Jatt", 2022, "D001", "Geo Films", true, "Bilal Lashari", "2h 33m", 9.1);
    CD *c1 = new CD("Coke Studio Season 14", 2022, "C001", "Coke Studio Pakistan", true, "Various Artists", "Fusion", 13);
    Magazine *m1 = new Magazine("Herald", 2023, "M001", "Dawn Media Group", true, 1001);

    lib.addMedia(b1);
    lib.addMedia(d1);
    lib.addMedia(c1);
    lib.addMedia(m1);

    b1->displayInfo();
    d1->displayInfo();
    c1->displayInfo();
    m1->displayInfo();

    lib.searchMedia("Herald");

    lib.searchMedia(2022);

    cout << endl;
    b1->checkout();
    b1->returnItem();

    delete b1;
    delete d1;
    delete c1;
    delete m1;

    return 0;
}

