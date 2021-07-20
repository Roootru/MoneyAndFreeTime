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
    fstream file; // создать входной/выходной файл
    Food food; // создать объект person

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD SELECTION MENU \n";
    cout << endl;

    file.open("FOOD.DAT", ios::app | ios::out |
        ios::in | ios::binary);

    cout << "\t BUCKET: \n";
    cout << "\t COUNT OF FOOD: " << CountOfFood << " \n";
    cout << "\t SUM OF ORDER: " << SumOfOrder << " \n";
    cout << "-----------------------------------------------------------------";
    // This is place where be food list, need function that get foor list
    file.seekg(0); // поставить указатель на начало файла
    // считать данные о первом человеке
    file.read(reinterpret_cast<char*>(&food), sizeof(food));
    while (!file.eof()) // Выход по EOF
    {
        cout << setw(10) << "NAME" << "DESCRIPTION" << "PRICE";// вывести данные
        cout << setw(10) << food.name << food.description << food.price;
        file.read(reinterpret_cast<char*>(&food), sizeof(food));
    }
    cout << endl;
    cout << "-----------------------------------------------------------------";
    cout << endl;
    cout << "\t\t PLEASE ENTER A FOOD NUMBER FROM LIST: ";
}

void UserInterface::EnterDescriptionOfFood()
{
    using namespace std;

    fstream file; // создать входной/выходной файл
    Food food; // создать объект person
    string name, description;
    float price; // переменные для создания информации о еде
    char ch; // считывает все ли мы заполнили или нет

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD INPUT MENU \n";
    cout << endl;

    // открыть для дозаписи
    file.open("FOOD.DAT", ios::app | ios::out |
        ios::in | ios::binary);
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
