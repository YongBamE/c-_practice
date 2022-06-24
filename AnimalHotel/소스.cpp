//���������� => animalRoom = new Animal * [roomnum];
//virtual delete -> ���ָ� �ڽ�Ŭ������ ����Ʈ�� �����ش�.

//Ŭ���� ������ �̻ڰ� �����
//����Ʈ�� ���°��� ���̰� �ϱ�.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
#include <windows.h>

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
	Animal** animalRoom;
	//Animal* animalRoom = new Animal[8]; //�̷��� ������ �Ǵµ� �� �ȵ���. 
	int roomselect = 0;
	int roomnum = 0;
	char specific[20];
	char name[20];

public:
	//������
	AnimalHotel() {
		// 
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
	void checkin(Animal* a) {
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
		animalRoom[roomselect] = a;	//private�� �ּ��κ� Animal* animalRoom = new Animal[8]�� �������� ���� animalRoom[roomselect] = *a; �ϴϱ� ������ ����. ������ ����� checkout�� ��, Animalũ�⸸ŭ �Ҵ��Ͽ� �� ���� ũ�⸦ ���� Dog�� Cat�κ��� �Ҵ� ������.

	}

	void checkout(Animal* a) {
		cout << "���� �����ϼ���" << endl;
		cin >> roomselect;
		animalRoom[roomselect]->checkout();
		delete animalRoom[roomselect];
		animalRoom[roomselect] = 0;
	}

	void roomcheck() {
		cout << "��\t�̸�" << endl;
		
		for (int i = 0; i < roomnum; i++) {
			//continue�� �������� �׳� �ܼ�â�� ����.
			if (animalRoom[i] == 0) {
				cout << i << "\t" << "x" << endl;
				continue;
			}
				
			cout << i << "\t" << animalRoom[i]->getName() << endl;
		}
		system("pause");

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
		system("cls");
		hotel->servicelist();
		cin >> menu;
		system("cls");
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