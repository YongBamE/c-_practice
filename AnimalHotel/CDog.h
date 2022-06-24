#pragma once
#include "Animal.h"
using namespace std;

class Dog : public Animal {

public:
	Dog();
	Dog(char* name);

	void checkout();
	void checkin();
};