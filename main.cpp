#include <iostream>

#define tab "\t"

class Point;
double Sqrt(double x);
double Pow_2(double x);
double distance(Point A, Point B);

// �������� ��������� 
 class Point
{
	double x;   //���� �������
	double y;
	
public:
	// get ������ ������ ���� �����������
	// ����������� �����, ������� �� �������� ������ ��� ������ ���������� 
	// ��� ������������� ������� ����� ���� �������� ������ ����������� ������
	double get_x() const //����� �������� 'x'
	{
		return x;
	}
	double get_y() const //����� �������� 'y'
	{
		return y;
	}
	void set_x(double x)  // �������� �������� 'x'
	{
		this->x = x;
	} 
	void set_y(double y)  // �������� �������� 'y'
	{
		this->y = y;
	}

};
 


//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a; //���������� ���������� 'a' ���� 'int'
	Point A; // �������� �������   // ���������� ���������� 'A' ���� 'Point' //�������� ������� 'A' ��������� 'Point'
	// ������� �������� ����������� ������/��������� //�������� ��������� 'A' ��������� 'Point'

	A.x = 2;
	A.y = 3;
	std::cout << A.x << tab << A.y << std::endl; // . - �������� ������� ������� (Point Operator) ������������ ��� ������� � ����� ������� �� ����� �������

	Point* pA = &A;
	std::cout << pA->x << tab << pA->y << std::endl;  // -> - �������� ���������� ������� (Arrow Operator) ������������ ��� ������� � ����� ������� �� ������  �������  
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
