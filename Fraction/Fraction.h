#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction& left, const Fraction& right);
Fraction operator +(Fraction left, Fraction right);
Fraction operator -(Fraction left, Fraction right);


class Fraction
{
	int integer;  // Целая часть
	int numerator; // Числитель
	int denominator; // Знаменатель
public:
	int get_integer()const;

	int get_numerator()const;
	int get_denominator()const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//Constructor

	Fraction();
	Fraction(double decimal);

	explicit Fraction(int integer);

	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	Fraction(Fraction&& other);

	~Fraction();

	//Operators

	Fraction& operator =(const Fraction& other);

	Fraction& operator*=(const Fraction& other);

	Fraction& operator/=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);


	//Increment/Decrement:

	Fraction& operator++();
	Fraction operator++(int);

	Fraction& operator--();

	Fraction operator--(int);

	//Type-cast operators:
	operator int();

	operator double();

	//Methods



	Fraction& to_improper();

	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();


	void print()const;

};
