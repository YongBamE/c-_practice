#pragma once
#include <iostream>
#include "string.h"

using namespace std;
class Animal {
private:
	char* name;
public:
	Animal() {};
	Animal(char* myname)
	{
	}
	const char* getName() {
	}
	void setName(const char* myname) {
	}

	void ShowName() {
	}
	~Animal() {
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
