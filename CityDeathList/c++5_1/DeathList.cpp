#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "DeathList.h"

using namespace std;

DeathList::DeathList() {				//외부 시티 데이터를 동적할당.
	city = new City * [230];
	for (int i = 0; i < 230; i++) {
		city[i] = 0;
	}
}
string DeathList::getSearch() {
	return search;
}

void DeathList::Dataset() {
	ifstream  file("ANSIData.csv");		//이게 deathlist에 있는게 맞을까?
	string line;
	
	//string data[229][30];	//얘는 이따가 City인스턴스가 들어갈 것이다.	data[]까지는 인스턴스 주소가 될것이고 data[][]는 인스턴스 내의 data값이 될 것이다.
	int cityNum = 0;
	int dataNum = 0;

	while (std::getline(file, line))	//한줄씩 끝날때까지 data를 line변수에 한줄씩 string형태로 넣어준다.
	{
		stringstream  lineStream(line);	//line을 stringstream형태로 변환
		string        cell;				//lineStream을 다시 string형식으로 받아줄 변수.

		city[cityNum] = new City();
		while (std::getline(lineStream, cell, ','))	//,이 계속 나올때까지 lineStream을 cell에 string형태로 넣어준다.
		{
			
			if (dataNum == 0) {
				city[cityNum]->setCityName(cell);
				//cout << city[cityNum]->getCityName() << endl;
				
			}
			else if(dataNum == 1) {
				city[cityNum]->setDistrictName(cell);
				//cout << city[cityNum]->getDistrictName() << endl;
			}
			else {
				city[cityNum]->setData(dataNum - 2, cell);
				//cout << city[cityNum]->getData()[dataNum-2] << endl;
			}
			
			
			
			dataNum++;
		}

		cityNum++;
		dataNum = 0;
	}

}
void DeathList::SearchCity() {

	cout << "도시명을 검색하세요" << endl;
	cin >> search;
	//getline(cin, search);
}

void DeathList::PrintList(){

	for (int i = 0; i < 229; i++) {
		
		cout << city[i]->getCityName();
		cout.width(14);
		cout << city[i]->getDistrictName();
		
		for (int j = 0; j < 11; j++) {
			cout.width(4);
			cout << city[i]->getData()[j];
		}
		cout << endl;
	}


}
void DeathList::subtotal() {
	
	cout << "도시명을 검색하세요" << endl;
	cin >> search;
	int data[11] = {};

	for (int i = 0; i < 229; i++) {
		
		if (search == city[i]->getCityName() || search == city[i]->getDistrictName()) {

			for (int j = 0; j < 11; j++) {
				data[j] += city[i]->getData()[j];
			}
		}
	}
	cout << search << " : ";
	for (int j = 0; j < 11; j++) {
		cout.width(4);
		cout << data[j];
	}


}