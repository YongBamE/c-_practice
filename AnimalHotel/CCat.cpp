#include "CCat.h"

using namespace std;


	//������
	Cat ::Cat() {};
	Cat ::Cat(char* name) : Animal(name) {};
	//���
	void Cat :: checkout() {
		cout << "�ɳ� �߰�" << endl;
	}
	void Cat :: checkin() {
		cout << "�ɳ� ���" << endl;
	}

