#include <iostream>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES 
#include <cmath> 
using namespace std;

// Класс, описывающий шар:
class Sphere
{
protected:
	double r; // радиус , для производных от него классов будет радиусом основания
public:
	// Конструктор:
	Sphere(double _r=0)
	{ r = _r;}
	double GetRad() {return r;}
	double Square() //площадь поверхности сферы
	{
		return 4*M_PI*r*r;
	}
};

// Класс, описывающий цилиндр (производный от класса Sphere):
class Cilinder : public Sphere
{
	double h; // высота
public:
	Cilinder(){h=0;}
	// Основной конструктор:
	Cilinder(double _r, double _h):
	Sphere (_r) // Явный вызов конструктора базового класса
	{h = _h;}
	double Volume() {return M_PI*r*r*h;} // объем цилиндра вычисляется с использованием r(радиус основания) protected член родительского класса.
	double GetH() {return h;}
};
// Пример использования классов:
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
	Sphere sph(10); 
	Cilinder cl(15, 10);
	cout<<"Площадь поверхности сферы радиусом "<<sph.GetRad()<< " равна "<<sph.Square()<<endl;
	cout<<"Объем цилиндра с радиусом основания "<<cl.GetRad()<< " и высотой "<<cl.GetH()<<" равен "<<cl.Volume();	
	_getch();
	return 0;
}