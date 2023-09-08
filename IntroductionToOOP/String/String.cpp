#include"String.h"

int String::get_size()const
{
	return size;
}
int String::set_size(int size)
{
	this->size = size;
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//Constructors:
//ключевое слово 'explicit' можно писать только внутри класса
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	std::cout << "DefaultConstruct:" << this << std::endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	std::cout << "Constructor:\t" << this << std::endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	std::cout << "CopyConstructor:" << this << std::endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	std::cout << "MoveConstructor:" << this << std::endl;
}
String::~String()
{
	delete[] str;
	std::cout << "Destructor:\t" << this << std::endl;
}

//						Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	std::cout << "CopyAssignment:\t" << this << std::endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	std::cout << "MoveAssignment:\t" << this << std::endl;
}

char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	if (i >= size)throw std::out_of_range("Error:");
	return str[i];
}


//Methods:

void String::print()const
{
	std::cout << "Size: \t" << size << std::endl;
	std::cout << "Str: \t" << str << std::endl;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


String operator +(const String left, const String right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[left.get_size() - 1 + i] = right[i];
	}
	return cat;
}

