//�����Ҵ� new, delete
//���������ͷ� ���ϴ¸�ŭ �游���
//virtual �Ҹ���.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

using namespace std;

class Animal {
private:
	char* name;
public:
	//������
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
	//���
	virtual void checkout() {
		cout << "?? �߰�" << endl;
	}
	virtual void checkin() {
		cout << "?? ���" << endl;
	}
	//�Ҹ���
	virtual ~Animal() {
		delete[]name;
	}
};

class Dog : public Animal {

public:
	//������
	Dog() {};
	Dog(char* name) : Animal(name) {

	};
	//���
	void checkout() {
		cout << "�۸� �߰�" << endl;
	}
	void checkin() {
		cout << "�۸� ���" << endl;
	}
};
class Cat : public Animal {

public:
	//������
	Cat() {};
	Cat(char* name) : Animal(name) {};
	//���
	void checkout() {
		cout << "�ɳ� �߰�" << endl;
	}
	void checkin() {
		cout << "�ɳ� ���" << endl;
	}

};
class AnimalHotel {
private:
	Animal* animalRoom[8];
	//Animal* animalRoom = new Animal[8]; //�̷��� ������ �Ǵµ� �� �ȵ���. 
	int roomnum = 0;
	char specific[20];
	char name[20];

public:
	//������
	AnimalHotel() {
		for (int i = 0; i < 8; i++)
		{
			animalRoom[i] = 0;
		}
	}

	//���
	void checkin(Animal* a) {
		cout << "���� �����ϼ���" << endl;
		cin >> roomnum;

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
		animalRoom[roomnum] = a;	//private�� �ּ��κ� Animal* animalRoom = new Animal[8]�� �������� ���� animalRoom[roomnum] = *a; �ϴϱ� ������ ����. ������ ����� checkout�� ��, Animalũ�⸸ŭ �Ҵ��Ͽ� �� ���� ũ�⸦ ���� Dog�� Cat�κ��� �Ҵ� ������.

	}

	void checkout(Animal* a) {
		cout << "���� �����ϼ���" << endl;
		cin >> roomnum;
		animalRoom[roomnum]->checkout();
		delete animalRoom[roomnum];
		animalRoom[roomnum] = 0;
	}

	void roomcheck() {
		cout << "��\t�̸�" << endl;
		for (int i = 0; i < 8; i++) {
			if (animalRoom[i] == 0)
				continue;
			cout << i << "\t" << animalRoom[i]->getName() << endl;
		}

	}
	void servicelist() {
		cout << "�޴��� �������ּ���" << endl;
		cout << "1. üũ��" << endl;
		cout << "2. üũ�ƿ�" << endl;
		cout << "3. ����ƮȮ��" << endl;
		cout << "4. ������" << endl;
	}


};

int main() {

	AnimalHotel* hotel = new AnimalHotel();
	Animal* animal = new Animal;

	int menu = 0;


	while (1) {
		hotel->servicelist();
		cin >> menu;

		if (menu == 1) {//üũ��

			hotel->checkin(animal);
		}
		else if (menu == 2) {//üũ�ƿ�
			hotel->checkout(animal);
		}
		else if (menu == 3) {//��ȸ
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