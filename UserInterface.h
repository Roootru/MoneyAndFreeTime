#pragma once

#include "Basket.h"

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void MainMenu();
	void FoodSelectionMenu();
	void FoodEntryMenu();
	void BasketMenu(Basket basket);

	void ReadFromFileIntoFoodList(std::vector<Food>* foodlist);
	void DisplayFoodList(std::vector<Food>* foodlist);
	void DisplayStartOfWindow(char* nameofwindow);
	void DisplayBasketSubMenu(Basket& basket);
private:
	std::fstream file;
	std::vector<Food> foodlist;
};
