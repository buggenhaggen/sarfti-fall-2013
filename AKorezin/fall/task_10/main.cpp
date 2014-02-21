#include "wall.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	Wall input;
	if (argc==1)
		cerr<<"No input file"<<endl;
	if (argc>2)
		cerr<<"Bad arguments"<<endl;
	if (argc!=2)
	{

		cerr<<"Usage: twitter [filepath]\n";
		cerr<<"Sample: twitter /home/user/file\n";
		cerr<<"File syntax samples:\n\n#1\n\"";
		cerr<<"1, 2, 3, 4, 5\"\n";
		cerr<<"\n#2\n\"";
		cerr<<"[1,2,3,4,5]\n[1, 2, 3, 4, 5]\"\n\n";
		return 1;
	}

	while(input.fill(argv[1])==1)
	{
		input.startSet();
		input.waterFill();
	}
	if(input.getErr()==1)
		return 1;
	else
		return 0;


}
