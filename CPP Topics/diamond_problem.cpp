/*
Diamond Problem
*/

#include <iostream>

class Base
{
public:
    void fun()
    {
        std::cout << "Function Called Base\n";
    }
};

// class Derived1 : public Base{};
class Derived1 : public virtual Base
{
};

// class Derived2 : public Base{};
class Derived2 : public virtual Base
{
};

class Child : public Derived1, public Derived2
{
};

int main()
{
    Child C;
    C.fun();

    return 0;
}