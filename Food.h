#pragma once

#include <string>

class Food
{
public:
	Food(std::string n);
	Food(std::string n, std::string desc);
	Food(std::string n, float pr);
	Food(std::string n, std::string desc, float pr);
private:
	std::string name;
	std::string description;
	float price;
};

class FoodOrder
{
public:
	FoodOrder(Food* fd);
	FoodOrder(Food* fd, int ct);
private:
	Food* food;
	int count;
};
