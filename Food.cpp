#include "Food.h"

Food::Food(std::string n) : name(n), description(""), price(0.0F)
{
}

Food::Food(std::string n, std::string desc) : name(n), description(desc), price(0.0F)
{
}

Food::Food(std::string n, float pr) : name(n), description(""), price(pr)
{
}

Food::Food(std::string n, std::string desc, float pr) : name(n), description(desc), price(pr)
{
}

FoodOrder::FoodOrder(Food* fd) : count(0)
{
}

FoodOrder::FoodOrder(Food* fd, int ct) : count(ct)
{
}
