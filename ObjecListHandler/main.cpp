#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Objects.h"
#include "ListOfObjects.h"


void saveResultsInFile(ListOfObjects& listOne, std::fstream& fs);

std::ostream& operator<<(std::ostream& os,const Object& object) {
	os << object.nameOfObject<< ' ' << object.x << ' ' << object.y << ' ' << object.typeOfobject << ' ' << object.now << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, Object& object) {
	is >> object.nameOfObject >> object.x >> object.y >> object.typeOfobject >> object.now;
	return is;
}

void readListOfObjects(std::fstream& fs) {
	while (!fs.eof()) {
		Object temp;
		fs >> temp;
		if (fs.eof()) {
			break;
		}
		std::cout << temp;
	}
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

ListOfObjects getTheListOfObject(std::fstream& fs, ListOfObjects& listOne) {
	while(!fs.eof()){
		Object temp;
		fs >> temp;
		if (fs.eof()) {
			break;
		}
		listOne.listOfObjects.push_back(temp);
		
	}
	return listOne;
}

void sortTheListOfObjects(ListOfObjects& listOne, ListOfObjects& tmpList, std::fstream& fs) {
	
	getTheListOfObject(fs, listOne);
	//for (auto i = 0; i < listOne.listOfObjects.size(); i++){
	//	/*for (auto j = 0; j < listOne.listOfObjects[j].nameOfObject.size(); j++)
	//	{
	//		
	//	}*/
	//	listOne.listOfNameOfobjects.push_back(listOne.listOfObjects[i].nameOfObject);
	//}
	//std::sort(listOne.listOfNameOfobjects.begin(), listOne.listOfNameOfobjects.end());
	//
	//listOne.PrintListOfNameOfobjects();
	fs.clear();
	//for (auto i = 0; i < listOne.listOfObjects.size(); i++) {
	//	listOne.listOfTypeOfobjects.push_back(listOne.listOfObjects[i].typeOfobject);
	//}
	//std::sort(listOne.listOfTypeOfobjects.begin(), listOne.listOfTypeOfobjects.end());
	//
	//for (auto i = 0; i < listOne.listOfObjects.size(); i++) {
	//	listOne.listOfCoordinateX.push_back(listOne.listOfObjects[i].x);
	//}
	//std::sort(listOne.listOfCoordinateX.begin(), listOne.listOfCoordinateX.end());

	//for (auto i = 0; i < listOne.listOfObjects.size(); i++) {
	//	listOne.listOfCoordinateY.push_back(listOne.listOfObjects[i].y);
	//}
	//std::sort(listOne.listOfCoordinateY.begin(), listOne.listOfCoordinateY.end());

	//for (auto i = 0; i < listOne.listOfObjects.size(); i++) {
	//	listOne.listOfDateAndTime.push_back(listOne.listOfObjects[i].now);
	//}
	//std::sort(listOne.listOfDateAndTime.begin(), listOne.listOfDateAndTime.end());
	listOne.PrintListOfObjects();
	std::cout << "\n\n\n";


	for (auto i = 0; i < listOne.listOfObjects.size();){
		/*if (i == listOne.listOfObjects.size()){
			tmpList.listOfObjects.push_back(listOne.listOfObjects[i]);
			break;
		}
		if (listOne.listOfObjects[i].nameOfObject[0] == listOne.listOfObjects[i + 1].nameOfObject[0]){
			i++;
			continue;
		}
		if (listOne.listOfObjects[i].nameOfObject[0] > listOne.listOfObjects[i + 1].nameOfObject[0]) {
			tmpList.listOfObjects.push_back(listOne.listOfObjects[i+1]);
		}
		else if(listOne.listOfObjects[i].nameOfObject[0] < listOne.listOfObjects[i + 1].nameOfObject[0]) {
			tmpList.listOfObjects.push_back(listOne.listOfObjects[i]);
		}*/
		if (i == listOne.listOfObjects.size() - 1) {
			break;
		}
		if (listOne.listOfObjects[i].nameOfObject[0] > listOne.listOfObjects[i+1].nameOfObject[0]) {
			std::swap(listOne.listOfObjects[i], listOne.listOfObjects[i + 1]);
			i = 0;
		}
		if (listOne.listOfObjects[i].nameOfObject[0] <= listOne.listOfObjects[i + 1].nameOfObject[0]) {
			i++;
		}
	}
	/*listOne.listOfObjects.clear();
	for (auto i = 0; i < listOne.listOfObjects.size(); i++){
		listOne.listOfObjects.push_back(tmpList.listOfObjects[i]);
	}*/

	listOne.PrintListOfObjects();
	fs.close();
	
	std::fstream file("objectList.txt", std::ios::out | std::ios::trunc);
	file.close();
	file.open("objectList.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	saveResultsInFile(listOne, file);
}

int main() {

	while (true) {
		std::string pathToFile = "objectList.txt";

		std::fstream fs;

		ListOfObjects listOne;
		ListOfObjects tmpList;

		listOne.listOfNameOfobjects.reserve(100);

		fs.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::app);

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
				sortTheListOfObjects(listOne,tmpList, fs);
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