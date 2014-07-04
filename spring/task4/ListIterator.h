// ���������, ����������� ���� ����:
struct Node
{
	int data; // ������� ������
	Node *next, *prev; // ��������� �� ��������� � ���������� ����
};
class ListIterator
{
public:
	Node *token;
	ListIterator():token(0){}
	ListIterator(Node *pn):token(pn){}
	//����������� �������� ���������������
	int operator*(){return token->data;}
	//����������� �������� ���������� (����� �� ������ �����)
	ListIterator operator++(int)
	{
		ListIterator tmp = *this;
		token = token->next;
		return tmp;
	}
	//����������� �������� ���������� (����� �� ������ ����)
	ListIterator operator--(int)
	{
		ListIterator tmp = *this;
		token = token->prev;
		return tmp;
	}
};