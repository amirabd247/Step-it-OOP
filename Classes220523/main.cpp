#include <iostream>
#include <string>
using namespace std;

class student
{

private:
    uint16_t birth_date;
    string country;

public:
    int phone_number;
    string city;
    int school_name;
    string school_place;
    int group_number;

    void setAge(int age)
    {
        this->birth_date = age;
    }

    void setCountry(string state)
    {
        this->country = state;
    }

    student(int nmbr,string town,int school,string place,int group)
    {
        this->phone_number = nmbr;
        this->city = town;
        this->school_name = school;
        this->school_place = place;
        this->group_number = group;
    }

    void print()
    {

            cout << "Your birth date: " << this->birth_date << endl;
            cout << "Your education country: " << this->country << endl;
            cout << "Your phone number:" << this->phone_number << endl;
            cout << "Your city: " << this->city << endl;
            cout <<"Your school: "<< this->school_name << endl;
            cout <<"The place of your school: "<< this->school_place << endl;
            cout <<"The number of your class: "<< this->group_number << endl;

    }

};

int main()
{
    string state{};
    uint16_t age{};
    student* person = new student(4443450,"Baku",160,"Azadliq",10);
    string main_country{};

    cout << "Set the country " << endl;
    cin >> state;
    person->setCountry(state);
    cout << "Set the birth date " << endl;
    cin >> age;
    person->setAge(age);
    person->print();
    return 0;
}
