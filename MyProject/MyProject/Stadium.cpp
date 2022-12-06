#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Stadium {
private:

	char* name;
	const int pitchSize;
	int Capacity;

public:

	Stadium() :pitchSize(100) {

		this->name = new char[strlen("Bernabeu") + 1];
		strcpy(this->name, "Bernabeu");
		this->Capacity = 30000;

	}

	Stadium(const char* name, int capacity, int pitchSize) :pitchSize(pitchSize) {

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->Capacity = capacity;
	}

	Stadium(const Stadium& s) :pitchSize(s.pitchSize) {

		this->name = new char[strlen(s.name) + 1];
		strcpy(this->name, s.name);
		this->Capacity = s.Capacity;
		

	}

	Stadium& operator=(Stadium& s) {
		if (this->name) { delete[]this->name; }
		this->name = new char[strlen(s.name) + 1];
		strcpy(this->name, s.name);
		this->Capacity = s.Capacity;

		return *this;

	}

	~Stadium() {

		if (this->name) {

			delete[]this->name;

		}

	}

	char* getName() {

		return this->name;

	}

	void setName(const char* newName) {



		if (strlen(newName) > 1) {

			if (this->name) {
				delete[]this->name;
			}

			this->name = new char[strlen(newName) + 1];
			strcpy(this->name, newName);
		}

	}

	int getCapacity() {

		return this->Capacity;

	}

	void setCapacity(int newCapacity) {

		if (newCapacity > 5000) {

			this->Capacity = newCapacity;

		}
	}

	int getPitchSize() {

		return this->Capacity;

	}


	friend ostream& operator<<(ostream& out, Stadium& s) {
		out << "\n -The name of the stadium is:" << s.name << "\n -Pitch Size: " << s.pitchSize << " \n-Capacity: " << s.Capacity;
	
	return out;
	}
	friend istream& operator>>(istream& in, Stadium& s) {
		
		char buffer[25];
		cout << " Name: ";
		in >> buffer;
		if (s.name) { delete[]s.name; }
		s.name = new char[strlen(buffer) + 1];
		strcpy(s.name, buffer);
		cout << "Capacity";
		in >> s.Capacity;
		return in;
	}


	Stadium& operator+(int x) {
		this->Capacity += x;
		return *this;
	}


	bool operator<(Stadium& s) {

		if (this->Capacity < s.Capacity) {
			return true;
		}
		else return false;

	}

};


class Parking {
private:

	int TicketID;
	int areas;
	int* spotsPerArea;
	static float maxEntrances;

public:
	Parking() {

		this->TicketID = 1;
		this->areas = 4;
		this->spotsPerArea = new int[this->areas];
		this->spotsPerArea[0] = 300;
		this->spotsPerArea[1] = 500;
		this->spotsPerArea[2] = 400;
		this->spotsPerArea[3] = 150;
	}

	Parking(int TicketID, int areas, int* spot) {

		this->TicketID = TicketID;
		this->areas = areas;
		this->spotsPerArea = new int[this->areas];
		for (int i = 0; i < this->areas; i++) {
			this->spotsPerArea[i] = spot[i];
		}
	}

	Parking(const Parking& p) {

		this->TicketID = p.TicketID;
		this->areas = p.areas;
		this->spotsPerArea = new int[this->areas];
		for (int i = 0; i < this->areas; i++) {
			this->spotsPerArea[i] = p.spotsPerArea[i];
		}

	}

	Parking& operator=(Parking& p) {

		this->TicketID = p.TicketID;
		this->areas = p.areas;
		this->spotsPerArea = new int[this->areas];
		if (this->spotsPerArea) { delete[]this->spotsPerArea; }
		for (int i = 0; i < this->areas; i++) {
			this->spotsPerArea[i] = p.spotsPerArea[i];
		}

	}

	int* getSpotPerArea() {

		return this->spotsPerArea;
	}

	void setSpotPerArea(int nr, int* spot) {

		if (this->spotsPerArea) { delete[]this->spotsPerArea; }
		this->areas = nr;
		this->spotsPerArea = new int[this->areas];
		for (int i = 0; i < this->areas; i++) {
			this->spotsPerArea[i] = spot[i];
		}
	}

	int getID() {

		return this->TicketID;
	}

	void setID(int newID) {
		if (newID > 0)
			this->TicketID = newID;

	}

	int getNewNrOfAreas() {

		return this->areas;
	}

	void setNewNrOfAreas(int newNrOfAreas) {
		if (newNrOfAreas < 10)
			this->areas = newNrOfAreas;

	}

	~Parking() {

		if (this->spotsPerArea)
		{ 
			delete[]this->spotsPerArea; 
		}

	}


	friend ostream& operator<<(ostream& out, Parking& p) {
		out << "\n -The Ticket ID number is:" << p.TicketID << "\n number of areas: " << p.areas;

		for (int i = 0; i < p.areas; i++) {
			out << i << "-----> " << p.spotsPerArea[i];
		}

		return out;
	}
	/*friend istream& operator>>(istream& in, Parking& p) {

		char buffer[25];
		cout << " Name: ";
		in >> buffer;
		if (s.name) { delete[]s.name; }
		s.name = new char[strlen(buffer) + 1];
		strcpy(s.name, buffer);
		cout << "Capacity";
		in >> s.Capacity;
		return in;
	}*/

