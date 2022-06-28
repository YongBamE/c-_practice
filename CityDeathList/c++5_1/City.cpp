#define _CRT_SECURE_NO_WARNINGS
#include "City.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

City::City() {}
City::City(const char* getname) {
	
	
}
string City::getCityName() {
	return cityName;
}
string City::getDistrictName() {
	return districtName;
}
int* City::getData() {
	return data;
}

void City::setCityName(string name) {
	cityName = name;
}

void City::setDistrictName(string name){
	districtName = name;
}
void City::setData(int i,string mydata) {

	if(mydata == "-" )
		data[i] = 0;
	else
		data[i] = stoi(mydata);
}