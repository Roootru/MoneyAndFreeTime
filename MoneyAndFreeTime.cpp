#include "UserInterface.h"

int main()
{
	UserInterface UI;
	UI.ShowMainMenu();
	char answer = 0;
	while (std::cin.get(answer))
	{
		UI.ShowMainMenu();
		switch (answer)
		{
		case '1':
			UI.ShowFoodSelectionWindow();
			break;
		case '2':
			UI.EnterDescriptionOfFood();
			break;
		case '3':
			std::exit(-1);
			break;
		}
	}
	return 0;
}