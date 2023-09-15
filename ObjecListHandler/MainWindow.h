#pragma once
#include <iostream>
#include <fstream>

#include "ListOfObjects.h"

int MainWindow() {
	while (true) {
		std::string pathToFile = "objectList.txt";

		std::fstream fs;
		std::fstream tmpFile;

		Object Player1;

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
				listOne.readListOfObjects(fs);
			}
			if (value == 2) {
				system("cls");
				listOne.addObjectToTheList(listOne, fs);
			}
			if (value == 3) {
				system("cls");
				listOne.sortTheListOfObjects(listOne, tmpList, fs);
			}
			if (value == 4) {
				listOne.saveResultsInFile(listOne, fs);
			}
			if (value == 5) {
				listOne.getTheListOfObjectFromAnotherFile(tmpFile, fs, tmpList);
			}
			if (value == 6) {
				return 0;
			}
			system("pause");
			system("cls");
			fs.close();
		}
	}
}
