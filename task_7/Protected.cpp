#include <iostream>

using namespace std;
class X {
public:
   void setProtMemb( int i ) { m_protMemb = i; }
   void Display() { cout << m_protMemb << endl; }
protected:
   int  m_protMemb;
   void Protfunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
   void useProtfunc() 
   { 
	   Protfunc(); 
   }
} y;

int main() 
{
   
   x.setProtMemb( 0 );   
   x.Display();
   y.setProtMemb( 5 );  
   y.Display();
   y.useProtfunc();      
                        
}