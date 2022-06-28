#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "DeathList.h"

using namespace std;

DeathList::DeathList() {				//�ܺ� ��Ƽ �����͸� �����Ҵ�.
	city = new City * [230];
	for (int i = 0; i < 230; i++) {
		city[i] = 0;
	}
}
string DeathList::getSearch() {
	return search;
}

void DeathList::Dataset() {
	ifstream  file("ANSIData.csv");		//�̰� deathlist�� �ִ°� ������?
	string line;
	
	//string data[229][30];	//��� �̵��� City�ν��Ͻ��� �� ���̴�.	data[]������ �ν��Ͻ� �ּҰ� �ɰ��̰� data[][]�� �ν��Ͻ� ���� data���� �� ���̴�.
	int cityNum = 0;
	int dataNum = 0;

	while (std::getline(file, line))	//���پ� ���������� data�� line������ ���پ� string���·� �־��ش�.
	{
		stringstream  lineStream(line);	//line�� stringstream���·� ��ȯ
		string        cell;				//lineStream�� �ٽ� string�������� �޾��� ����.

		city[cityNum] = new City();
		while (std::getline(lineStream, cell, ','))	//,�� ��� ���ö����� lineStream�� cell�� string���·� �־��ش�.
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

	cout << "���ø��� �˻��ϼ���" << endl;
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
	
	cout << "���ø��� �˻��ϼ���" << endl;
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