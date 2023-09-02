﻿#include <iostream>

class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction& left, const Fraction& right);


class Fraction 
{
	int integer;  // Целая часть
	int numerator; // Числитель
	int denominator; // Знаменатель
public:
	int get_integer()const 
	{
		return integer;
	}

	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	
	void set_integer(int integer) 
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructor

	Fraction() 
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "DefaultContstuctor: \t" << this << std::endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "SingleArgumentContstuctor: \t" << this << std::endl;
	}

	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
	}

	Fraction(int integer, int numerator, int denominator) 
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		std::cout << "Constructor: \t" << this << std::endl;
	}
	Fraction(const Fraction& other) 
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyConstructor: \t" << this << std::endl;
	}
	

	~Fraction() 
	{
		std::cout << "Destructor: \t" << this << std::endl;
	}

	//Operators

	Fraction& operator =(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment: \t\t" << this << std::endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other) 
	{
		return *this = *this * other;
	}
	
	Fraction& operator/=(const Fraction& other) 
	{
		return *this = *this / other;
	}
	

						//Increment/Decrement

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}



	//Methods


	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper() 
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& inverted()const 
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap (inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce() 
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


	void print()const 
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

};

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

Fraction operator /( const Fraction& left, const Fraction& right)
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

/*std::istream& operator>>(std::istream& is, Fraction& obj)
{
	return;
}*/


Fraction operator +(Fraction left, Fraction right) 
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	if (left.get_denominator() * right.get_denominator()== right.get_denominator() * left.get_denominator())
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
	if (left.get_denominator() * right.get_denominator()== right.get_denominator() * left.get_denominator())
	{
	result.set_denominator(left.get_denominator() * right.get_denominator());

	}
	result.to_proper();
	return result;
}


//#define CONSTRUCTORS_CHECK
void main() 
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(2, 3, 4);
	A.print();
	

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();


	Fraction F = A + B;
	F.print();

	Fraction G = A - B;
	G.print();
	

	A *= B;
	A.print();


	A /= B;
	A.print();


	//Fraction X;
	//std::cout << "Введите простую дробь: "; std::cin >> X;
	//std::cout << X << std::endl;
}