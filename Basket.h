#pragma once

#include "Food.h"
#include <list>

class Basket
{
public:
	void AddPositionToTheBasket(Food* foodOrder, int amout);
	void DeletePositionFromTheBasket(int position);
private:
	std::list<FoodOrder*> fo;
	int top = 0;
};