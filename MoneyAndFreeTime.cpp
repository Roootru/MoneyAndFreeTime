#include "UserInterface.h"

int main()
{
	UserInterface UI;
	UI.MainMenu();
	char answer = 0;
	while (std::cin.get(answer))
	{
		UI.MainMenu();
		switch (answer)
		{
		case '1':
			UI.FoodSelectionMenu();
			break;
		case '2':
			UI.FoodEntryMenu();
			break;
		case '3':
			std::exit(-1);
			break;
		}
	}
	return 0;
}