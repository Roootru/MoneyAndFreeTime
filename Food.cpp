#include "Food.h"

Food::Food()
{
}

Food::Food(char* nm) : price(0.0F)
{
	for (int i = 0; i < MAX; i++)
		name[i] = nm[i];
}

Food::Food(char* nm, char* desc) : price(0.0F)
{
	for (int i = 0; i < MAX; i++)
		name[i] = nm[i];
	for (int i = 0; i < MAX; i++)
		description[i] = desc[i];
}

Food::Food(char* nm, float pr) : description("EMPTY"), price(pr)
{
	for (int i = 0; i < MAX; i++)
		name[i] = nm[i];
}

Food::Food(char* nm, char* desc, float pr) : price(pr)
{
	for (int i = 0; i < MAX; i++)
		name[i] = nm[i];
	for (int i = 0; i < MAX; i++)
		description[i] = desc[i];
}

void Food::setdata(char* nm, char* desc, float pr)
{
	for (int i = 0; i < MAX; i++)
		name[i] = nm[i];
	for (int i = 0; i < MAX; i++)
		description[i] = desc[i];
	price = pr;
}

float Food::getprice()
{
	return price;
}

FoodOrder::FoodOrder()
{
}

FoodOrder::FoodOrder(Food* fd) : count(0)
{
}

FoodOrder::FoodOrder(Food* fd, int ct) : count(ct)
{
}

void FoodOrder::setdata(Food* fd, int ct)
{
	food = fd;
	count = ct;
}
