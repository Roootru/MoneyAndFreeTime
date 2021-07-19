#include "UserInterface.h"

void UserInterface::ShowMainMenu()
{
	using namespace std;

    cout << endl;
    cout << endl;
    cout << "\t\t MAIN MENU \n";
    cout << endl;
    cout << "\t\t 1. I NEED A FOOD. \n";
    cout << "\t\t 2. ENTER A DESCRIPTION OF FOOD. \n";
    cout << "\t\t 3. EXIT. \n";
    cout << endl;
    cout << "\t\t YOUR ANSWER: ";
}

void UserInterface::ShowFoodSelectionWindow()
{
    using namespace std;
    int CountOfFood = 0, SumOfOrder = 0;

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD SELECTION MENU \n";
    cout << endl;
    cout << "\t BUCKET: \n";
    cout << "\t COUNT OF FOOD: " << CountOfFood << " \n";
    cout << "\t SUM OF ORDER: " << SumOfOrder << " \n";
    cout << "-----------------------------------------------------------------";
    cout << endl;
    cout << "\t\t PLEASE ENTER A FOOD NUMBER FROM LIST: ";
}

void UserInterface::EnterDescriptionOfFood()
{
}
