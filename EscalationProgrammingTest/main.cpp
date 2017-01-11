#include <fstream>
#include <iostream>
#include <list>

using namespace std;

struct Entity {
	unsigned short UniqueID;
	unsigned short EntityID;
	float posX;
	float posY;
	float normX;
	float normY;
	char pad[12];
};

class Mob {
public:
	Entity monster;
	void print() {

	}
};

void main() {

	std::fstream file;

	file.open("mapfile.bin", std::ios_base::in | std::ios_base::binary);

	unsigned size;	
	Entity *ents;		
	std::list<Mob*> mobList;
	Entity *ptr = new Entity;

	if (file.is_open()) {		

		file.read((char*)&size, sizeof(unsigned));
		
		ents = new Entity[size];

		while (!file.eof()) {
				ptr = file.read((char*)ents, sizeof(Entity));
				
				cout << ents->UniqueID << " "
					<< ents->EntityID << " "
					<< ents->posX << " "
					<< ents->posY << endl;
		}

	}

	file.close();

	system("pause");
}