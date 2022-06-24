#pragma once
#include "Animal.h"
using namespace std;

class Cat : public Animal {

public:
	//생성자
	Cat();
	Cat(char* name);
	//기능
	void checkout();
	void checkin();
};