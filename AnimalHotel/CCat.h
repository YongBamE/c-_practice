#pragma once
#include "Animal.h"
using namespace std;

class Cat : public Animal {

public:
	//������
	Cat();
	Cat(char* name);
	//���
	void checkout();
	void checkin();
};