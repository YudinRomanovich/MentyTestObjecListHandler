#pragma once
#include<vector>
#include <iostream>
#include <iomanip>

#include "Objects.h"


class ListOfObjects : public Object
{
public:

	ListOfObjects() {};
	~ListOfObjects() {};

	void PrintListOfObjects() {
		std::cout << "#Name" << std::setw(12) << std::left << "	 #X"
			<< std::setw(10) << "#Y"
			<< std::setw(10) << "#Type"
			<< std::setw(10) << "#Date"
			<< std::endl;
		std::cout << "--------------------------------------------------\n";
		for (auto i = 0; i < listOfObjects.size(); i++)
		{
			
			std::cout<< std::setw(10)<<listOfObjects[i].nameOfObject<< std::setw(10)<<listOfObjects[i].x << std::setw(10) << listOfObjects[i].y << std::setw(10) << listOfObjects[i].typeOfobject << std::setw(10) << listOfObjects[i].now<<'\n';
		}
	}
	std::vector<Object> listOfObjects;
};