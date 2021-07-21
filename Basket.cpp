#include "Basket.h"

void Basket::AddPositionToTheBasket(Food* food, int count)
{
	fo.push_back(new FoodOrder(food, count));
	sum_b += food->getprice() * count;
	count_b += count;
}

void Basket::DeletePositionFromTheBasket(int position)
{
	std::list<FoodOrder*>::iterator it;
	std::advance(it, position - 1);
	//fo.erase(it);
}

int Basket::GetCountOfFoodInTheBasket()
{
	return count_b;
}

int Basket::GetSumOfFoodInTheBasket()
{
	return sum_b;
}

void Basket::DisplayBasketItems()
{
	for (int i = 0; i < fo.size(); i++)
	{
		fo[i]->DisplayFoodOrderItem();
	}
}
