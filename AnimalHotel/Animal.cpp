#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "string.h"

using namespace std;


	Animal::Animal() {};
	Animal::Animal(char* myname) : name(myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	//get,set
	const char* Animal::getName() const {
		return name;
	}
	void Animal::setName(const char* myname) {
		this->name = new char[strlen(myname) + 1];
		strcpy(this->name, myname);
	}
	//���
	void Animal ::checkout() {
		cout << "?? �߰�" << endl;
	}
	void Animal :: checkin() {
		cout << "?? ���" << endl;
	}
	//�Ҹ���
	Animal :: ~Animal() {
		delete[]name;
	}
