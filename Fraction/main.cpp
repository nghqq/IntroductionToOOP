#include <iostream>


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
		this->numerator = 1;
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

	//Methods


	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}

	void to_proper() 
	{
		integer += numerator / denominator;
		numerator %= denominator;
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
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;

}

Fraction operator /(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	result.to_proper();
	return result;

	 
}

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
	

	Fraction B(3, 4, 5);

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();


	Fraction F = A + B;
	F.print();

	Fraction G = A - B;
	G.print();
	



}