#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Parking {
private:
	
	int TIcketID;
	int areas;
	int* spotsPerArea ;
	static float maxEntrances;

public:
	Parking()  {
		
		this->TIcketID = 1;
		this->areas = 4;
		this->spotsPerArea = new int[this->areas];
		this->spotsPerArea[0] = 300;
		this->spotsPerArea[1] = 500;
		this->spotsPerArea[2] = 400;
		this->spotsPerArea[3] = 150;
	}

	Parking(int TicketID, int Areas, int* spot) {

		this->TIcketID = TIcketID;
		this->areas = areas;
		this->spotsPerArea = new int[this->areas];
		for (int i = 0; i < this->areas; i++) {
			this->spotsPerArea[i] = spot[i];
		}
	}

	int* getSpotPerArea() {

		return this->spotsPerArea;
	}

	void setSpotPerArea(int nr, int* spot) {

		if (this->spotsPerArea) { delete[]this->spotsPerArea; }

	}



};
float Parking::maxEntrances=20000


