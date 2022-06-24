#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

using namespace std;

class Animal {
private:
	char* name;
public:
	//생성자
	Animal();
	Animal(char* myname);
	//get,set
	const char* getName() const;
	void setName(const char* myname);
	//기능
	virtual void checkout();
	virtual void checkin();
	//소멸자
	virtual ~Animal();
};