#pragma once
#include<vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <unordered_map>


#include "Objects.h"

std::ostream& operator<<(std::ostream& os, const Object& object);
std::istream& operator>>(std::istream& is, Object& object);

class ListOfObjects : private Object
{
public:

	ListOfObjects() {};
	~ListOfObjects() {};

	std::unordered_map<char, std::vector<std::string>> groupStringsByFirstLetter(ListOfObjects& listOne);

	ListOfObjects getTheListOfObject(std::fstream& fs, ListOfObjects& listOne);
	ListOfObjects sortingListByName(ListOfObjects& listOne);
	ListOfObjects sortingListByCoordinates(ListOfObjects& listOne);
	ListOfObjects sortingListByType(ListOfObjects& listOne);
	ListOfObjects sortingListByTime(ListOfObjects& listOne);
	ListOfObjects sortTheListOfObjects(ListOfObjects& listOne, ListOfObjects& tmpList, std::fstream& fs);
	ListOfObjects getTheListOfObjectFromAnotherFile(std::fstream& tmpFile, std::fstream& fs, ListOfObjects& tmpList);

	void readListOfObjects(std::fstream& fs);
	void addObjectToTheList(ListOfObjects& listOne, std::fstream& fs);
	void saveResultsInFile(ListOfObjects& listOne, std::fstream& fs);
	void PrintListOfObjects();

private:
	std::vector<Object> listOfObjects;
	Object Player;
};

inline void ListOfObjects::readListOfObjects(std::fstream& fs) {
	while (!fs.eof()) {
		Object temp;
		fs >> temp;
		if (fs.eof()) {
			break;
		}
		std::cout << temp;
	}
}

