#pragma once

#include "Food.h"
#include <list>

class Basket
{
public:
	void AddPositionToTheBasket(Food* foodOrder, int amout);
	void DeletePositionFromTheBasket(int position);
	int GetCountOfFoodInTheBasket();
	int GetSumOfFoodInTheBasket();
	void DisplayBasketItems();
private:
	std::vector<FoodOrder*> fo;
	int top = 0;
	float sum_b = 0;
	int count_b = 0;
};