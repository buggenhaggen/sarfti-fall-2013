#ifndef QUEUE_H
#define QUEUE_H
 
class queue
{
public:
    void init();//инициализировать
    void put( int m );//положить
    void get();//взять
    int a[501];//очередь
    int start,end;//начало и конец очереди
};
#endif
