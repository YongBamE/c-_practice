//�̻ڰ� �����

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "string.h"
#include "Animal.h"
#include "AnimalHotel.h"

using namespace std;

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
			system("pause");
		}
		else if (menu == 2) {//üũ�ƿ�
			hotel->checkout(animal);
			system("pause");
		}
		else if (menu == 3) {//��ȸ
			hotel->roomcheck();
			system("pause");
		}
		else if (menu == 4) {
			cout << "��������" << endl;
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