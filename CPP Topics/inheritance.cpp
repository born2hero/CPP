/*
Inheritance
*/

#include <iostream>

class Animal
{
public:
	void sound()
	{
		std::cout << "Animal Sound\n";
	}
};

class Dog : public Animal
{
public:
	void sound()
	{
		std::cout << "Dog Barks\n";
	}
};

class Lion : public Animal
{
public:
	void sound()
	{
		std::cout << "Lion Roars\n";
	}
};

int main()
{
	Animal A;
	A.sound();
	Dog D;
	D.sound();
	Lion L;
	L.sound();

	return 0;
}