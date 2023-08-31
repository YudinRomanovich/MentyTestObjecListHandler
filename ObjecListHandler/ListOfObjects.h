#pragma once
#include<vector>

#include "Objects.h"


class ListOfObjects : public Object
{
public:

	ListOfObjects() {};
	~ListOfObjects() {};
	void PrintListOfObjects() {

		for (auto i = 0; i < listOfObjects.size(); i++)
		{
			std::cout<<listOfObjects[i].nameOfObject<<' '<<listOfObjects[i].x << ' ' << listOfObjects[i].y << ' ' << listOfObjects[i].typeOfobject << ' ' << listOfObjects[i].now<<'\n';
		}
	}
	std::vector<Object> listOfObjects;
};


