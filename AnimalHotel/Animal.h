#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

using namespace std;

class Animal {
private:
	char* name;
public:
	//������
	Animal();
	Animal(char* myname);
	//get,set
	const char* getName() const;
	void setName(const char* myname);
	//���
	virtual void checkout();
	virtual void checkin();
	//�Ҹ���
	virtual ~Animal();
};