	int& operator[](int pos) {
		return this->spotsPerArea[pos];
	}

	bool CanTheyEnterTheParking(int nr) {
		if (this->TicketID > 0) {
			return true;
		}
		else {
			return false;
		}
	}

};
float Parking::maxEntrances = 20000;


class Team {
private:

	char* KitColor;
	const int noOfStartingPlayers;
	int noOfTrophies;
public:

	Team() :noOfStartingPlayers(11) {

		this->KitColor = new char[strlen("Blue") + 1];
		strcpy(this->KitColor, "Blue");
		this->noOfTrophies = 3;

	}

	Team(const char* KitColor, int noOfTrophies, int noOfStartingPlayers) :noOfStartingPlayers(noOfStartingPlayers) {

		this->KitColor = new char[strlen(KitColor) + 1];
		strcpy(this->KitColor, KitColor);
		this->noOfTrophies = noOfTrophies;

	}

	Team(const Team& t) :noOfStartingPlayers(t.noOfStartingPlayers) {
		this->noOfTrophies = t.noOfTrophies;
		this->KitColor = new char[strlen(t.KitColor) + 1];
		strcpy(this->KitColor, t.KitColor);

	}

	Team& operator=(Team& t) {

		this->noOfTrophies = t.noOfTrophies;
		if (this->KitColor) { delete[]this->KitColor; }
		this->KitColor = new char[strlen(t.KitColor) + 1];
		strcpy(this->KitColor, t.KitColor);

		return*this;

	}
	~Team() {

		if (this->KitColor) {

			delete[]this->KitColor;
		}

	}


	char* getKitColor() {

		return this->KitColor;
	}

	void setKitColor(const char* newKitColor) {

		if (strlen(newKitColor) > 1) {

			if (this->KitColor) {
				delete[]this->KitColor;
			}

			this->KitColor = new char[strlen(newKitColor) + 1];
			strcpy(this->KitColor, newKitColor);
		}


	}

	int GetNoOfTrophies() {

		return this->noOfTrophies;


	}

	void setNumberOfTrophis(int newNoOfTrophies) {

		this->noOfTrophies = newNoOfTrophies;

	}

	int GetNoOfStartingPlayers() {

		return this->noOfStartingPlayers;


	}


	friend ostream& operator<<(ostream& out, Team& t) {
		out << "\n -The Kit color is::" << t.KitColor << "\n -NUmber of trophies: " << t.noOfTrophies;

		return out;
	}
	friend istream& operator>>(istream& in, Team& t) {

		char buffer[25];
		cout << " Kit color: ";
		in >> buffer;
		if (t.KitColor) { delete[]t.KitColor; }
		t.KitColor = new char[strlen(buffer) + 1];
		strcpy(t.KitColor, buffer);
		cout << "No. of trophies";
		in >> t.noOfTrophies;
		return in;
	}

	Team& operator-(int x) {

		this->noOfTrophies -= x;
		return*this;
	}


	Team& operator++() {


		noOfTrophies++;
		return *this;

	}
	Team& operator++(int) {

		Team t;
		noOfTrophies++;
		return t;

	}
	};



void main() {

	
	Stadium s1;
	Stadium s2("Bernabeu", 50000, 100);
	Stadium s3 = s2;
	s1 = s3;
	cout << "-------------------------------First Class-----------------------------------";
	cout << endl << s2.getName(); s2.setName("Camp Nou");
	cout << endl << s2.getCapacity(); s2.setCapacity(60000);
	cout << endl << s2.getPitchSize();
	cout << endl << s2;
	cout << "\n------------";
	cout << s3;
	s2 = s3 + 5000;
	cout << "\n------Added-Capacity-----";
	cout << s3;
	if (s2 < s3 ) {
		cout << "\n -Stadium capacity is larger";
	}
	else { cout << "\n-Stadium capacity is smaller"; }
	cout << "\n-------------------------------Second Class-----------------------------------";

	Parking p1;
	Parking p2(2, 4, new int[4]{ 500,700,800,250 });
	cout << p2.getID(); p2.setID(5);
	cout << p2.getNewNrOfAreas(); p2.setNewNrOfAreas(3);
	cout << p2.getSpotPerArea(); p2.setSpotPerArea(2, new int[2]{ 500,600 });
	p2[2] = 1000;
	cout << endl << p2[2];
	Parking p3 = p2;
	cout << "\n-------" << p2 << "\n------" << p3;

	if (p3.CanTheyEnterTheParking(2)) {
		cout << "\nThey can";
	}
	else {
		cout << "\nThey can't";

	}

	Team t1;
	Team t2("Red", 3, 11);
	Team t3 = t2;
	t3 = t1;
	cout << "\n-------------------------------Second Class-----------------------------------";
	cout << t2.getKitColor(); t2.setKitColor("Purple");
	cout << t2.GetNoOfTrophies(); t2.setNumberOfTrophis(16);
	cout << t2.GetNoOfStartingPlayers();
	cout <<endl << t2;
	t2 = t3 - 100;
	cout << endl<< t2;
	++t3;
	cout << endl << t3;
	t3++;
	cout << t3;



	
}