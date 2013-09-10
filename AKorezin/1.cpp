#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>
#define N 10
using namespace std;
int main(int argc, char ** argv)
{
stack <int> first, second;
int a,i;
srand(time(NULL));


for(i=0;i<N;i++)
{
first.push(rand()%100);
cout << first.top() << " ";
}
cout << endl;

for(i=0;i<N;i++)
{
a=first.top();
first.pop();
while(first.size()!=i)
{
if(a<first.top())
{
second.push(a);
a=first.top();
first.pop();
}
else
{
second.push(first.top());
first.pop();
}
}
first.push(a);
while(second.size()!=0)
{
first.push(second.top());
second.pop();
}

}

for(i=0;i<N;i++)
{
cout << first.top() << " ";
first.pop();
}
cout << endl;
return 0;
}
