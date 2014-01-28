#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
class Triangle
{
protected:
	int x1, y1, x2, y2, x3, y3;//защищенные члены родительского класса
public:
	Triangle(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _x3 = 0, int _y3 = 0)
	{
		x1 = _x1; x2 =_x2; x3 = _x3;
		y1 = _y1; y2 = _y2; y3 = _y3;
	}
	// функции ввода-вывода:
	void Input()
	{ 	
		cout << "Задайте координаты вершин треугольника (x1 y1 x2 y2 x3 y3) ";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;		
	}
	void Output()
	{
		cout << "Координаты вершин треугольника: ";
		cout << "("<<x1 << ";" << y1 << ")" << " : (" <<x2<< ";"<<y2<<")"<<  " : (" <<x3<< ";"<<y3<<")"<<endl;
	}
	//конструктор копирования:
	Triangle(const Triangle& tr)
	{
		x1 = tr.x1; y1 = tr.y1; x2 = tr.x2; y2 = tr.y2; x3 = tr.x3; y3 =tr.y3;
	}
	double LengthAB(){return sqrt(pow(double(x2 - x1), 2) + pow(double(y2 - y1), 2));}
	double LengthBC(){return sqrt(pow(double(x3 - x2), 2) + pow(double(y3 - y2), 2));}
	double LengthCA(){return sqrt(pow(double(x1 - x3), 2) + pow(double(y1 - y3), 2));}
	double Perimetr(){return LengthAB()+LengthBC()+LengthCA();}
	double Square(){return 0.5*abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));}
};

class Piramid:public Triangle//клас описывающий треугольную пирамиду
{
protected:
	double h;
public:
	Piramid(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _x3 = 0, int _y3 = 0, double _h = 0)
	{
		x1 = _x1; x2 =_x2; x3 = _x3;
		y1 = _y1; y2 = _y2; y3 = _y3;
		h = _h;
	}
	//конструктор копирования:
	Piramid(const Piramid& pir)
	{
		x1 = pir.x1; y1 = pir.y1; 
		x2 = pir.x2; y2 = pir.y2;
		x3 = pir.x3; y3 =pir.y3;
		h =	pir.h; 
	}
	// функции ввода-вывода:
	void Input()
	{ 	
		cout << "Задайте координаты вершин треугольника, являющегося основанием пирамиды (x1 y1 x2 y2 x3 y3) ";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		cout<<"Укажите высотy пирамиды: ";
		cin >> h;
	}
	void Output()
	{
		cout << "Координаты верщин основания треугольной пирамиды: ";
		cout << "("<<x1 << ";" << y1 << ")" << " : (" <<x2<< ";"<<y2<<")"<<  " : (" <<x3<< ";"<<y3<<")"<<endl;
		cout << "Высота пирамиды = "<<h<<endl;
	}
	double Volume() {return h*Square()*1/3;}//Square() унаследованная ф-ия считающая площадь основания
	

};
int main ()
{	
	Piramid pir;
	pir.Input();
	pir.Output();
	cout << "Объем пирамиды = "<<pir.Volume()<<endl;
	_getch();
	return 0;
}
