#include <iostream>

#define tab "\t"
#define delimeter  "\n--------------------------------------------\n"


//double Sqrt(double x);
//double Pow_2(double x);
//double distance(Point A, Point B);

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

	//Constructors:



/*Point()
{
	x = y = double();
	std::cout << "DefaultConstructor: \t" << this << std::endl;
}

Point(double x)
{
	this->x = x;
	this->y = double();
	std::cout << "SingleArgumentConstuctor: \t" << this << std::endl;
}
*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "Constuctor: \t" << this << std::endl;
	}

	// Deep Copy ��������� �����������

	Point(const Point& other) // other ��� ��� ������������ ��������� ����� ���������� ��� ������
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	~Point()
	{
		std::cout << " Destructor: \t" << this << std::endl;
	}

	//Assignment operator:

	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment: " << this << std::endl;
		return *this;
	}

	Point operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
					
														//Increment/Decrement:

	Point operator++()      //Prefix Increment
	{
			x++;
			y++;
			return *this;
	}
	Point operator++(int)  //Postfix Increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}


														//Methods:

	void print()const
	{
		std::cout << "X = " << x << "\tY = " << y << std::endl;
	}

	double distance(Point& other) 
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
		//this  - A
		//other -  B

	}

};

 Point operator+(const Point& left, const Point& right) 
 {
	 Point result;
	 result.set_x(left.get_x() + right.get_x());
	 result.set_y(left.get_y() + right.get_y());
	 return result;
 }
 
 bool operator==(const Point& left, const Point& right)
 {
	 return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	 //if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		//  return true;
	// else
		//return false;
 }
 std::ostream& operator <<(std::ostream& os, const Point& obj) 
 {
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y() << std::endl;
 }

 
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK
//#define OPERATOR_CHECK
//#define DISTANCE_CHECK
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

#ifdef CONSTRUCTORS_CHECK
	 Point A;   // ��� �������� ����� ������� ���������� Default constructor
	 //A.set_x(2);
	 //A.set_y(3);
	 //std::cout << A.get_x() << tab << A.get_y() << std::endl;
	 A.print();



	 Point B = 5;  // ���������� Single Argument constructor 
	 //B.set_x(5);
	 //B.set_y(6);
	 //std::cout << B.get_x() << tab << B.get_y() << std::endl;
	 B.print();

	 Point C(2, 3);
	 C.print();

	 Point D = C;  // �opyConstructor
	 D.print();


	 Point E;
	 E = D;        // CopyAssignment
	 E.print();


#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	 int a, b, c;
	 a = b = c = 0;
	 std::cout << delimeter;
	 std::cout << a << tab << b << tab << c << std::endl;
	 std::cout << delimeter;


	 Point A, B, C;
	 std::cout << delimeter;
	 A = B = C = Point(4, 4);
	 std::cout << delimeter;
#endif // ASSIGNMENT_CHECK


#ifdef OPERATOR_CHECK
	 Point A(2, 3);
	 A.print();

	 Point B(5, 7);
	 B.print();


	 Point C = A + B;
	 C.print();

	 A += B;
	 A.print();

	 //++A;
	// A.print();

	 B = A++;
	 A.print();
	 B.print();


	 std::cout << (A == B) << std::endl;

	 std::cout << A << std::endl;


	 A(33, 44);
	 A.print();
#endif // OPERATOR_CHECK

#ifdef DISTANCE_CHECK
	 Point A(7, 8);
	 Point B(2, 3);
	 std::cout << "���������� �� ����� A  �� ����� B: " << A.distance(B) << std::endl;
#endif // DISTANCE_CHECK

}









