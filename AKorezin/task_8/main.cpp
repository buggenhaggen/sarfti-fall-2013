#include "wall.h"



int main(int argc, char *argv[])
{
	Wall input;
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
