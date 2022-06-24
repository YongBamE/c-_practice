#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

#include "Animal.h"
#include "CDog.h"
#include "CCat.h"

class AnimalHotel {
private:
	Animal** animalRoom;
	//Animal* animalRoom = new Animal[8]; //�̷��� ������ �Ǵµ� �� �ȵ���. 
	int roomselect = 0;
	int roomnum = 0;
	char specific[20];
	char name[20];

public:
	//������
	AnimalHotel();

	//���
	void checkin(Animal* a);
	void checkout(Animal* a);

	void roomcheck();
	void servicelist();
};

