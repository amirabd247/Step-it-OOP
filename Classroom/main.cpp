#include <iostream>
#include <string>
using namespace std;
//struct fraction
//{
//    float enumerator;
//
//    bool operator ==(fraction element) const
//    {
//        return this->enumerator == element.enumerator;
//    }
//
//    bool operator !=(fraction element) const
//    {
//        return this->enumerator != element.enumerator;
//    }
//
//    bool operator > (fraction element) const
//    {
//        return this->enumerator > element.enumerator;
//    }
//
//    bool operator < (fraction element) const
//    {
//        return this->enumerator < element.enumerator;
//    }
//
//};
//
//
//int main()
//{
//    fraction object1{1.3f};
//    fraction object2{2.54f};
//
//    cout << bool(object1 > object2);
//}

class Student
{

    public:
    string name;
    int grade;
    Student(string name,int grade)
    {
        this->name = name;
        this->grade = grade;
    }

    bool operator ==(Student person) const
    {
        return this->grade == person.grade;
    }

    bool operator !=(Student person) const
    {
        return this->grade != person.grade;
    }

    bool operator > (Student person) const
    {
        return this->grade > person.grade;
    }

    bool operator < (Student person) const
    {
        return this->grade < person.grade;
    }

    friend ostream& operator<< (ostream& stream, Student person)
    {
        stream << "Value: ";
        stream << person.name;
        return stream;
    }
};

class Classroom
{
    public:
    Student** person;
    Classroom(Student** persons)
    {
        this->person = persons;
    }

    friend ostream& operator<< (ostream& stream, Classroom persons)
    {
        stream << "Name: ";
        for (int i = 0; i < 10; ++i)
        {
            stream << persons.person[i] << endl;
        }
        return stream;
    }
};

int main()
{
    Student* Person1 = new Student("Slavik",4);
    Student* Person2 = new Student("Slavyan",3);

    Student** persons = new Student*[]{Person1,Person2};

    Classroom* classroom = new Classroom(persons);
};

