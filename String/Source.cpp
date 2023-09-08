#include"String.h"
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




