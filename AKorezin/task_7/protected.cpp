class A
{
protected:
int x;
friend int getx1(A &);
void setx1(int x1){x=x1;};
public:
int getx(void){return x;};
void setx(int x1){x=x1;};
};
int getx1(A &obj)
{
return obj.x;
}
int main(void)
{
A a;
int b=getx1(a);
return 0;
}
