
#include "CDog.h"
using namespace std;

	Dog :: Dog() {};
	Dog :: Dog(char* name) : Animal(name) {

	};
	//扁瓷
	void Dog :: checkout() {
		cout << "港港 肋啊" << endl;
	}
	void Dog :: checkin() {
		cout << "港港 绢辑客" << endl;
	}
