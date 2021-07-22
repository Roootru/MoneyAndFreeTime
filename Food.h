#pragma once

#include "IncludeFiles.h"

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
	char* getname();
	float getprice();
	void DisplayFoodProperties(int count);

	friend class UserInterface;
private:
	char name[MAX];
	char description[MAX];
	float price;
};

class FoodOrder
{
public:
	FoodOrder();
	FoodOrder(Food* fd);
	FoodOrder(Food* fd, int ct);

	void setdata(Food* fd, int ct);
	void DisplayFoodOrderItem(int count);
private:
	Food* food;
	int count;
};
