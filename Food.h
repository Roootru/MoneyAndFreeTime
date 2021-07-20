#pragma once

#include <string>
class UserInterface;

class Food
{
public:
	Food();
	Food(std::string n);
	Food(std::string n, std::string desc);
	Food(std::string n, float pr);
	Food(std::string n, std::string desc, float pr);
	void setdata(std::string nm, std::string desc, float pr);
	friend class UserInterface;
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
