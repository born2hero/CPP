/*
Compile time polymorphism
function overloading
*/

#include <iostream>

class Calculator
{
public:
	int add(int a, int b)
	{
		std::cout << "INT-> ";
		return a + b;
	}
	double add(double a, double b)
	{
		std::cout << "double-> ";
		return a + b;
	}

	float add(float a, float b)
	{
		std::cout << "float-> ";
		return a + b;
	}

	long add(long a, long b, long c)
	{
		std::cout << "long-> ";
		return a + b + c;
	}
};

int main()
{
	Calculator calc;
	std::cout << calc.add(1, 2) << std::endl;
	std::cout << calc.add(1.0, 2.0) << std::endl;
	std::cout << calc.add(1.0f, 2.0f) << std::endl;
	std::cout << calc.add(1L, 2L, 3L) << std::endl;

	return 0;
}