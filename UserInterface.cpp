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
    ifstream file("FOOD.DAT", ios::binary); // создать выходной файл
    if (!file.is_open())
    {
        cout << "FILE IS NOT OPEN!";
        return;
    }

    vector<Food> foodslist;
    Food contFood;

    file.read(reinterpret_cast<char*>(&contFood), sizeof(contFood));
    while (!file.eof()) // Выход по EOF
    {
        foodslist.push_back(contFood);
        file.read(reinterpret_cast<char*>(&contFood), sizeof(contFood));
    }
    file.close();

    int idfood, countfood;
    Basket basket;

    while (true)
    {
        system("cls");
        cout << endl;
        cout << endl;
        cout << "\t\t FOOD SELECTION MENU \n";
        cout << endl;
        cout << setw(20) << "NAME" << setw(20) << "DESCRIPTION" << setw(20) << "PRICE" << endl;// вывести данные
        for (int i = 0; i < foodslist.size(); i++)
        {
            cout << setw(20) << foodslist[i].name << setw(20) << foodslist[i].description << setw(20) << foodslist[i].price << endl;
        }
        cout << endl;
        cout << "-----------------------------------------------------------------\n";
        cout << "\t\t BUCKET: \n";
        cout << "\t\t COUNT OF FOOD: "  << basket.GetCountOfFoodInTheBasket()   << endl;
        cout << "\t\t SUM OF ORDER: "   << basket.GetSumOfFoodInTheBasket()     << endl;
        cout << "-----------------------------------------------------------------\n";

        cout << "\n\t\t PLEASE ENTER A FOOD NUMBER FROM LIST OR TYPE WORD \"322\": ";
        cin >> idfood;
        if (idfood == 322)
            break;
        cout << "\n\t\t PLEASE ENTER A COUNT OF FOOD OR TYPE WORD \"322\": ";
        cin >> countfood;
        if (countfood == 322)
            break;
        basket.AddPositionToTheBasket(&(foodslist[idfood]), countfood);
    }
    cout << "\n\t\t Do you want open a busket menu? Your answer: ";
    char ans = 'X';
    cin >> ans;
    if (ans == 'y')
        BasketMenu(basket);
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

void UserInterface::BasketMenu(Basket basket)
{
    system("cls");
    cout << endl;
    cout << endl;
    cout << "\t\t BASKET MENU \n";
    cout << endl;
    cout << "-----------------------------------------------------------------\n";
    cout << setw(20) << "NAME" << setw(20) << "COUNT" << setw(20) << "SUM" << endl;// вывести данные
    cout << "-----------------------------------------------------------------\n";
    basket.DisplayBasketItems();
    cout << "-----------------------------------------------------------------\n";
    cout << "TOTAL: " << setw(33) << basket.GetCountOfFoodInTheBasket() << setw(20) << basket.GetSumOfFoodInTheBasket() << endl;
    cout << "-----------------------------------------------------------------\n";

    char answer;
    cout << "\t\t Thank you. ";
    system("pause");
}
