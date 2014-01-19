#define _USE_MATH_DEFINES 
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

// Класс, описывающий точку:
class Point
{

private:
	//дружественные функции ввода и вывода
	//---------------------------------------------------------
	friend istream& operator >> (istream& is, Point& p)
	{
		cout << "Задайте координаты точки ";
		return is >> p.x >> p.y;
	}
	friend ostream& operator << (ostream& os, const Point& p)
	{
		return os << "коордиаты точки: [" <<
			p.x << ", " << p.y << "]\n";
	}
	//----------------------------------------------------------------
public:

	int x, y;
	//конструктор
	Point(int _x=0, int _y=0)
	{ x = _x; y =_y;}
	//конструктор копирования:
	Point(const Point& pt)
	{
		x= pt.x; y = pt.y;
	}
};

// Класс, описывающий окружность наследование от класса Point
class Circle: public Point // Класс Point является базовым для класса Circle
{
	friend istream& operator >> (istream& is, Circle& c)
	{
		cout << "Задайте координаты центра и радиус ";
		return is >> c.x >> c.y >> c.r;
	}
	friend ostream& operator << (ostream& os, const Circle& c)
	{
		return os << "Радиус: " << c.r << ", " <<  Point(c.x, c.y); 
		// Пример использования функции базового класса

	}
	//----------------------------------------------------------------
protected:
	double r; // радиус окружности
public:
	// конструктор:
	Circle (double _x = 0, double _y = 0, double _r = 0): Point (_x, _y)
	{ r = _r;}
	double Area ()
	{return M_PI* r *r;} // площадь круга
};


int main()
{
	//Настройки шрифтов и региональных стандартов: 
	//if(SetConsoleCP(1251)==0)
	//	//проверка правильности установки кодировки символов для ввода
	//{
	//	cerr<<"Fialed to set codepage!"<<endl;
	//	/* если не удалось установить кодовую страницу, вывод сообщения об ошибке */
	//}
	//if(SetConsoleOutputCP(1251)==0)//тоже самое для вывода
	//{
	//	cerr<<"Failed to set OUTPUT page!"<<endl;
	//}
	setlocale(LC_ALL, "Russian");

	Point from, to;
	cin>>from;
	cin>>to;
	Line ln (from, to);
	ln.Output();
	cout<<"Длина отрезка = "<<ln.Lenght()<<endl;
	Circle cr;
	cin>>cr;
	cout<<cr<<"Площадь окружности "<<cr.Area()<<endl;
	_getch();
	return 0;
}