inline void ListOfObjects::addObjectToTheList(ListOfObjects& listOne, std::fstream& fs) {
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

inline void ListOfObjects::saveResultsInFile(ListOfObjects& listOne, std::fstream& fs) {
	for (auto i = 0; i < listOne.listOfObjects.size(); i++)
	{
		fs << listOne.listOfObjects[i];
	}
}


inline void ListOfObjects::PrintListOfObjects() {
	std::cout << "#Name" << std::setw(12) << std::left << "	 #X"
		<< std::setw(10) << "#Y"
		<< std::setw(10) << "#Type"
		<< std::setw(10) << "#Date"
		<< std::endl;
	std::cout << "--------------------------------------------------\n";
	for (auto i = 0; i < listOfObjects.size(); i++)
	{

		std::cout << std::setw(10) << listOfObjects[i].nameOfObject << std::setw(10) << listOfObjects[i].x << std::setw(10) << listOfObjects[i].y << std::setw(10) << listOfObjects[i].typeOfobject << std::setw(10) << listOfObjects[i].now << '\n';
	}
}

inline std::unordered_map<char, std::vector<std::string>> ListOfObjects::groupStringsByFirstLetter(ListOfObjects& listOne)
{
	std::unordered_map<char, std::vector<std::string>> groupedStrings;

	for (auto str = 0; str < listOne.listOfObjects.size(); str++) {
		char firstLetter = listOne.listOfObjects[str].GetTheNameOfObject()[0];
		groupedStrings[firstLetter].push_back(listOne.listOfObjects[str].GetTheNameOfObject());
	}
	for (const auto& pair : groupedStrings) {
		std::cout << "'" << pair.first << "': ";
		for (const std::string& str : pair.second) {
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
	return groupedStrings;
}

inline ListOfObjects ListOfObjects::getTheListOfObject(std::fstream& fs, ListOfObjects& listOne) {
	while (!fs.eof()) {
		Object temp;
		fs >> temp;
		if (fs.eof()) {
			break;
		}
		listOne.listOfObjects.push_back(temp);

	}
	return listOne;
}

inline ListOfObjects ListOfObjects::sortingListByName(ListOfObjects& listOne) {
	for (auto i = 0; i < listOne.listOfObjects.size();) {
		if (i == listOne.listOfObjects.size() - 1) {
			break;
		}
		if (listOne.listOfObjects[i].nameOfObject[0] > listOne.listOfObjects[i + 1].nameOfObject[0]) {
			std::swap(listOne.listOfObjects[i], listOne.listOfObjects[i + 1]);
			i = 0;
		}
		if (listOne.listOfObjects[i].nameOfObject[0] <= listOne.listOfObjects[i + 1].nameOfObject[0]) {
			i++;
		}
	}
	return listOne;
}

inline ListOfObjects ListOfObjects::sortingListByCoordinates(ListOfObjects& listOne) { 
	for (auto i = 0; i < listOne.listOfObjects.size(); ) {

		if (i == listOne.listOfObjects.size() - 1) {
			break;
		}

		double range1 = pow((pow(listOne.listOfObjects[i].x - Player.x, 2) + pow(listOne.listOfObjects[i].y - Player.y, 2)), 0.5);
		double range2 = pow((pow(listOne.listOfObjects[i+1].x - Player.x, 2) + pow(listOne.listOfObjects[i+1].y - Player.y, 2)), 0.5);
		
		if (range1 > range2) {
			std::swap(listOne.listOfObjects[i], listOne.listOfObjects[i + 1]);
			i = 0;
		}
		if (range1 <= range2) {
			i++;
		}
	}
	return listOne;
}

inline ListOfObjects ListOfObjects::sortingListByType(ListOfObjects& listOne) {
	for (auto i = 0; i < listOne.listOfObjects.size(); ) {
		if (i == listOne.listOfObjects.size() - 1) {
			break;
		}
		if (listOne.listOfObjects[i].typeOfobject > listOne.listOfObjects[i + 1].typeOfobject) {
			std::swap(listOne.listOfObjects[i], listOne.listOfObjects[i + 1]);
			i = 0;
		}
		if (listOne.listOfObjects[i].typeOfobject <= listOne.listOfObjects[i + 1].typeOfobject) {
			i++;
		}
	}
	return listOne;
}

inline ListOfObjects ListOfObjects::sortingListByTime(ListOfObjects& listOne) {
	for (auto i = 0; i < listOne.listOfObjects.size(); ) {
		if (i == listOne.listOfObjects.size() - 1) {
			break;
		}
		if (listOne.listOfObjects[i].now > listOne.listOfObjects[i + 1].now) {
			std::swap(listOne.listOfObjects[i], listOne.listOfObjects[i + 1]);
			i = 0;
		}
		if (listOne.listOfObjects[i].now <= listOne.listOfObjects[i + 1].now) {
			i++;
		}
	}
	return listOne;
}

inline ListOfObjects ListOfObjects::sortTheListOfObjects(ListOfObjects& listOne, ListOfObjects& tmpList, std::fstream& fs) {
	int choose;
	while (true) {
		getTheListOfObject(fs, listOne);
		fs.clear();
		std::cout << "\n";
		std::cout << "***How do you want to sort?***\n\n";
		std::cout << "0. Show list of objects\n";
		std::cout << "1. Sorting list by name\n";
		std::cout << "2. Sorting list by range\n";
		std::cout << "3. Sorting list by type\n";
		std::cout << "4. Sorting list by time\n";
		std::cout << "5. Group list by first letter\n\n";

		std::cout << "6. Return&Save\n";
		std::cin >> choose;
		while (choose < 0 || choose > 6) {
			std::cout << "Error! Enter a number in the range 1-6\n";
			std::cin >> choose;
		}

		switch (choose)
		{
		case 0:
			listOne.PrintListOfObjects(); //вывод списка обьектов из списка
			system("pause");
			system("cls");
		case 1:
			sortingListByName(listOne);//сортировка по имени
			listOne.PrintListOfObjects(); //вывод списка обьектов из списка
			system("pause");
			system("cls");
			break;
		case 2:
			sortingListByCoordinates(listOne);//сортировка по координатам
			listOne.PrintListOfObjects(); //вывод списка обьектов из списка
			system("pause");
			system("cls");
			break;
		case 3:
			sortingListByType(listOne);//сортировка по типу
			listOne.PrintListOfObjects(); //вывод списка обьектов из списка
			system("pause");
			system("cls");
			break;
		case 4:
			sortingListByTime(listOne);//сортировка по времени
			listOne.PrintListOfObjects(); //вывод списка обьектов из списка
			system("pause");
			system("cls");
			break;
		case 5:
			listOne.groupStringsByFirstLetter(listOne);
			system("pause");
			system("cls");
			break;
		case 6:
			saveResultsInFile(listOne, fs);
			fs.close();

			std::fstream file("objectList.txt", std::ios::out | std::ios::trunc);
			file.close();
			file.open("objectList.txt", std::fstream::in | std::fstream::out | std::fstream::app);

			saveResultsInFile(listOne, file);

			return listOne;
		}
	}
}

inline ListOfObjects ListOfObjects::getTheListOfObjectFromAnotherFile(std::fstream& tmpFile, std::fstream& fs, ListOfObjects& tmpList) {
	std::string pathToTmpFile;

	std::cout << "Enter file name(Example: tmpFile.txt)\t*file must be in directory with main.cpp file*\n";
	std::cin >> pathToTmpFile;

	tmpFile.open(pathToTmpFile, std::fstream::in | std::fstream::out | std::fstream::app);

	while (!tmpFile.eof()) {
		Object temp;
		tmpFile >> temp;
		tmpList.listOfObjects.push_back(temp);
		if (tmpFile.eof()) {
			break;
		}
	}
	tmpFile.clear();
	std::cout << "This file has this list of elements: \n";
	tmpList.PrintListOfObjects();
	std::cout << "\nDo you want copy this list in main txt file?\n";
	std::cout << "1. Yes\t2. No\n";

	int choose;
	std::cin >> choose;
	switch (choose)
	{
	case 1:
		saveResultsInFile(tmpList, fs);
	case 2:
		return tmpList;
	}

}

std::ostream& operator<<(std::ostream& os, const Object& object) {
	os << object.nameOfObject << ' ' << object.x << ' ' << object.y << ' ' << object.typeOfobject << ' ' << object.now << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, Object& object) {
	is >> object.nameOfObject >> object.x >> object.y >> object.typeOfobject >> object.now;
	return is;
}