#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
struct Point//структура описывающая точку
{
	int x;
	int y;
};
class Line//базовый класс
{// Элементы данных: координаты начала и конца отрезка:
protected:
	int x1, y1, x2, y2;
	// функции:
public:
	/* благодаря значениям по умолчанию можно объединить два конструктора(по умолчанию и основной) в один: */
	Line(int _x1=0, int _y1=0, int _x2=0, int _y2=0)
	{	
		x1 = _x1; y1 = _y1; x2 = _x2, y2 = _y2;
	}
	//конструктор копирования:
	Line(const Line& ln)
	{
		x1 = ln.x1; y1 = ln.y1; x2 = ln.x2; y2 = ln.y2;
	}
	// функции ввода-вывода:
	void Input()
	{
		cin >> x1 >> y1 >> x2 >> y2;		
	}
	void Output()
	{
		cout << "Координаты отрезка: ";
		cout << "("<<x1 << ";" << y1 << ")" << " : (" <<x2<< ";"<<y2<<")"<< endl;
	}
	// функции доступа:
	int GetX1(){return x1;}
	int GetY1() {return y1;}
	int GetX2() {return x2;}
	int GetY2() {return y2;}
	//проверяет перпендикулярность двух отрехков
	bool isPerpendicular(const Line& ln){
		int condition = (x2-x1)*(ln.x2-ln.x1)+(y2-y1)*(ln.y2-ln.y1); 
		if (condition == 0)
			return true;
		return false;
	}
};
class Circle
{
	Line rad_vect;//аггрегация (первая точка координаты центра, вторая точка на окружности)
public:
	Circle(Line _r_vec = 0)
	{
		rad_vect = _r_vec;
	}
	//конструктор копирования:
	Circle(const Circle& cr)
	{
		rad_vect = cr.rad_vect; 	
	}
	// функции ввода-вывода:
	void Input()
	{ 		
		rad_vect.Input();
	}
	void Output()
	{
		cout << "Центр окружности: ";
		cout << "("<<rad_vect.GetX1()<< ";" << rad_vect.GetY1() << ")" << " , радиус = " <<GetRadius()<< endl;
	}
	double	GetRadius(){return sqrt(pow(double(rad_vect.GetX2() - rad_vect.GetX1()), 2) + pow(double(rad_vect.GetY2() - rad_vect.GetY1()), 2));}//вычисляем длину радиуса
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
	////Настройки шрифтов и региональных стандартов: 
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
	Line ln;
	cout << "Задайте координаты центра окружности и точки на окружности: (x1 y1 x2 y2) ";
	ln.Input();
	Circle cr(ln);//задаем окружность через отрезок от центра до точки на окружности
	cr.Output();
	cout<<"Площадь окружности = "<<cr.Square()<<endl;
	_getch(); 
	return 0;
}
