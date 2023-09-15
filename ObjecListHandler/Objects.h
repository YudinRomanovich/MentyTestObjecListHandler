#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

class Object {
public:

	friend std::ostream& operator<<(std::ostream& os, const Object& object);
	friend std::istream& operator>>(std::istream& is, Object& object);
	friend class ListOfObjects;

	Object() { x = y = 0; };
	~Object() {};

	Object(double x, double y, std::string nameOfObject, std::string typeOfobject) {
		this->x = x;
		this->y = y;
		this->nameOfObject = nameOfObject;
		this->typeOfobject = typeOfobject;
		auto now = std::chrono::system_clock::now();
	};

	
private:
	time_t now = time(0);

	double x;
	double y;

	std::string nameOfObject;
	std::string typeOfobject;
};