//동적할당 new, delete
//이중포인터로 원하는만큼 방만들기
//virtual 소멸자.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

using namespace std;

class Animal {
private:
	char* name;
public:
	//생성자
	Animal() {};
	Animal(char* myname) : name(myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	//get,set
	const char* getName() {
		return name;
	}
	void setName(const char* myname) {
		this->name = new char[strlen(myname) + 1];
		strcpy(this->name, myname);
	}
	//기능
	virtual void checkout() {
		cout << "?? 잘가" << endl;
	}
	virtual void checkin() {
		cout << "?? 어서와" << endl;
	}
	//소멸자
	virtual ~Animal() {
		delete[]name;
	}
};

class Dog : public Animal {

public:
	//생성자
	Dog() {};
	Dog(char* name) : Animal(name) {

	};
	//기능
	void checkout() {
		cout << "멍멍 잘가" << endl;
	}
	void checkin() {
		cout << "멍멍 어서와" << endl;
	}
};
class Cat : public Animal {

public:
	//생성자
	Cat() {};
	Cat(char* name) : Animal(name) {};
	//기능
	void checkout() {
		cout << "냥냥 잘가" << endl;
	}
	void checkin() {
		cout << "냥냥 어서와" << endl;
	}

};
class AnimalHotel {
private:
	Animal* animalRoom[8];
	//Animal* animalRoom = new Animal[8]; //이렇게 선언은 되는데 잘 안됐음. 
	int roomnum = 0;
	char specific[20];
	char name[20];

public:
	//생성자
	AnimalHotel() {
		for (int i = 0; i < 8; i++)
		{
			animalRoom[i] = 0;
		}
	}

	//기능
	void checkin(Animal* a) {
		cout << "방을 선택하세요" << endl;
		cin >> roomnum;

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
		animalRoom[roomnum] = a;	//private의 주석부분 Animal* animalRoom = new Animal[8]로 선언했을 때는 animalRoom[roomnum] = *a; 하니까 동작은 됐음. 하지만 결과가 checkout할 때, Animal크기만큼 할당하여 더 많은 크기를 가진 Dog와 Cat부분은 할당 못받음.

	}

	void checkout(Animal* a) {
		cout << "방을 선택하세요" << endl;
		cin >> roomnum;
		animalRoom[roomnum]->checkout();
		delete animalRoom[roomnum];
		animalRoom[roomnum] = 0;
	}

	void roomcheck() {
		cout << "방\t이름" << endl;
		for (int i = 0; i < 8; i++) {
			if (animalRoom[i] == 0)
				continue;
			cout << i << "\t" << animalRoom[i]->getName() << endl;
		}

	}
	void servicelist() {
		cout << "메뉴를 선택해주세요" << endl;
		cout << "1. 체크인" << endl;
		cout << "2. 체크아웃" << endl;
		cout << "3. 리스트확인" << endl;
		cout << "4. 나가기" << endl;
	}


};

int main() {

	AnimalHotel* hotel = new AnimalHotel();
	Animal* animal = new Animal;

	int menu = 0;


	while (1) {
		hotel->servicelist();
		cin >> menu;

		if (menu == 1) {//체크인

			hotel->checkin(animal);
		}
		else if (menu == 2) {//체크아웃
			hotel->checkout(animal);
		}
		else if (menu == 3) {//조회
			hotel->roomcheck();
		}
		else if (menu == 4) {
			return 0;
		}
		else {
			cin.clear();
			cin.ignore(100, '\n');
		}

		//delete animal;

	}

	return 0;
}