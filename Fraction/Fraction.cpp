#include"Fraction.h"
int Fraction::get_integer()const
{
	return integer;
}

int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}

void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//Constructor

Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
	//this->integer = 0;
	//this->numerator = 0;
	//this->denominator = 1;
	std::cout << "DefaultContstuctor: \t" << this << std::endl;
}
Fraction::Fraction(double decimal) :integer(decimal), denominator(1e+9), numerator(decimal)
{
	decimal += 1e-10;
	//integer = decimal;
	decimal -= integer;
	//denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
	std::cout << "DoubleContstuctor: \t" << this << std::endl;
}

Fraction::Fraction(int integer) : integer(integer), numerator(0), denominator(1)
{
	//this->integer = integer;
	//this->numerator = 0;
	//this->denominator = 1;
	std::cout << "SingleArgumentContstuctor: \t" << this << std::endl;
}

Fraction::Fraction(int numerator, int denominator) : integer(0), numerator(numerator), denominator(denominator)
{
	//this->integer = 0;
	//this->numerator = numerator;
	//set_denominator(denominator);
}

Fraction::Fraction(int integer, int numerator, int denominator) :integer(integer), numerator(numerator), denominator(denominator)
{
	//this->integer = integer;
	//this->numerator = numerator;
	//set_denominator(denominator);
	std::cout << "Constructor: \t" << this << std::endl;
}
Fraction::Fraction(const Fraction& other) : integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	// DeepCopy
	//this->integer = other.integer;
	//this->numerator = other.numerator;
	//this->denominator = other.denominator;
	std::cout << "CopyConstructor: \t" << this << std::endl;
}
Fraction::Fraction(Fraction&& other) : integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	//Shallow Copy
	//this->integer = other.integer;
	//this->numerator = other.numerator;
	//this->denominator = other.denominator;
	other.integer = 0;
	other.numerator = 0;
	other.denominator = 0;
	std::cout << "MoveConstructor: \t" << this << std::endl;
}

Fraction::~Fraction()
{
	std::cout << "Destructor: \t" << this << std::endl;
}

//Operators

Fraction& Fraction::operator =(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	std::cout << "CopyAssignment: \t\t" << this << std::endl;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}


//Increment/Decrement:

Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}

Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}

//Type-cast operators:
Fraction::operator int()
{
	return to_proper().integer;
}

Fraction::operator double()
{
	return integer + (double)numerator / denominator;
}

//Methods



Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	std::swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{
	if (numerator == 0)return *this;
	int more;
	int less;
	int rest;
	if (numerator > denominator)more = numerator,
		less = denominator;
	else less = numerator,
		more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;

	} while (rest);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}


void Fraction::print()const
{
	if (integer) std::cout << integer;
	if (numerator)
	{
		if (integer)std::cout << "( ";
		std::cout << numerator << "/" << denominator;
		if (integer) std::cout << ")";

	}
	else if (integer == 0) std::cout << 0;
	std::cout << std::endl;
}

Fraction operator *(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());
	result.to_proper();
	return result;*/
	/*Fraction result(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
	//В этом выражении явно вызывается конструктор, и создается временный безымянный объект.
	//Этот временный безымянный объект сразу же возвращается на место вызова функции.
	//Временные безымянные объекты существуют в пределах одного выражения.

}

Fraction operator /(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/

	return left * right.inverted();


}

bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	const int SIZE = 256;
	char sz_buffer[SIZE]{};
	int number[3] = {};
	char delimiters[] = "()/";
	int n = 0;
	for (char* pch = strtok(sz_buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = std::atoi(pch);
	}
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}
	return is;
}


Fraction operator +(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	if (left.get_denominator() * right.get_denominator() == right.get_denominator() * left.get_denominator())
	{
		result.set_denominator(left.get_denominator() * right.get_denominator());

	}
	result.to_proper();
	return result;
}



Fraction operator -(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
	if (left.get_denominator() * right.get_denominator() == right.get_denominator() * left.get_denominator())
	{
		result.set_denominator(left.get_denominator() * right.get_denominator());

	}
	result.to_proper();
	return result;
}
