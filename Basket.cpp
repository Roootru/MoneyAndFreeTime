#include "Basket.h"

void Basket::AddPositionToTheBasket(Food* food, int count)
{
	fo.push_back(new FoodOrder(food, count));
}

void Basket::DeletePositionFromTheBasket(int position)
{
	std::list<FoodOrder*>::iterator it;
	std::advance(it, position - 1);
	fo.erase(it);
}
