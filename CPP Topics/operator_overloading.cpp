/*
operator oveloading
*/

#include <iostream>

class Complex
{
private:
	int real, imag;

public:
	Complex()
	{
		real = 0;
		imag = 0;
	}

	Complex(int real, int imag) : real(real), imag(imag) {}

	Complex(const Complex &objC)
	{
		real = objC.real;
		imag = objC.imag;
	}
	void print()
	{
		std::cout << real << " + i" << imag << std::endl;
	}

	Complex operator+(const Complex &objC)
	{
		Complex temp;
		temp.real = real + objC.real;
		temp.imag = imag + objC.imag;
		return temp;
	}

	Complex operator-(const Complex &objC)
	{
		Complex temp;
		temp.real = std::abs(real - objC.real);
		temp.imag = std::abs(imag - objC.imag);
		return temp;
	}

	Complex operator*(const Complex &objC)
	{
		Complex temp;
		temp.real = (real * objC.real) + -1 * (imag * objC.imag);
		temp.imag = (real * objC.imag) + (imag * objC.real);
		return temp;
	}

	Complex operator/(const Complex &objC)
	{
		Complex temp;
		int denominator = (objC.real * objC.real) + (objC.imag * objC.imag);
		temp.real = ((real * objC.real) + (imag * objC.imag)) / denominator;
		temp.imag = ((imag * objC.real) - (real * objC.imag)) / denominator;
		return temp;
	}

	~Complex()
	{
		std::cout << "Destructor called\n";
	}
};

int main()
{
	Complex C1(1, 2);
	Complex C2(2, 3);
	Complex C3 = C1 + C2;
	C3.print();
	Complex C4 = C1 - C2;
	C4.print();
	Complex C5 = C1 * C2;
	C5.print();
	Complex C6 = C2 / C1;
	C6.print();

	return 0;
}