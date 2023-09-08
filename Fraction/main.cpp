#include"Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;  // DefaultConstuctor
	A.print();

	Fraction B = 5;   //SingleArgument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef SOMETHINK_CHECK
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
#endif // SOMETHINK_CHECK

#ifdef CONVERSION_FROM_OTHER_TO_CLASS



	Fraction Y = (Fraction)5;
	std::cout << Y << std::endl;

	B = Fraction(8);
#endif // CONVERSION_FROM_OTHER_TO_CLASS
	
#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction Y(52, 10);
	int y = (int)Y;
	std::cout << y << std::endl;

	Fraction Z(2, 3, 4);
	double z = Z;
	std::cout << z << std::endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER


	//Fraction X;
	//std::cout << "Введите простую дробь: "; std::cin >> X;
	//std::cout << X << std::endl;

	//Fraction B(2, 3, 4);
	//std::cout << B << std::endl;
	//Fraction A = 2.75;
	//std::cout << A << std::endl;

	//Fraction A(2, 3, 4);
	//Fraction B(3, 4, 5);
	//std::cout << (Fraction(1, 2) > Fraction(5, 10)) << std::endl;


	//Fraction A(2, 3, 4);
	//Fraction B(3, 4, 5);
	//std::cout << A + B << std::endl;

	Fraction A;   
	A.print();
	

	Fraction B(5);
	B.print();
	
	Fraction C(2.75);
	C.print();

	Fraction F(2, 3, 4);
	F.print();

	Fraction G = F;
	G.print();

	A = F;
	A.print();
	
}