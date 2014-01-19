//класс описывающий линию и агрегирующий в себе класc Point 
class Line
{// Элементы данных: координаты начала и конца отрезка:
	Point from, to;
	// функции:
public:
	//конструктор
	Line(Point a, Point b)
	{	
		from = a;
		to = b;
	}
	//конструктор копирования:
	Line(const Line& ln)
	{
		from = ln.from; to = ln.to;
	}
	// функции ввода-вывода:
	void Input()
	{ 	
		cout << "Задайте начальную и конечную точки отрезка (x1 y1 x2 y2) ";
		cin >> from >> to;		
	}
	void Output()
	{
		cout << "Координаты отрезка: ";
		cout << "("<<from.x << ";" << from.y << ")" << " : (" <<to.x<< ";"<<to.y<<")"<< endl;
	}
	// функции доступа:
	Point GetFrom(){return from;}
	Point GetTo() {return to;}
	//возвращает длину отрезка
	double Lenght()
	{
		return sqrt(pow(double(to.y-from.y), 2)+pow(double(to.x-from.x),2));
	}

};