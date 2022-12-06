#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Parking {
private:
	
	int TicketID;
	int areas;
	int* spotsPerArea ;
	static float maxEntrances;

public:
	Parking()  {
		
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
		if(newID>0)
		this->TicketID = newID;

	}

	int getNewNrOfAreas() {

		return this->areas;
	}

	void setNewNrOfAreas(int newNrOfAreas) {
		if(newNrOfAreas<10)
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

	
