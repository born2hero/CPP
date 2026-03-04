#include <iostream>

int main()
{
    /*
    Fundamental types
    integral type
    floating type
    nullptr type
    */
    int a = 10;
    double b = 3.14;
    bool c = true;
    const int d = 20; // constant variable
    const int &r = d; // reference variable
    int *p = nullptr; // pointer variable
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of b: " << b << std::endl;
    std::cout << "Value of c: " << c << std::endl;
    std::cout << "Value of d: " << d << std::endl;
    std::cout << "Value of r: " << r << std::endl;
    std::cout << "Value of p: " << p << std::endl;
    std::cout << "Type of a: " << typeid(a).name() << std::endl;
    std::cout << "Type of b: " << typeid(b).name() << std::endl;
    std::cout << "Type of c: " << typeid(c).name() << std::endl;
    std::cout << "Type of d: " << typeid(d).name() << std::endl;
    std::cout << "Type of r: " << typeid(r).name() << std::endl;
    std::cout << "Type of p: " << typeid(p).name() << std::endl;

    /*
    Reference variable: A reference variable is an alias for another variable. It is created using the & operator. Once a reference variable is initialized, it cannot be changed to refer to another variable. It must be initialized at the time of declaration.
    Pointer variable: A pointer variable is a variable that stores the memory address of another variable. It is created using the * operator. A pointer variable can be assigned to point to different variables during its lifetime. It can also be assigned a null value (nullptr) to indicate that it does not point to any variable.
    reference vs pointer:
    1. Syntax: Reference variables are declared using the & operator, while pointer variables are declared using the * operator.
    2. Initialization: Reference variables must be initialized at the time of declaration, while pointer variables can
        be initialized later.
    */
    int x = 5;
    int &ref = x;  // reference variable
    int *ptr = &x; // pointer variable
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Value of ref: " << ref << std::endl;
    std::cout << "Value of ptr: " << *ptr << std::endl;

    /*
    Pointer arithmetic: Pointer arithmetic is the process of performing arithmetic operations on pointer variables. The most common operations are addition and subtraction. When you add an integer to a pointer, it moves the pointer to the next memory location of the type it points to. When you subtract an integer from a pointer, it moves the pointer to the previous memory location of the type it points to.
    */
    int arr[5] = {1, 2, 3, 4, 5};
    int *p1 = &arr[2];                                  // points to the first element of the array
    std::cout << "Value of p1: " << *p1 << std::endl;   // prints 1
    std::cout << "Address of p1: " << &p1 << std::endl; // prints the address of the pointer variable
    *p1++;                                              // moves the pointer to the next element of the array
    std::cout << "Value of p1: " << *p1 << std::endl;   // prints 2
    std::cout << "Address of p1: " << &p1 << std::endl; // prints the address of the pointer variable
    *p1 += 2;                                           // moves the pointer two elements ahead
    std::cout << "Value of p1: " << *p1 << std::endl;   // prints 4
    std::cout << "Address of p1: " << &p1 << std::endl; // prints the address of the pointer variable
    *p1--;                                              // moves the pointer to the previous element of the array
    std::cout << "Value of p1: " << *p1 << std::endl;   // prints 3
    std::cout << "Address of p1: " << &p1 << std::endl; // prints the address of the pointer variable

    /*
    nullptr: nullptr is a keyword in C++ that represents a null pointer. It is used to indicate that a pointer does not point to any valid memory location. It is a safer alternative to using NULL or 0 to represent null pointers, as it provides better type safety and prevents accidental conversions to integer types.
    */
    int *p2 = nullptr; // pointer variable initialized to nullptr
    if (p2 == nullptr)
    {
        std::cout << "p2 is a null pointer." << std::endl;
    }

    /*
    const correctness: Const correctness is a programming practice that involves using the const keyword to indicate that a variable or function parameter should not be modified. This helps to prevent accidental changes to data and can improve code readability and maintainability. In C++, you can declare variables, pointers, and references as const to ensure that their values cannot be changed after initialization.
    */
    const int y = 10;     // constant variable
    const int *ptr1 = &y; // pointer to a constant integer
    // int *const ptr2 = &y;     // constant pointer to an integer
    const int *const ptr3 = &y; // constant pointer to a constant integer
    std::cout << "Value of y: " << y << std::endl;
    std::cout << "Value of ptr1: " << *ptr1 << std::endl;
    // std::cout << "Value of ptr2: " << *ptr2 << std::endl;
    std::cout << "Value of ptr3: " << *ptr3 << std::endl;

    /*
    enums(scoped and unscoped): An enum (short for enumeration) is a user-defined data type that consists of a set of named integral constants. In C++, there are two types of enums: scoped enums (enum class) and unscoped enums (enum). Scoped enums provide better type safety and prevent name clashes, while unscoped enums allow implicit conversions to integers and can lead to potential issues with name conflicts.
    */
    enum Color
    {
        Red,
        Green,
        Blue
    }; // unscoped enum
    enum class Shape
    {
        Circle,
        Square,
        Triangle
    }; // scoped enum
    Color color = Red; // valid
    // Shape shape = Circle; // invalid, must use Shape::Circle
    Shape shape = Shape::Circle; // valid
    std::cout << "Value of color: " << color << std::endl;
    std::cout << "Value of shape: " << static_cast<int>(shape) << std::endl;

    return 0;
}