// Nayely Alvarado
// EE3223 Homework 6
// This program implements an overloaded operator and friend function
//  to add and multiply two complex numbers

#include <iostream>
#include <math.h>

using namespace std;


// Complex Class

class Complex
{
	private:
	double real;
	double img;
	public:
	Complex(double _real, double _img)		// Constructor
	{
		this->real = _real;
		this->img = _img;
	}
	double get_real();
	double get_img();
	double calc_phase();
	friend void print(Complex c);
	Complex operator+ (const Complex& num)
	{
		Complex comp(0.0,0.0);
		comp.real = this->real + num.real;
		comp.img = this->img + num.img;
		return comp;
	}
	Complex operator* (const Complex& num)
	{
		Complex comp(0.0,0.0);
		comp.real = (this->real * num.real) - (num.img * this->img);
		comp.img = (this->img * num.real) + (this->real * num.img);
		return comp;
	}
};

void print(Complex c)
{
	cout << c.real;
	if (c.img > 0)
		cout << "+" << c.img << "i" << endl;
	else if (c.img < 0)
		cout << c.img << "i" << endl;
}

double Complex::get_real()
{
	return(this->real);
}

double Complex::get_img()
{
	return(this->img);
}

double Complex::calc_phase()
{
	double a1 = this->real;
	double b1 = this->img;

	double phase = atan2(b1,a1);
	
	return(phase);
}

int main()
{
	Complex c1(4.0,-5.0);
	Complex c2(2.0,9.0);
	Complex c3(0.0,0.0);
	
	cout << "c1: ";
	print(c1);
	cout << "c2: ";
	print(c2);
	
	cout << "phase c1: " << c1.calc_phase() << endl;
	cout << "phase c2: " << c2.calc_phase() << endl;
	
	c3 = c1 + c2;
	cout << "c1 + c2: ";
	print(c3);
	
	c3 = c1 * c2;
	cout << "c1 * c2: ";
	print(c3);
	
	return(0);
}






