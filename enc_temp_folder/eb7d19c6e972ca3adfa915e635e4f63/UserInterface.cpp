#include "UserInterface.h"
using namespace std;

UserInterface::UserInterface()
{
    file.open("FOOD.DAT", std::fstream::in | std::fstream::out | std::fstream::binary);
    if (!file.is_open())
    {
        cout << "FILE IS NOT OPEN!";
        return;
    }
}

UserInterface::~UserInterface()
{
    file.close();
}

void UserInterface::MainMenu()
{
    system("cls");

    DisplayStartOfWindow((char*)"MAIN MENU");
    cout << "\t\t 1. I NEED A FOOD. \n";
    cout << "\t\t 2. ENTER A DESCRIPTION OF FOOD. \n";
    cout << "\t\t 3. EXIT. \n";
    cout << endl;
    cout << "\t\t YOUR ANSWER: ";
}

void UserInterface::FoodSelectionMenu()
{
    vector<Food> foodlist;
    int input_idfood, input_countfood;
    Basket basket;

    ReadFromFileIntoFoodList(&foodlist);
    while (true)
    {
        DisplayStartOfWindow((char*)"FOOD SELECTION MENU");
        DisplayFoodList(&foodlist);
        DisplayBasketSubMenu(basket);

        cout << "\n\t\t PLEASE ENTER A FOOD NUMBER FROM LIST OR TYPE NUMBER \"0\": ";
        cin >> input_idfood;
        if (input_idfood == 0)
            break;
        cout << "\n\t\t PLEASE ENTER A COUNT OF FOOD OR TYPE NUMBER \"0\": ";
        cin >> input_countfood;
        if (input_countfood == 0)
            break;
        basket.AddPositionToTheBasket(&(foodlist[input_idfood - 1]), input_countfood);
    }

    cout << "\n\t\t Do you want open a busket menu? Your answer (press \"y\" to go to basket menu): ";
    char ans = 'X';
    cin >> ans;
    if (ans == 'y')
        BasketMenu(basket);
}

void UserInterface::FoodEntryMenu()
{
    vector<Food> foodlist;
    char answer, approve = 'y'; // считывает все ли мы заполнили или нет

    do // данные от пользователя - в файл
    {
        ReadFromFileIntoFoodList(&foodlist);
        DisplayStartOfWindow((char*)"FOOD INPUT MENU");
        DisplayFoodList(&foodlist);
        cout << endl;
        cout << "\t\t 1. ADD A FOOD. \n";
        cout << "\t\t 2. DELETE A FOOD. \n";
        cout << "\t\t 3. EXIT. \n";
        cout << endl;
        cout << "\t\t YOUR ANSWER: ";
        cin >> answer;
        switch (answer)
        {
        case '1':
            AddFoodInFile();
            break;
        case '2':
            DeleteFoodFromFile(&foodlist);
            break;
        case '3':
            approve = 'n';
            break;
        }
    } while (approve != 'n'); // выход по 'n'

}

void UserInterface::BasketMenu(Basket basket)
{
    DisplayStartOfWindow((char*)"BASKET MENU");
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "COUNT" << setw(20) << "SUM" << endl;// вывести данные
    cout << "------------------------------------------------------------------------------------------------\n";
    basket.DisplayBasketItems();
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "TOTAL: " << setw(53) << basket.GetCountOfFoodInTheBasket() << setw(20) << basket.GetSumOfFoodInTheBasket() << endl;
    cout << "------------------------------------------------------------------------------------------------\n";

    char answer;
    cout << "\t\t Thank you. ";
    system("pause");
}

void UserInterface::ReadFromFileIntoFoodList(vector<Food>* foodlist)
{
    Food food;
    file.clear();
    file.seekg(0, fstream::beg);
    foodlist->clear();
    while (file.read(reinterpret_cast<char*>(&food), sizeof(food))) // Выход по EOF
    {
        foodlist->push_back(food);
    }
}

// Выводим данные foodlist'а на консоль
void UserInterface::DisplayFoodList(vector<Food>* foodlist)
{
    cout << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "DESCRIPTION" << setw(20) << "PRICE" << endl;
    for (int i = 0; i < foodlist->size(); i++)
    {
        foodlist->at(i).DisplayFoodProperties(i);
    }
    cout << endl;
}

void UserInterface::DisplayStartOfWindow(char* nameofwindow)
{
    system("cls");
    cout << endl;
    cout << endl;
    cout << "\t\t" << nameofwindow << "\n";
    cout << endl;
}

void UserInterface::DisplayBasketSubMenu(Basket& basket)
{
    cout << "-----------------------------------------------------------------\n";
    cout << "\t\t BUCKET: \n";
    cout << "\t\t COUNT OF FOOD: " << basket.GetCountOfFoodInTheBasket() << endl;
    cout << "\t\t SUM OF ORDER: " << basket.GetSumOfFoodInTheBasket() << endl;
    cout << "-----------------------------------------------------------------\n";
}

void UserInterface::AddFoodInFile()
{
    char name[60], description[60];
    float price; // переменные для создания информации о еде
    Food food; // создать объект Food для заполнения в файл

    cout << "\t\t PLEASE ENTER AN INFORMATION ABOUT FOOD";
    cout << endl;
    cout << "\t\t NAME: ";           cin >> name;
    cout << "\t\t DESCRIPTION: ";    cin >> description;
    cout << "\t\t PRICE: ";          cin >> price;
    food.setdata(name, description, price);
    // записать их в файл
    file.clear();
    file.seekg(0, file.end);
    file.write(reinterpret_cast<char*>(&food), sizeof(food));
}

void UserInterface::DeleteFoodFromFile(vector<Food>* foodlist)
{
    int id;
    ReadFromFileIntoFoodList(foodlist);

    cout << "\t\t PLEASE ENTER ID DELETED FOOD";
    cout << endl;
    cout << "\t\t ID: ";            cin >> id;
    // удаляем из foodlist'a и записываем все оставшееся в файл
    foodlist->erase(foodlist->begin() + id - 1);
    file.clear();
    file.seekg(0, file.beg);
    for (auto food : *foodlist)
    {
        file.write(reinterpret_cast<char*>(&food), sizeof(food));
    }
}
