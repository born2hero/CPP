/*
Abstraction
*/

#include <iostream>

class Shape
{
protected:
	std::string color;

public:
	Shape(std::string color)
	{
		this->color = color;
	}
	virtual double area() = 0;
	std::string getColor()
	{
		return color;
	}
	virtual ~Shape()
	{
		std::cout << "Destructor Shape Called" << std::endl;
	}
};

class Rectangle : public Shape
{
private:
	double length;
	double width;

public:
	Rectangle(std::string color, double length, double width) : Shape(color)
	{
		this->length = length;
		this->width = width;
	}
	double area() override
	{
		return length * width;
	}
	
	~Rectangle(){
		std::cout << "Destructor Rectangle Called" << std::endl;		
	}
};

int main()
{
	Shape *S = new Rectangle("Yellow", 5, 6);
	std::cout << S->getColor() << std::endl;
	std::cout << S->area() << std::endl;
	Rectangle *R = new Rectangle("Red", 4, 5);
	std::cout << R->getColor() << std::endl;
	std::cout << R->area() << std::endl;

	// Rectangle *T = new Shape("Red", 4, 5);
	// std::cout << T->getColor() << std::endl;
	// std::cout << T->area() << std::endl;

	delete R;
	delete S;

	return 0;
}