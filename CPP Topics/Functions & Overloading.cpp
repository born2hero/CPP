#include <iostream>

class FunctionAndOverloading
{
public:
    /*
    Function Overloading is a feature in C++ that allows you to have multiple functions with the same name but different parameters. The compiler determines which function to call based on the number and types of arguments passed to the function.
    Function overloading can be achieved by changing the number of parameters, the types of parameters, or both. It allows you to create functions that perform similar tasks but with different input types or numbers of inputs, improving code readability and usability.
    Function Overloading is a compile-time polymorphism feature, meaning that the decision of which function to call is made at compile time based on the function signature (the number and types of parameters). This allows for more flexible and intuitive code, as you can use the same function name for different operations without needing to create separate function names for each variation.
    Function overloading does not depend on the return type of the function. The compiler only considers the function name and the parameter list when determining which function to call. Therefore, you cannot overload functions based solely on their return type.
    */
    int add(int a, int b);
    int add(double a, double b);

    double multiply(double a, double b);
    double multiply(int a, int b);

    // double area(double radius);
    double area(double length, double width);
    double area(double side);

    // int area(double side);

    void print();
    void print(int a);

    /*
    Default arguments are values that are automatically assigned to function parameters if no argument is provided for those parameters when the function is called. They allow you to call a function without providing all the arguments, and the default values will be used for any missing arguments.
    Default arguments are specified in the function declaration or definition by assigning a value to the parameter.
    */
    int sum(int a = 1, int b = 0);
    // int sum(int a, int b, int c);

    /*
    inline functions are functions that are expanded in line when they are called. This means that the function's code is inserted at the point of the function call, rather than being called as a separate function. This can improve performance by eliminating the overhead of a function call, but it can also increase the size of the compiled code if the function is large or called frequently.
    To declare a function as inline, you can use the inline keyword before the function definition.
    */
    inline int areaOfSquare(int side)
    {
        return side * side;
    }

    /*
    pass by value and pass by reference are two different ways of passing arguments to a function in C++.
    Pass by value means that a copy of the argument is passed to the function. Any changes made to the parameter inside the function do not affect the original argument outside the function.
    Pass by reference means that a reference to the argument is passed to the function. Any changes made to the parameter inside the function will affect the original argument outside the function, as both the parameter and the argument refer to the same memory location.
    To pass by reference, you can use the reference operator (&) in the function parameter declaration.
    */
    void passByValue(int a)
    {
        a = 10; // This change will not affect the original argument
    }

    void passByReference(int &a)
    {
        a = 10; // This change will affect the original argument
    }
};

int FunctionAndOverloading::add(int a, int b)
{
    return a + b;
}

int FunctionAndOverloading::add(double a, double b)
{
    return a + b;
}

double FunctionAndOverloading::multiply(double a, double b)
{
    return a * b;
}

double FunctionAndOverloading::multiply(int a, int b)
{
    return a * b;
}

double FunctionAndOverloading::area(double length, double width)
{
    return length * width;
}

double FunctionAndOverloading::area(double side)
{
    return side * side;
}

int FunctionAndOverloading::sum(int a, int b)
{
    return a + b;
}

// int FunctionAndOverloading::sum(int a = 0, int b, int c)
// {
//     return a + b + c;
// }

void FunctionAndOverloading::print()
{
    std::cout << "This is a print function with no parameters." << std::endl;
}

void FunctionAndOverloading::print(int a)
{
    std::cout << "This is a print function with an integer parameter: " << a << std::endl;
}

int main()
{
    FunctionAndOverloading objFunc;
    std::cout << "Addition of 5 and 10: " << objFunc.add(5, 10) << std::endl;
    std::cout << "Addition of 5.5 and 10.5: " << objFunc.add(5.5, 10.5) << std::endl;
    std::cout << "Multiplication of 5 and 10: " << objFunc.multiply(5, 10) << std::endl;
    std::cout << "Multiplication of 5.5 and 10.5: " << objFunc.multiply(5.5, 10.5) << std::endl;
    std::cout << "Area of rectangle with length 5 and width 10: " << objFunc.area(5, 10) << std::endl;
    std::cout << "Area of square with side 5: " << objFunc.area(5) << std::endl;
    // std::cout << "Sum of 5 and 10: " << objFunc.sum(5, 10) << std::endl;
    // std::cout << "Sum of 5 and default value (1): " << objFunc.sum(5) << std::endl;
    // std::cout << "Sum of 5, 10, and 15: " << objFunc.sum(5, 10, 15) << std::endl;

    std::cout << "Area of square with side 5 (using inline function): " << objFunc.areaOfSquare(5) << std::endl;

    int value = 5;
    std::cout << "Value before pass by value: " << value << std::endl;
    objFunc.passByValue(value);
    std::cout << "Value after pass by value: " << value << std::endl;

    int value2 = 5;
    std::cout << "Value before pass by reference: " << value2 << std::endl;
    objFunc.passByReference(value2);
    std::cout << "Value after pass by reference: " << value2 << std::endl;

    std::cout << "Calling print function with no parameters:" << std::endl;
    objFunc.print();
    std::cout << "Calling print function with an integer parameter (10):" << std::endl;
    objFunc.print(10);

    return 0;
}