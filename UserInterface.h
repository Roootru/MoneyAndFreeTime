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
	void AddFoodInFile();
	void DeleteFoodFromFile(std::vector<Food>* foodlist);
private:
	std::fstream file;
};
