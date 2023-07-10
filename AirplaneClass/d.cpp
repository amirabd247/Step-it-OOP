#include <string>
#include <iostream>
using namespace std;

//class Circle{
//
//    int radius;
//    int length;
//
//public:
//    Circle(int radius)
//    {
//        this->radius = radius;
//        this->length = 3 * 2 * radius;
//    }
//
//    bool operator == (Circle& figure) const
//    {
//        return this->length == figure.length;
//    }
//
//    bool operator > (Circle& figure) const
//    {
//        return this->length > figure.length;
//    }
//
//    bool operator < (Circle& figure) const
//    {
//        return this->length < figure.length;
//    }
//
//    void increase(int value)
//    {
//        this->radius += value;
//        this->length = 3 * 2 * radius;
//    }
//
//    void decrease(int value)
//    {
//        this->radius -= value;
//        this->length = 3 * 2 * radius;
//    }
//};
//
//int main()
//{
//
//    Circle* element1 = new Circle(4);
//    Circle* element2 = new Circle(6);
//    bool a{};
//    int b{};
//    int choice{};
//
//    cout << "1.Equality" << endl
//         << "2.Higher" << endl
//         << "3.Lower" << endl
//         << "4.Increase" << endl
//         << "5.Decrease" << endl;
//
//    cin >> choice;
//
//    switch(choice)
//    {
//        case 1:
//            a = element1 == element2;
//            cout << a;
//            break;
//        case 2:
//            a = element1 > element2;
//            cout << a;
//            break;
//        case 3:
//            a = element1 < element2;
//            cout << a;
//            break;
//        case 4:
//            cout << "Enter the Value" << endl;
//            cin >> b;
//            element1->increase(b);
//            break;
//        case 5:
//            cout << "Enter the Value" << endl;
//            cin >> b;
//            element1->decrease(b);
//            break;
//    }
//};



class Airplane
{
    string type;
    int capacity;

public:
    Airplane(string type, int capacity)
    {
        this->type = type;
        this->capacity = capacity;
    }

    bool operator == (Airplane& plane) const
    {
        return this->type == plane.type;
    }

    bool operator > (Airplane& plane) const
    {
        return this->capacity > plane.capacity;
    }

    Airplane operator++(int)
    {
        this->capacity += 1;
        return *this;
    }

    Airplane operator--(int)
    {
        this->capacity -= 1;
        return *this;
    }
};

int main()
{

    Airplane* element1 = new Airplane("Boeing",44);
    Airplane* element2 = new Airplane("Airbus",55);
    bool a{};
    int b{};
    int choice{};

    cout << "1.Equality" << endl
         << "2.Higher" << endl
         << "3.Increase" << endl
         << "4.Decrease" << endl;

    cin >> choice;

    switch(choice)
    {
        case 1:
            a = element1 == element2;
            cout << a;
            break;
        case 2:
            a = element1 > element2;
            cout << a;
            break;
        case 3:
            element1++;
            break;
        case 4:
            element1--;
            break;
    }
};