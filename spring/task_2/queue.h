#ifndef QUEUE_H
#define QUEUE_H
 
class queue
{
public:
    void init();//����������������
    void put( int m );//�������� � �������
    void get();//����� �� �������
    int a[501];//�������
    int start,end;//������ � ����� �������
};
#endif