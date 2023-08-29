#include <iostream>

#define tab "\t"

class Point;
double Sqrt(double x);
double Pow_2(double x);
double distance(Point A, Point B);

// Описание структуры 
 class Point
{
	double x;   //Поля объекта
	double y;
	
public:
	// get методы должны быть константами
	// константный метод, который не изменяет объект для корого вызывается 
	// для константоного объекта могут быть вызвааны только константные методы
	double get_x() const //Взять значение 'x'
	{
		return x;
	}
	double get_y() const //Взять значение 'y'
	{
		return y;
	}
	void set_x(double x)  // Получить значение 'x'
	{
		this->x = x;
	} 
	void set_y(double y)  // Получить значение 'y'
	{
		this->y = y;
	}

};
 


//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a; //Объявление переменной 'a' типа 'int'
	Point A; // Создание объекта   // Объявление переменной 'A' типа 'Point' //Создание объекта 'A' структуры 'Point'
	// Объекты называют экземлярами класса/структуры //Создание экземляра 'A' структуры 'Point'

	A.x = 2;
	A.y = 3;
	std::cout << A.x << tab << A.y << std::endl; // . - Оператор прямого доступа (Point Operator) Используется для доступа к полям объекта по имени объекта

	Point* pA = &A;
	std::cout << pA->x << tab << pA->y << std::endl;  // -> - Оператор косвенного доступа (Arrow Operator) Используется для доступа к полям объекта по адресу  объекта  
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	std::cout << A.get_x() << tab << A.get_y() << std::endl;



	Point B;
	B.set_x(5);
	B.set_y(6);
	std::cout << B.get_x() << tab << B.get_y() << std::endl;

	
	std::cout << distance(A,B) << std::endl;
	

}

double Sqrt(double x)
{
	double guess = x / 2;

	while (guess * guess - x > 10e-12)
	{
		guess = (guess + x / guess) / 2;
	}
	return guess;
}

double Pow_2(double x)
{
	double result = x * x;

	return result;
}

double distance(Point A, Point B)
{
	double result;
	result = sqrt(B.get_x() - A.get_y())* (B.get_x() - A.get_y()) + (B.get_y() - A.get_y())* (B.get_y() - A.get_y());
	return result;
}
