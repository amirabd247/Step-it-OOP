#include <iostream>
using namespace std;

class OutOfRange : public exception{
public:
    OutOfRange() = default;
    OutOfRange(string message, int ind) {
        this->message = message;
        this->value = 160 - ind;
    }
    const char* what() const throw() override {
        return this->message.c_str();
    }

    string message = "Object not set to an instance of an object.";
    int value;
};

class MyVector{
private:
    uint16_t capacity;
    uint16_t size{};

public:
    int* vector = new int;

    MyVector(uint16_t capacity,int* vector)
    {
        this->capacity = capacity;
        this->vector = vector;
    }

    void pushback(int value)
    {
        if(this->size == this->capacity)
        {
            if(this->capacity * 2 >= 160)
            {
                throw OutOfRange();
            }
        }
        this->vector[size] = value;
        size++;
    }
};

int main()
{
    int* array = new int[]{};
    MyVector* v = new MyVector(20,array);
}