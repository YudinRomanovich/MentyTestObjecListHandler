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

ListOfObjects sortingListByName(ListOfObjects& listOne) {
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

ListOfObjects sortingListByCoordinates(ListOfObjects& listOne) {
	for (auto i = 0; i < listOne.listOfObjects.size(); ) {
		if (i == listOne.listOfObjects.size() - 1) {
			break;
		}
		/*if (listOne.listOfObjects[i].nameOfObject[0] == listOne.listOfObjects[i + 1].nameOfObject[0]) {*/

		if ((listOne.listOfObjects[i].x + listOne.listOfObjects[i].y) / 2 > (listOne.listOfObjects[i + 1].x + listOne.listOfObjects[i + 1].y) / 2) {
			std::swap(listOne.listOfObjects[i], listOne.listOfObjects[i + 1]);
			i = 0;
		}
		if ((listOne.listOfObjects[i].x + listOne.listOfObjects[i].y) / 2 <= (listOne.listOfObjects[i + 1].x + listOne.listOfObjects[i + 1].y) / 2) {
			i++;
		}
	}
	return listOne;
}

ListOfObjects sortingListByType(ListOfObjects& listOne) {
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

ListOfObjects sortingListByTime(ListOfObjects& listOne) {
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

ListOfObjects sortTheListOfObjects(ListOfObjects& listOne, ListOfObjects& tmpList, std::fstream& fs) {
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
		std::cout << "4. Sorting list by time\n\n";
		std::cout << "5. Return&Save\n";
		std::cin >> choose;
		while (choose < 0 || choose > 5) {
			std::cout << "Error! Enter a number in the range 1-5\n";
			std::cin >> choose;
		}

		switch (choose)
		{
		case 0:
			listOne.PrintListOfObjects(); //����� ������ �������� �� ������
			system("pause");
			system("cls");
		case 1:
			sortingListByName(listOne);//���������� �� �����
			listOne.PrintListOfObjects(); //����� ������ �������� �� ������
			system("pause");
			system("cls");
			break;
		case 2:
			sortingListByCoordinates(listOne);//���������� �� �����������
			listOne.PrintListOfObjects(); //����� ������ �������� �� ������
			system("pause");
			system("cls");
			break;
		case 3:
			sortingListByType(listOne);//���������� �� ����
			listOne.PrintListOfObjects(); //����� ������ �������� �� ������
			system("pause");
			system("cls");
			break;
		case 4:
			sortingListByTime(listOne);//���������� �� �������
			listOne.PrintListOfObjects(); //����� ������ �������� �� ������
			system("pause");
			system("cls");
			break;
		case 5:
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
	
ListOfObjects getTheListOfObjectFromAnotherFile(std::fstream& tmpFile, std::fstream& fs, ListOfObjects& tmpList) {
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

int main() {

	while (true) {
		std::string pathToFile = "objectList.txt";

		std::fstream fs;
		std::fstream tmpFile;

		ListOfObjects listOne;
		ListOfObjects tmpList;

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
			std::cout << "4. Save results in file\n";
			std::cout << "5. Append list of objects from another file\n\n\n";


			std::cout << "6. Quit\n";

			std::cin >> value;
			while (value <= 0 || value > 6) {
				std::cout << "Error! Enter a number in the range 1-6\n";
				std::cin >> value;
			}
			if (value == 1) {
				readListOfObjects(fs);
			}
			if (value == 2) {
				system("cls");
				addObjectToTheList(listOne,fs);
			}
			if (value == 3) {
				system("cls");
				sortTheListOfObjects(listOne,tmpList, fs);
			}
			if (value == 4) {
				saveResultsInFile(listOne, fs);
			}
			if (value == 5){
				getTheListOfObjectFromAnotherFile(tmpFile, fs, tmpList);
			}
			if (value == 6) {
				return 0;
			}

			system("pause");
			system("cls");
			fs.close();

		}

	}
	return 0;
}