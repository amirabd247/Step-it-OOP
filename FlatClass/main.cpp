#include <iostream>
#include <string>

using namespace std;

//class overcoat
//{
//public:
// string name;
// int size;
// string color;
// int price;
// overcoat(string name, int size, string color,int price)
// {
// this->name = name;
// this->size = size;
// this->color = color;
// this->price = price;
// }
//
// bool isequal(overcoat w1 , overcoat w2)
// {
// if (w1.name == w2.name && w1.size == w2.size && w1.color == w2.color)
// {
// return true;
// }
// else
// {
// return false;
// }
// }
//
// void assignment(overcoat w1, overcoat w2)
// {
// w1.name = w2.name;
// w1.size = w2.size;
// w1.color = w2.color;
// w1.price = w2.price;
// }
//
// bool operator > (overcoat w1)
// {
// if (this->price > w1.price)
// {
// return true;
// }
// else
// {
// return false;
// }
// }
//};
//
//int main()
//{
//
// overcoat wearing1("Nike", 42, "black", 1000);
// overcoat wearing2("Adidas", 44, "white", 2000);
// overcoat wearing3("Puma", 46, "red", 3000);
//
//};


class Flat
{

    int square;
    int price;
public:
    Flat(int square,int price)
    {
        this->square = square;
        this->price = price;
    }

    bool isequal(Flat apart)
    {
        if (this->square == apart.square)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void assignment(Flat apart)
    {
        this->price = apart.price;
        this->square = apart.square;
    }

    bool operator > (Flat apart)
    {
        if (this->price > apart.price)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

 Flat* apartment1 = new Flat(49, 1000);
 Flat* apartment2 = new Flat(56,9499);

};