#include "UserInterface.h"
using namespace std;

void UserInterface::ShowMainMenu()
{
    system("cls");

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
    system("cls");

    ifstream file("FOOD.DAT", ios::binary); // создать выходной файл
    if (!file.is_open())
    {
        cout << "FILE IS NOT OPEN!";
        return;
    }

    Basket basket;
    vector<Food> foodslist;

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD SELECTION MENU \n";
    cout << endl;

    int countofvector = 0;
    file.read(reinterpret_cast<char*>(&foodslist[countofvector]), sizeof(foodslist[countofvector]));
    cout << setw(20) << "NAME" << setw(20) << "DESCRIPTION" << setw(20) << "PRICE" << endl;// вывести данные
    while (!file.eof()) // Выход по EOF
    {
        countofvector++;
        cout << setw(20) << foodslist[countofvector].name   << setw(20) << foodslist[countofvector].description << setw(20) << foodslist[countofvector].price << endl;
        file.read(reinterpret_cast<char*>(&foodslist[countofvector]), sizeof(foodslist[countofvector]));
    }
    cout << endl;
    cout << "-----------------------------------------------------------------\n";

    char idfood, countfood;

    while (true)
    {
        cout << "\t\t BUCKET: \n";
        cout << "\t\t COUNT OF FOOD: " << basket.GetCountOfFoodInTheBasket() << " \n";
        cout << "\t\t SUM OF ORDER: " << basket.GetSumOfFoodInTheBasket() << " \n";
        cout << "-----------------------------------------------------------------\n";

        cout << "\n\t\t PLEASE ENTER A FOOD NUMBER FROM LIST OR TYPE WORD \"X\": ";
        cin.get(idfood);
        if (idfood == 'X')
            break;
        cout << "\n\t\t PLEASE ENTER A COUNT OF FOOD OR TYPE WORD \"X\": ";
        cin.get(countfood);
        if (idfood == 'X')
            break;
        basket.AddPositionToTheBasket(&(foodslist[idfood]), countfood);
    }

    file.close();
}

void UserInterface::EnterDescriptionOfFood()
{
    system("cls");

    ofstream file("FOOD.DAT", ios::app | ios::binary); // создать входной файл
    if (!file.is_open())
    {
        cout << "FILE IS NOT OPEN!";
        return;
    }
    Food food; // создать объект person
    char name[60], description[60];
    float price; // переменные для создания информации о еде
    char ch; // считывает все ли мы заполнили или нет

    cout << endl;
    cout << endl;
    cout << "\t\t FOOD INPUT MENU \n";
    cout << endl;

    cout << "\t\t PLEASE ENTER AN INFORMATION ABOUT FOOD\n";
    do // данные от пользователя - в файл
    {
        cout << "\t\t NAME: ";           cin >> name;
        cout << "\t\t DESCRIPTION: ";    cin >> description;
        cout << "\t\t PRICE: ";          cin >> price;
        food.setdata(name, description, price);
        // записать их в файл
        file.write(reinterpret_cast<char*>(&food), sizeof(food));
        cout << "\n\t\t Continue typing (y/n)?: ";
        cin >> ch;
        cout << endl;
    } while (ch == 'y'); // выход по 'n'

}
