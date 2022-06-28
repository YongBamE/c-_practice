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


	int menu = 0;		// 1. 리스트 2. 부분합 3. 종료
	int submenu = 0;
	DeathList deathlist;
	deathlist.Dataset();		//엑셀파일속 내용 저장.
	
	while (1) {

		cout << "메뉴를 선택하세요 1. 리스트/ 2. 부분합 / 3. 종료" << endl;
		cin >> menu;

		if (menu == list) {

			deathlist.PrintList();
			system("pause");
			system("cls");
		}
		else if (menu == subtotal) {
			cout << "1. 도시 부분합" << endl;
			cin >> submenu;

			if (submenu == city) {
				//deathlist->SearchCity();	//string 형태의 search변수를 받아서 설정한다.
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

	
	

	while (std::getline(file, line))	//한줄씩 끝날때까지 data를 line변수에 한줄씩 string형태로 넣어준다.
	{
		stringstream  lineStream(line);	//line을 stringstream형태로 변환
		string        cell;				//lineStream을 다시 string형식으로 받아줄 변수.


		while (std::getline(lineStream, cell, ','))	//,이 계속 나올때까지 lineStream을 cell에 string형태로 넣어준다.
		{
			data[cityNum][dataNum] = cell;
			
			dataNum++;
		}
		cityNum++;
		dataNum = 0;
	}
	*/
	//if (search == data[cityNum][0] || search == data[cityNum][1]) 	//그 line의 시나 군이랑 같을 경우.	city인스턴스의 값을 받으면 그 경우로 바꾸자.

	
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
//절대경로
// c:\~~~\~~.txt
//상대경로
// ./~~~~.txt
// ../../~~~.txt
//리눅스 우분투 같은느낌.

//csv : comma seperate value