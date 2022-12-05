#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Stadium {
private:
	char* name;
	const int pitchSize;
	int Capacity;

public:

	Stadium():pitchSize(100) {

		this->name = new char[strlen("Bernabeu") + 1];
		strcpy(this->name, "Bernabeu");
		this->Capacity = 30000;

	}

	Stadium(const char* name, int capacity, int pitchSize) :pitchSize(pitchSize) {

		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name );
		this->Capacity = Capacity;
	}

	Stadium(const Stadium& s):pitchSize(pitchSize) {

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

	if (this->name) { delete[]this->name; }
		if (strlen(name) > 1) {

			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);


	}



};