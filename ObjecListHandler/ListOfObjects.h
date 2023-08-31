#pragma once
#include<vector>

#include "Objects.h"


class ListOfObjects : public Object
{
public:

	ListOfObjects() { listOfNameOfobjects = {}; };
	~ListOfObjects() {};

	void PrintListOfObjects() {
		for (auto i = 0; i < listOfObjects.size(); i++)
		{
			std::cout<<listOfObjects[i].nameOfObject<<' '<<listOfObjects[i].x << ' ' << listOfObjects[i].y << ' ' << listOfObjects[i].typeOfobject << ' ' << listOfObjects[i].now<<'\n';
		}
	}

	void PrintListOfNameOfobjects() {
		for (const auto& str : listOfNameOfobjects) {
			std::cout << str << " ";
		}
	};


	
	std::vector<Object> listOfObjects;

	std::vector<std::string> listOfNameOfobjects = {};
	std::vector<std::string> listOfTypeOfobjects;
	std::vector<double> listOfCoordinateX;
	std::vector<double> listOfCoordinateY;
	std::vector<time_t> listOfDateAndTime;
};


