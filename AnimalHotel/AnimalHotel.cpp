#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

#include "AnimalHotel.h"
#include "Animal.h"
#include "CDog.h"
#include "CCat.h"



	//생성자
	AnimalHotel ::AnimalHotel() {
		cout << "방을 개수 선택하세요" << endl;
		cin >> roomnum;
		animalRoom = new Animal * [roomnum];
		// null값으로 초기화 해준다.
		for (int i = 0; i < roomnum; i++)
		{
			animalRoom[i] = 0;
		}
	}

	//기능
	void AnimalHotel::checkin(Animal* a) {
		cout << "방을 선택하세요" << endl;
		cin >> roomselect;

		cout << "이름을 입력하세요" << endl;
		cin >> name;

		cout << "종을 입력하세요" << endl;
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
		//private의 주석부분 Animal* animalRoom = new Animal[8]로 선언했을 때는 animalRoom[roomselect] = *a; 하니까 동작은 됐음. 하지만 결과가 checkout할 때, Animal크기만큼 할당하여 더 많은 크기를 가진 Dog와 Cat부분은 할당 못받음.
		animalRoom[roomselect] = a;	

	}

	void AnimalHotel::checkout(Animal* a) {
		cout << "방을 선택하세요" << endl;
		cin >> roomselect;
		animalRoom[roomselect]->checkout();
		delete animalRoom[roomselect];
		animalRoom[roomselect] = 0;
	}

	void AnimalHotel::roomcheck() {
		cout << "방\t이름" << endl;

		for (int i = 0; i < roomnum; i++) {
			//continue를 안적으면 그냥 콘솔창이 끝남.
			if (animalRoom[i] == 0) {
				cout << i << "\t" << "x" << endl;
				continue;
			}

			cout << i << "\t" << animalRoom[i]->getName() << endl;
		}
	}
	void AnimalHotel::servicelist() {
		cout << "메뉴를 선택해주세요" << endl;
		cout << "1. 체크인" << endl;
		cout << "2. 체크아웃" << endl;
		cout << "3. 리스트확인" << endl;
		cout << "4. 나가기" << endl;
	}

