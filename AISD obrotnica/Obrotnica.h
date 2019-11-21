#pragma once
#include <iostream>
#include "Wagon.h"

using namespace std;

class Obrotnica
	:public Trail {
public:
	int lw;

	Obrotnica()
	{
		head = nullptr;
		tail = nullptr;
		lw = 0;
	}
	bool push_front(int sth)
	{
		if (lw < 10 && sth != 0)
		{
			Wagon *x = new Wagon;
			x->id = sth;
			x->next = head;
			if (head == nullptr)
				tail = x;
			head = x;
			lw++;
			return true;
		}
		else
			return false;
	}
	bool pop()
	{
		if (lw>0)
		{
			Wagon *sth = head->next;
			delete head;
			head = sth;
			tail = sth;
			lw--;
			return true;
		}
		else
			return false;
	}
	
};