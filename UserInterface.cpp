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

    ifstream file("FOOD.DAT", ios::binary); // создать выходной файл
    if (!file.is_open())
    {
        cout << "FILE IS NOT OPEN!";
        return;
    }

    int CountOfFood = 0, SumOfOrder = 0;
    Food food; // создать объект person

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD SELECTION MENU \n";
    cout << endl;

    cout << "\t BUCKET: \n";
    cout << "\t COUNT OF FOOD: " << CountOfFood << " \n";
    cout << "\t SUM OF ORDER: " << SumOfOrder << " \n";
    cout << "-----------------------------------------------------------------\n";

    //// считать данные о первом человеке
    file.seekg(0);
    //file.read(reinterpret_cast<char*>(&food), sizeof(food));
    cout << setw(20) << "NAME" << setw(20) << "DESCRIPTION" << setw(20) << "PRICE" << endl;// вывести данные
    while (file.read(reinterpret_cast<char*>(&food), sizeof(food))) // Выход по EOF
    {
        cout << setw(20) << food.name   << setw(20) << food.description << setw(20) << food.price << endl;
        //file.read(reinterpret_cast<char*>(&food), sizeof(food));
    }
    cout << endl;
    cout << "-----------------------------------------------------------------\n";
    cout << endl;
    cout << "\t\t PLEASE ENTER A FOOD NUMBER FROM LIST: ";
    file.close();
}

void UserInterface::EnterDescriptionOfFood()
{
    using namespace std;

    ofstream file("FOOD.DAT", ios::app | ios::binary); // создать входной файл
    if (!file.is_open())
    {
        cout << "FILE IS NOT OPEN!";
        return;
    }
    Food food; // создать объект person
    string name, description;
    float price; // переменные для создания информации о еде
    char ch; // считывает все ли мы заполнили или нет

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD INPUT MENU \n";
    cout << endl;

    do // данные от пользователя - в файл
    {
        cout << "\t\t PLEASE ENTER AN INFORMATION ABOUT FOOD";
        cout << "\n\t\t NAME: ";           cin >> name;
        cout << "\n\t\t DESCRIPTION: ";    cin >> description;
        cout << "\n\t\t PRICE: ";          cin >> price;
        food.setdata(name, description, price);
        // записать их в файл
        file.write(reinterpret_cast<char*>(&food), sizeof(food));
        cout << "Continue typing (y/n)? ";
        cin >> ch;
    } while (ch == 'y'); // выход по 'n'

}
