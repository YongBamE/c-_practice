#include <iostream>
#include "AnimalHotel.h"
#include "Animal.h"
#include "string.h"

class AnimalHotel {
	typedef struct _room {
		char* name = (char*)"x";
		int state = 0;
	}Room;
private:
	Room room[8];
public:
	AnimalHotel() {}


	void checkin(Animal* a, int roomNum) {
		room[roomNum].name = new char(strlen(a->getName() + 1));
		strcpy(room[roomNum].name, a->getName());
	}
	void checkout(Animal a, int roomNum) {
		room[roomNum].name = (char*)'x';
	}

	void roomcheck() {
		cout << "¹æ\tÀÌ¸§" << endl;
		for (int i = 0; i < 8; i++) {
			cout << i << "\t" << room[i].name << endl;
		}

	}

};
