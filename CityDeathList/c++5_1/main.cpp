#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <windows.h>
#include "City.h"
#include "DeathList.h"

using namespace std;

int main()
{
	enum menu_type {
		list = 1, subtotal, exit
	};
	enum subtotal_menu {
		city = 1
	};


	int menu = 0;		// 1. ����Ʈ 2. �κ��� 3. ����
	int submenu = 0;
	DeathList deathlist;
	deathlist.Dataset();		//�������ϼ� ���� ����.
	
	while (1) {

		cout << "�޴��� �����ϼ��� 1. ����Ʈ/ 2. �κ��� / 3. ����" << endl;
		cin >> menu;

		if (menu == list) {

			deathlist.PrintList();
			system("pause");
			system("cls");
		}
		else if (menu == subtotal) {
			cout << "1. ���� �κ���" << endl;
			cin >> submenu;

			if (submenu == city) {
				//deathlist->SearchCity();	//string ������ search������ �޾Ƽ� �����Ѵ�.
				deathlist.subtotal();
			}

			system("pause");
			system("cls");

		}


	}

	

	/*
	vector<Student*> v1;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		v1.push_back(new Student());
	}
	*/
	


	/*
	int cityNum = 0, int dataNum = 0;

	
	

	while (std::getline(file, line))	//���پ� ���������� data�� line������ ���پ� string���·� �־��ش�.
	{
		stringstream  lineStream(line);	//line�� stringstream���·� ��ȯ
		string        cell;				//lineStream�� �ٽ� string�������� �޾��� ����.


		while (std::getline(lineStream, cell, ','))	//,�� ��� ���ö����� lineStream�� cell�� string���·� �־��ش�.
		{
			data[cityNum][dataNum] = cell;
			
			dataNum++;
		}
		cityNum++;
		dataNum = 0;
	}
	*/
	//if (search == data[cityNum][0] || search == data[cityNum][1]) 	//�� line�� �ó� ���̶� ���� ���.	city�ν��Ͻ��� ���� ������ �� ���� �ٲ���.

	
	/*
	string str = "abc";
	string str2 = "abc";

	if (str == str2) {
		cout << "Same";
		string ret = str + str2;
		cout << ret;
	}
	*/

}
//������
// c:\~~~\~~.txt
//�����
// ./~~~~.txt
// ../../~~~.txt
//������ ����� ��������.

//csv : comma seperate value