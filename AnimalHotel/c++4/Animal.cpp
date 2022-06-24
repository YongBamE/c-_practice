#include <iostream>
#include "Animal.h"
#include "string.h"

using namespace std;
class Animal {
private:
	char* name;
public:
	Animal() {};
	Animal(char* myname) : name(myname)
	{
		name = new char(strlen(myname) + 1);
		strcpy(name, myname);
	}
	const char* getName() {
		return name;
	}
	void setName(const char* myname) {
		this->name = new char(strlen(myname) + 1);
		strcpy(this->name, myname);
	}
	void ShowName() {
		cout << "저는" << name << "입니다" << endl;
	}
	~Animal() {
		delete[]name;
	}


};

class Dog : public Animal {

public:
	Dog(char* name) : Animal(name) {

	};
};
class Cat : public Animal {

public:
	Cat(char* name) : Animal(name) {};

};
