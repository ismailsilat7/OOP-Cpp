#include <iostream>
using namespace std;

class Person {
	private:
		string name;
		int age;
		
	public: 
		Person (string name, int age) : name(name), age(age) {}
		
		virtual void displayDetails() {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
		}
};

class Teacher : virtual public Person {
    string subject; 
	public:
		
		Teacher (string name, int age, string subject)
		: Person (name, age), subject(subject) {}
		string getSubject() { return subject; }
		void displayDetails() override {
		    Person::displayDetails();
			cout << "Subject: " << subject << endl;
		}
		
};

class Researcher : virtual public Person {
    string researchArea; 
	public:
		
		Researcher (string name, int age, string researchArea)
		: Person (name, age), researchArea(researchArea) {}
		string getResearch() { return researchArea; }
		void displayDetails() override {
			Person::displayDetails();
			cout << "Research Area: " << researchArea << endl;
		}
		
};

class Professor : public Researcher, public Teacher {
    int publications; 
	public:
		
		Professor (string name, int age, string subject,string researchArea, int publications)
		: Person(name, age) ,Researcher (name, age, researchArea), Teacher(name, age, subject), publications (publications) {}
		
		void displayDetails() override {
		    Person::displayDetails();
			cout << "Subject: " << getSubject() << endl << "Research Area: " << getResearch() << endl << "Publications: " << publications << endl;
		}
		
};

int main() {
	
	Professor ismail("Ismail Silat", 19, "Computer Science", "AI", 45 ) ;
	 
	ismail.displayDetails();
	
	return 0;
}