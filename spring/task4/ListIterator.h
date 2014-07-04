// структура, описывающая один узел:
struct Node
{
	int data; // элемент данных
	Node *next, *prev; // указатели на следующий и предыдущий узел
};
class ListIterator
{
public:
	Node *token;
	ListIterator():token(0){}
	ListIterator(Node *pn):token(pn){}
	//перегружаем операцию разыменовывания
	int operator*(){return token->data;}
	//перегружаем операцию инкремента (ходим по списку вверх)
	ListIterator operator++(int)
	{
		ListIterator tmp = *this;
		token = token->next;
		return tmp;
	}
	//перегружаем операцию декремента (ходим по списку вниз)
	ListIterator operator--(int)
	{
		ListIterator tmp = *this;
		token = token->prev;
		return tmp;
	}
};