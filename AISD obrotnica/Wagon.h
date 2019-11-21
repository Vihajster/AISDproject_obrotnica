#pragma once
#include <iostream>
using namespace std;

class Trail {
protected:
	struct Wagon {
		int id;
		Wagon *next;
	};
	Wagon *head;
	Wagon *tail;
public:
	Trail()
	{
		head = nullptr;
		tail = nullptr;
	}
	void push_front(int sth)
	{
		if (sth != 0)
		{
			Wagon *x = new Wagon;
			x->id = sth;
			x->next = head;
			if (head == nullptr)
				tail = x;
			head = x;
		}
	}
	void push_bottom(int sth)
	{
		Wagon *x = new Wagon;
		x->id = sth;
		x->next = nullptr;
		if (tail == nullptr)
			head = x;
		else
			tail->next = x;
		tail = x;
	}
	void pop()
	{
		if (head != nullptr)
		{
			Wagon *sth = head->next;
			delete head;
			head = sth;
			tail = sth;
		}
	}
	int getId()
	{
		if (head != nullptr)
			return head->id;
		else 
			return 0;
	}
	void wypisz()
	{
		Wagon *x = head;
		int i = 0;
		while (x != nullptr)
		{
			x = x->next;
			i++;
		}
		cout << i << " ";
		x = head;
		while (x != nullptr)
		{
			cout << x->id << " ";
			x = x->next;
		}
		cout << endl;
	}

};