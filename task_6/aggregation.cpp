#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
struct Point//��������� ����������� �����
{
	int x;
	int y;
};
class Line//������� �����
{// �������� ������: ���������� ������ � ����� �������:
protected:
	int x1, y1, x2, y2;
	// �������:
public:
	/* ��������� ��������� �� ��������� ����� ���������� ��� ������������(�� ��������� � ��������) � ����: */
	Line(int _x1=0, int _y1=0, int _x2=0, int _y2=0)
	{	
		x1 = _x1; y1 = _y1; x2 = _x2, y2 = _y2;
	}
	//����������� �����������:
	Line(const Line& ln)
	{
		x1 = ln.x1; y1 = ln.y1; x2 = ln.x2; y2 = ln.y2;
	}
	// ������� �����-������:
	void Input()
	{
		cin >> x1 >> y1 >> x2 >> y2;		
	}
	void Output()
	{
		cout << "���������� �������: ";
		cout << "("<<x1 << ";" << y1 << ")" << " : (" <<x2<< ";"<<y2<<")"<< endl;
	}
	// ������� �������:
	int GetX1(){return x1;}
	int GetY1() {return y1;}
	int GetX2() {return x2;}
	int GetY2() {return y2;}
	//��������� ������������������ ���� ��������
	bool isPerpendicular(const Line& ln){
		int condition = (x2-x1)*(ln.x2-ln.x1)+(y2-y1)*(ln.y2-ln.y1); 
		if (condition == 0)
			return true;
		return false;
	}
};
class Circle
{
	Line rad_vect;//���������� (������ ����� ���������� ������, ������ ����� �� ����������)
public:
	Circle(Line _r_vec = 0)
	{
		rad_vect = _r_vec;
	}
	//����������� �����������:
	Circle(const Circle& cr)
	{
		rad_vect = cr.rad_vect; 	
	}
	// ������� �����-������:
	void Input()
	{ 		
		rad_vect.Input();
	}
	void Output()
	{
		cout << "����� ����������: ";
		cout << "("<<rad_vect.GetX1()<< ";" << rad_vect.GetY1() << ")" << " , ������ = " <<GetRadius()<< endl;
	}
	double	GetRadius(){return sqrt(pow(double(rad_vect.GetX2() - rad_vect.GetX1()), 2) + pow(double(rad_vect.GetY2() - rad_vect.GetY1()), 2));}//��������� ����� �������
	Point	GetCenter()	
	{
		Point center;
		center.x = rad_vect.GetX1();
		center.y = rad_vect.GetY1();
		return center;
	}
	double	Square()
	{
		double radius = GetRadius();
		return M_PI*radius*radius;
	}
	double	Length()
	{
		double radius = GetRadius();	
		return 2*M_PI*radius;
	}
};



int main()
{
	Line ln;
	cout << "������� ���������� ������ ���������� � ����� �� ����������: (x1 y1 x2 y2) ";
	ln.Input();
	Circle cr(ln);//������ ���������� ����� ������� �� ������ �� ����� �� ����������
	cr.Output();
	cout<<"������� ���������� = "<<cr.Square()<<endl;
	_getch(); 
	return 0;
}
