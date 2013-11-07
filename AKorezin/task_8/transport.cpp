#include "transport.h"

Transport::Transport()
{
}

void Transport::setPostion(int pos)
{
position=pos;
}

int Transport::getPosition(void)
{
	return position;
}

void Transport::setMax(int max1)
{
	max=max1;
}
int Transport::getMax(void)
{
	return max;
}
