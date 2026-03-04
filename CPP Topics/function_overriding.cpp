/**
 * @file function_overriding.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-03-04
 *
 * @copyright Copyright (c) 2026
 * runtime polymorphism
 */

#include <iostream>

class Shape
{
private:

public:
    Shape();
    virtual void calculateArea()
    {
        std::cout << "Area of Shape\n";
    }
    virtual ~Shape();
};

Shape::Shape()
{
    std::cout << "Shape Created\n";
}

Shape::~Shape()
{
    std::cout << "Shape Destroyed\n";
}

class Rectangle : public Shape
{
private:
    int length, width;

public:
    Rectangle(int length, int width);
    void calculateArea() override
    {
        std::cout << "Area of Rectangle: " << length * width << std::endl;
    }
    ~Rectangle();
};

Rectangle::Rectangle(int length, int width) : length(length), width(width)
{
    std::cout << "Rectangle Created\n";
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle Destroyed\n";
}

int main()
{
    Shape *shapePtr = new Rectangle(5, 3);
    shapePtr->calculateArea();

    Rectangle *rectPtr = new Rectangle(10, 4);
    rectPtr->calculateArea();

    delete shapePtr;
    delete rectPtr;
    return 0;
}