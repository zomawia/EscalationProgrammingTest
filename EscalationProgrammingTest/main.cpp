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

void main() {

	std::fstream file;

	file.open("mapfile.bin", std::ios_base::in | std::ios_base::binary);

	unsigned size;
	Entity *ents;

	if (file.is_open()) {		

		file.read((char*)&size, sizeof(unsigned));
		
		ents = new Entity[size];
		
		while (!file.eof()) {
			for (int i = 0; i < size; ++i) {
				file.read((char*)ents, sizeof(Entity));
				ents[i] = *ents;


				cout << ents->UniqueID << " "
					<< ents->EntityID << " "
					<< ents->posX << " "
					<< ents->posY << endl;
			}
		}

	}

	file.close();
}