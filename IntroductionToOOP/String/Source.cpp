#include<iostream>


class String;
String operator +(const String left, const String right);

class String
{
	int size; // размер строки
	char* str; // адрес строки в динамической памяти

public:

	int get_size()const
	{
		return size;
	}
	int set_size(int size)
	{
		this->size = size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//Constructors:
	explicit String(int size = 80):size(size),str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char[size] {};
		std::cout << "DefaultConstruct:" << this << std::endl;
	}
	String(const char* str): String(strlen(str)+1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other):String(other.str)
	{
		//Deep copy
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	String(String&& other):size(other.size),str(other.str)
	{
		//Shallow copy
		//this->size = other.size;
		//this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		std::cout << "MoveConstructor:" << this << std::endl;
	}
	~String()
	{
		delete[] str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//						Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		std::cout << "MoveAssignment:\t" << this << std::endl;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		if (i >= size)throw std::out_of_range("Error:");
		return str[i];
	}


	//Methods:

	void print()const
	{
		std::cout << "Size: \t" << size << std::endl;
		std::cout << "Str: \t" << str << std::endl;
	}

};
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


String operator +( const String left, const String right)
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


//#define CONSTRUCTOR_CHECK
//#define PLUSr_CHECK
#define CHECK
void main()
{
	setlocale(LC_ALL, "");


#ifdef CONSTRUCTOR_CHECK
	String str(5);
	str.print();


	String str_1 = "Hello";
	str_1 = str_1;
	std::cout << str_1 << std::endl;

	String str_2 = str_1;				//CopyConstuctor
	std::cout << str_2 << std::endl;


	String str_3;
	str_3 = str_2;						//CopyAssignment
	std::cout << str_3 << std::endl;
#endif // CONSTRUCTOR_CHECK
#ifdef PLUSr_CHECK

	String str_1 = "Hello";
	String str_2 = "World";
	String str_3 = str_1 + str_2;

	std::cout << str_3 << std::endl;


	//str_1 += str_2;
	//std::cout << str_1 << std::endl;


#endif // PLUS=_CHECK


#ifdef CHECK
	String str_1;   // DefaultConstructor
	str_1.print();

	String str_2(5);  // SingleArgumentConstructor
	str_2.print();

	String str_3 = "Hello"; // SingleArgumentConstructor
	str_3.print();

	String str_4(); // Здесь не создаётся никакой объект, здесь объявляется функция 'str_4()',
	// которая ничего не принимает, и возвращает объект класса 'String';
//str_4().print();

	String str_5{};
	str_5.print();

	String str_6("World");
	str_6.print();
#endif // CHECK

}




