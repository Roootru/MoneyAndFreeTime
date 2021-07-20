#include "UserInterface.h"

int main()
{
	UserInterface UI;
	UI.ShowMainMenu();
	char answer = 0;
	while (std::cin.get(answer))
	{
		switch (answer)
		{
		case '1':
			UI.ShowFoodSelectionWindow();
			std::cout << "HI";
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