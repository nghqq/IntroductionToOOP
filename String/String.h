#pragma once
#include<iostream>


class String;
String operator +(const String left, const String right);

class String
{
	int size; // размер строки
	char* str; // адрес строки в динамической памяти

public:

	int get_size()const;
	int set_size(int size);
	const char* get_str()const;
	char* get_str();

	//Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//						Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);

	char operator[](int i)const;
	char& operator[](int i);


	//Methods:

	void print()const;
};
