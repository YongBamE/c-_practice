
#include "CDog.h"
using namespace std;

	Dog :: Dog() {};
	Dog :: Dog(char* name) : Animal(name) {

	};
	//���
	void Dog :: checkout() {
		cout << "�۸� �߰�" << endl;
	}
	void Dog :: checkin() {
		cout << "�۸� ���" << endl;
	}
