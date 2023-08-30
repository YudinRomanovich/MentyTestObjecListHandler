#include <iostream>
#include <fstream>
#include <sstream>

#include "Objects.h"
#include "ListOfObjects.h"

std::ostream& operator<<(std::ostream& os,const Object& object) {
	os << object.nameOfObject<< ' ' << object.x << ' ' << object.y << ' ' << object.typeOfobject << ' ' << object.now << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, Object& object) {
	is >> object.nameOfObject >> object.x >> object.y >> object.typeOfobject >> object.now;
	return is;
}

void saveResultsInFile(ListOfObjects& listOne, std::fstream& fs);

void readListOfObjects(std::fstream& fs) {
	do {
		Object temp;
		fs >> temp;
		if (fs.eof()) {
			break;
		}
		std::cout << temp;
	} while (!fs.eof());
}

void addObjectToTheList(ListOfObjects&listOne, std::fstream& fs) {
	Object tempObject;
	std::cout << "Enter name of object\n";
	std::cin >> tempObject.nameOfObject;
	std::cout << "Enter x-coordinate of object\n";
	std::cin >> tempObject.x;
	std::cout << "Enter y-coordinate of object\n";
	std::cin >> tempObject.y;
	std::cout << "Enter type of object\n";
	std::cin >> tempObject.typeOfobject;

	listOne.listOfObjects.push_back(tempObject);

	saveResultsInFile(listOne, fs);
}

void saveResultsInFile(ListOfObjects& listOne, std::fstream& fs) {
	for (auto i = 0; i < listOne.listOfObjects.size(); i++)
	{
		fs << listOne.listOfObjects[i];
	}
}

void getTheListOfObject(std::fstream& fs, ListOfObjects& listOne) {
	while(!fs.eof()){
		Object temp;
		fs >> temp;
		if (fs.eof()) {
			break;
		}
		listOne.listOfObjects.push_back(temp);
	}
}

void sortTheListOfObjects(ListOfObjects& listOne, std::fstream& fs) {
	
	for (auto i = 0; i < listOne.listOfObjects.size(); i++){

	}

}

int main() {



	while (true) {
		std::string pathToFile = "objectList.txt";

		std::fstream fs;

		ListOfObjects listOne;

		

		fs.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::app);

		getTheListOfObject(fs, listOne);


		if (!fs.is_open()) {
			std::cout << "Error! unable to open file\n";
		}
		else {
			int value;
			std::cout << "File is open!\n\n\n";
			std::cout << "1. Read a list of objects from a file\n";
			std::cout << "2. Add object to the list\n";
			std::cout << "3. Group objects with sorting within groups\n";
			std::cout << "4. Save results in file\n\n\n";

			std::cout << "5. Quit\n";




			std::cin >> value;
			while (value <= 0 || value > 5) {
				std::cout << "Error! Enter a number in the range 1-5\n";
				std::cin >> value;
			}

			if (value == 1) {
				readListOfObjects(fs);
			}
			if (value == 2) {
				addObjectToTheList(listOne,fs);
			}
			if (value == 3) {
			}
			if (value == 4) {
				saveResultsInFile(listOne, fs);
			}
			if (value == 5) {
				return 0;
			}

			system("pause");
			system("cls");

			fs.close();

		}

	}
	return 0;
}