#pragma once

#include <string>
class UserInterface;
const int MAX = 50;

class Food
{
public:
	Food();
	Food(char* n);
	Food(char* n, char* desc);
	Food(char* n, float pr);
	Food(char* n, char* desc, float pr);
	void setdata(char* nm, char* desc, float pr);
	friend class UserInterface;
private:
	char name[MAX];
	char description[MAX];
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
