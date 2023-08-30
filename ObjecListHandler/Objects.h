#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>


class Object {
public:

	Object() { x = y = 0; };
	~Object() {};

	Object(double x, double y, std::string nameOfObject, std::string typeOfobject) {
		this->x = x;
		this->y = y;
		this->nameOfObject = nameOfObject;
		this->typeOfobject = typeOfobject;
		auto now = std::chrono::system_clock::now();
	};
	
	time_t now = time(0);

	double x;
	double y;

	std::string nameOfObject;
	std::string typeOfobject;
};