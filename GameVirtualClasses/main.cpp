#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    string name;
    string gender;

    virtual void changeName(const string& newName) = 0;

    virtual void printInfo() const = 0;
};

class ClassType {
public:
    int power;
    int stamina;
    int defend;
    int agility;

    virtual void printInfo() const = 0;
};

class Archer : public ClassType {
public:
    void printInfo() const override
    {
        cout << "Archer" << endl;
        cout << "Power- " << power << endl;
        cout << "Stamina- " << stamina << endl;
        cout << "Agility- " << agility << endl;
        cout << "Defend- " << defend << endl;
    }
};

class Mage : public ClassType{
public:
    void printInfo() const override
    {
        cout << "Mage" << endl;
        cout << "Power- " << power << endl;
        cout << "Stamina- " << stamina << endl;
        cout << "Agility- " << agility << endl;
        cout << "Defend- " << defend << endl;
    }
};

class Tank : public ClassType {
public:
    void printInfo() const override
    {
        cout << "Tank" << endl;
        cout << "Power- " << power << endl;
        cout << "Stamina- " << stamina << endl;
        cout << "Agility- " << agility << endl;
        cout << "Defend- " << defend << endl;
    }
};

class Human : public Character {
public:
    Human(ClassType* classType, string& name,string& gender,int power,int agility,int defend,int stamina)
    {
        this->classType = classType;
        this->name = name;
        this->gender = gender;
        this->classType->power = power;
        this->classType->agility = agility;
        this->classType->defend = defend;
        this->classType->defend = stamina;
    }

    void printInfo() const override {
        cout << "Human - " ;
        classType->printInfo();
        cout << "Name - " << this->name << endl << "Gender - " << this->gender << endl;
    }

    void changeName(const string& newName) override
    {
        name = newName;
    }

private:
    ClassType* classType;
};

class Elf : public Character {
public:
    Elf(ClassType* classType, string& name,string& gender,int power,int agility,int defend,int stamina)
    {
        this->classType = classType;
        this->name = name;
        this->gender = gender;
        this->classType->power = power;
        this->classType->agility = agility;
        this->classType->defend = defend;
        this->classType->defend = stamina;
    }

    void printInfo() const override {
        cout << "Elf -";
        classType->printInfo();
        cout << "Name - " << this->name << endl << "Gender - " << this->gender << endl;
    }

    void changeName(const string& newName) override
    {
        name = newName;
    }

private:
    ClassType* classType;
};

class Orc : public Character {
public:
    Orc(ClassType* classType, string& name,string& gender,int power,int agility,int defend,int stamina)
    {
        this->classType = classType;
        this->name = name;
        this->gender = gender;
        this->classType->power = power;
        this->classType->agility = agility;
        this->classType->defend = defend;
        this->classType->defend = stamina;
    }

    void printInfo() const override
    {
        cout << "Orc -";
        classType->printInfo();
        cout << "Name - " << this->name << endl << "Gender - " << this->gender << endl;
    }

    void changeName(const string& newName) override
    {
        name = newName;
    }

private:
    ClassType* classType;
};

int main() {
    ClassType* archer = new Archer();
    ClassType* mage = new Mage();
    ClassType* tank = new Tank();

    string h_name = "John";
    string h_gender = "Male";

    string e_name = "Elar";
    string e_gender = "Female";

    string o_name = "Grogh";
    string o_gender = "Male";

    Character* human = new Human(archer, h_name, h_gender,44,56,33,45);
    Character* elf = new Elf(mage, e_name, e_gender,45,64,34,65);
    Character* orc = new Orc(tank, o_name , o_gender,45,22,45,66);

    human->printInfo();
    elf->printInfo();
    orc->printInfo();

    human->changeName("Michael");
    human->printInfo();

    delete[] archer;
    delete[] mage;
    delete[] tank;
    delete[] human;
    delete[] elf;
    delete[] orc;

    return 0;
}