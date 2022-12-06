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


};
float Parking::maxEntrances = 20000;



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

}