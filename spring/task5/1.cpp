#include "Tree.h"
using namespace std;


// Пример использования класса:
int main()
{
	////Настройки шрифтов и региональных стандартов: 
	//if(SetConsoleCP(1251)==0)
	////проверка правильности установки кодировки символов для ввода
	//{
	//	cerr<<"Fialed to set codepage!"<<endl;
	//}
	//if(SetConsoleOutputCP(1251)==0)//тоже самое для вывода
	//{
	//	cerr<<"Failed to set OUTPUT page!"<<endl;
	//}
	setlocale(LC_ALL, "Russian");
	Tree tree; // Объявляем объект основного дерева
	Tree nechet, chet; //два дерева четное и нечетное 
	int x;
// Открываем файл с данными:
	ifstream file("numbers.txt");
	if (file)
	{
		bool f_first = true;
		cout << "Прочитана последовательность: \n";
		do
		{
			file>>x;
			if (!file.eof())
			{
				cout << x << " ";
				if (f_first)
				{
					tree.Add(x); // добавляем первый элемент как корень дерева
					f_first = false;					
				}
				else
				{
					//отдельно собираем четные и нечетные деревья
					if (x%2)//нечетное
					{
						nechet.Add(x);
					}
					else
						chet.Add(x);
				}
				
			}
		} while (!file.eof());
		cout<<endl;
		//добавляем к корневому элементу дерева левые и правые потдеревья
		tree.rootPtr->lPtr = nechet.rootPtr;
		tree.rootPtr->rPtr = chet.rootPtr;
		cout<<"Вывод дерева (дерево расположено слева направо):"<<endl;
		tree.Out();
	}
	else cout << "Файл не найден\n";
	_getch();
	return 0;
}
