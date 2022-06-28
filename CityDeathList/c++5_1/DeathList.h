#pragma once
#include<string>
#include"City.h"

using namespace std;
class DeathList
{
private :
	City** city;
	string search;
	int menu = 0;

public:
	DeathList();


	string getSearch();
	void Dataset();
	void SearchCity();
	void PrintList();
	void subtotal();
};

