#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    string Name;
    uint16_t HomePhone;
    uint16_t JobPhone;
    uint16_t MobilePhone;
    string info;

    Person() = default;
    Person(const string &name, uint16_t hphone, uint16_t jphone ,uint16_t mphone, const string &info)
    {
        this->Name = name;
        this->HomePhone = hphone;
        this->JobPhone = jphone;
        this->MobilePhone = mphone;
        this->info = info;
    }

    friend ostream &operator<<(ostream &out, const Person &contact)
    {
        out << "Contact name: " << contact.Name << endl;
        out << "Contact home phone: " << contact.HomePhone << endl;
        out << "Contact job phone: " << contact.JobPhone << endl;
        out << "Contact mobile phone: " << contact.MobilePhone << endl;
        out << "Contact information: " << contact.info << endl;
        return out;
    }
};

class PhoneBook
{
public:
    Person* people{};
    uint16_t capacity{10};
    uint16_t size{};

    PhoneBook()
    {
        this->people = new Person[capacity];
    }

    Person* CreatePerson()
    {
        Person* contact = new Person();
        cout << "Enter the name of a contact" << endl;
        cin >> contact->Name;

        cout << "Enter the home phone of the contact" << endl;
        cin >> contact->HomePhone;

        cout << "Enter the job phone of the contact" << endl;
        cin >> contact->JobPhone;

        cout << "Enter the mobile phone of the contact" << endl;
        cin >> contact->MobilePhone;

        cout << "Add the Information about the contact" << endl;
        cin >> contact->info;

        return contact;
    }

    void AddContact()
    {
        if (this->size == this->capacity)
        {
            this->capacity *= 2;
        }

        this->people[this->size] = *CreatePerson();
        this->size += 1;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << this->people[i].Name << endl;
        }
    }

    Person* DeleteContact(int index,Person*& arr)
    {
        Person* NewPeople = new Person[this->capacity]{};

        for (int i = 0; i < index; ++i)
        {
            NewPeople[i] = arr[i];
        }
        for (int i = index; i < size - 1; ++i)
        {
            NewPeople[i] = arr[i];
        }

        delete[] arr;

        return NewPeople;
    }

    void Search(string name)
    {
        for (int i = 0; i < size; ++i)
        {
        if(name == this->people[i].Name)
        {
            cout << this->people[i];
            return;
        }
        }
    }

};


int main() {
    PhoneBook phonebook{};
    int i{};
    int choice{};
    string namef{};
    while(true)
    {

        cout << "Enter the choice 1.Add 2.Delete 3.Print 4.Search" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                phonebook.AddContact();
                break;
            case 2:
                cout << "Enter the index" << endl;
                cin >> i;
                phonebook.people = phonebook.DeleteContact(i,phonebook.people);
                break;
            case 3:
                phonebook.print();
                break;
            case 4:
                cout << "Enter the name" << endl;
                cin >> namef;
                phonebook.Search(namef);
        }
    }
}