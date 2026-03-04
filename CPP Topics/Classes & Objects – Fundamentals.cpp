#include <iostream>

class Base
{
private:
    int num1;
    int num2;

public:
    Base() : num1(0), num2(0)
    {
        std::cout << "Base default constructor called." << std::endl;
    }

    ~Base()
    {
        std::cout << "Base class destructor called." << std::endl;
    }

    int getNum1()
    {
        return num1;
    }
    int getNum2()
    {
        return num2;
    }

    void setNum1(int n1)
    {
        num1 = n1;
    }
    void setNum2(int n2)
    {
        num2 = n2;
    }
};

class Derived : public Base
{
};

class Vector2D
{
private:
public:
    double x;
    double y;
    Vector2D() : x(0), y(0)
    {
        std::cout << "Vector2D default constructor called." << std::endl;
    }

    Vector2D(int xVal, int yVal) : x(xVal), y(yVal)
    {
        std::cout << "Vector2D parameterized constructor called." << std::endl;
    }

    Vector2D(const Vector2D &other) : x(other.x), y(other.y)
    {
        std::cout << "Vector2D copy constructor called." << std::endl;
    }

    Vector2D(const Vector2D &&other) : x(other.x), y(other.y)
    {
        std::cout << "Vector2D move constructor called." << std::endl;
    }

    Vector2D &operator=(const Vector2D &other)
    {
        std::cout << "Vector2D assignment operator called." << std::endl;
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Vector2D &operator=(const Vector2D &&other)
    {
        std::cout << "Vector2D move assignment operator called." << std::endl;
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    ~Vector2D()
    {
        std::cout << "Vector2D destructor called." << std::endl;
    }

    Vector2D operator+(const Vector2D &other)
    {
        return Vector2D(x + other.x, y + other.y);
    }
};

int main()
{
    Derived objDerived;
    objDerived.setNum1(10);
    objDerived.setNum2(20);

    std::cout << "Value of num1: " << objDerived.getNum1() << std::endl;
    std::cout << "Value of num2: " << objDerived.getNum2() << std::endl;

    Vector2D v1(1, 2);
    Vector2D v2(3, 4);
    Vector2D v3 = v1 + v2;

    std::cout << "Vector v3: (" << v3.x << ", " << v3.y << ")" << std::endl;

    return 0;
}