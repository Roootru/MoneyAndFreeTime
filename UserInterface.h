#pragma once

#include "Basket.h"

class UserInterface
{
public:
	void MainMenu();
	void FoodSelectionMenu();
	void FoodEntryMenu();
	void BasketMenu(Basket basket);

	void DisplayStartOfWindow(char* nameofwindow);
	template <class T>
	void DisplayTitleOfFoodList(T* id, T* nm, T* desc, T* pr);
};
