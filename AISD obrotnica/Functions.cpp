#include "Declaration.h"
void move_right(int t, int *nrt, int l)
{
	*nrt = (*nrt + l) % t;
	//int x = *nrt + l;
	//if (x > t)
	//	*nrt = x - t;
	//else
	//	*nrt = x;
}

void move_left(int t, int *nrt, int l)
{
	int x = (*nrt - l)%t;
	if (x < 0)
		*nrt = t + x;
	else
		*nrt = x;
}