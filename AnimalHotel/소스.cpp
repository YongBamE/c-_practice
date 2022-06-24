//이쁘게 만들기

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
		if (menu == 1) {//체크인
			hotel->checkin(animal);
			system("pause");
		}
		else if (menu == 2) {//체크아웃
			hotel->checkout(animal);
			system("pause");
		}
		else if (menu == 3) {//조회
			hotel->roomcheck();
			system("pause");
		}
		else if (menu == 4) {
			cout << "영업종료" << endl;
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