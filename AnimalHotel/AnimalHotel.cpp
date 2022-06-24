#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

#include "AnimalHotel.h"
#include "Animal.h"
#include "CDog.h"
#include "CCat.h"



	//������
	AnimalHotel ::AnimalHotel() {
		cout << "���� ���� �����ϼ���" << endl;
		cin >> roomnum;
		animalRoom = new Animal * [roomnum];
		// null������ �ʱ�ȭ ���ش�.
		for (int i = 0; i < roomnum; i++)
		{
			animalRoom[i] = 0;
		}
	}

	//���
	void AnimalHotel::checkin(Animal* a) {
		cout << "���� �����ϼ���" << endl;
		cin >> roomselect;

		cout << "�̸��� �Է��ϼ���" << endl;
		cin >> name;

		cout << "���� �Է��ϼ���" << endl;
		cin >> specific;
		if (strcmp(specific, "dog") == 0) {
			a = new Dog(name);
		}
		else if (strcmp(specific, "cat") == 0) {
			a = new Cat(name);
		}
		else {
			a = new Dog(name);
		}
		a->checkin();
		//private�� �ּ��κ� Animal* animalRoom = new Animal[8]�� �������� ���� animalRoom[roomselect] = *a; �ϴϱ� ������ ����. ������ ����� checkout�� ��, Animalũ�⸸ŭ �Ҵ��Ͽ� �� ���� ũ�⸦ ���� Dog�� Cat�κ��� �Ҵ� ������.
		animalRoom[roomselect] = a;	

	}

	void AnimalHotel::checkout(Animal* a) {
		cout << "���� �����ϼ���" << endl;
		cin >> roomselect;
		animalRoom[roomselect]->checkout();
		delete animalRoom[roomselect];
		animalRoom[roomselect] = 0;
	}

	void AnimalHotel::roomcheck() {
		cout << "��\t�̸�" << endl;

		for (int i = 0; i < roomnum; i++) {
			//continue�� �������� �׳� �ܼ�â�� ����.
			if (animalRoom[i] == 0) {
				cout << i << "\t" << "x" << endl;
				continue;
			}

			cout << i << "\t" << animalRoom[i]->getName() << endl;
		}
	}
	void AnimalHotel::servicelist() {
		cout << "�޴��� �������ּ���" << endl;
		cout << "1. üũ��" << endl;
		cout << "2. üũ�ƿ�" << endl;
		cout << "3. ����ƮȮ��" << endl;
		cout << "4. ������" << endl;
	}

