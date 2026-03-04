/*
Encapsulation
*/

#include <iostream>

class Programmer
{
private:
	std::string name;

public:
	Programmer()
	{
		name = "Unknown";
	}
	std::string getName()
	{
		return name;
	}

	void setName(std::string newName)
	{
		name = newName;
	}
};

int main()
{
	Programmer P;
	std::cout << P.getName() << std::endl;
	P.setName("ABC");
	std::cout << P.getName() << std::endl;

	return 0;
}