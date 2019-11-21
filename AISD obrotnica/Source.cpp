#include <iostream>
#include "Wagon.h"
#include "Obrotnica.h"
#include "Declaration.h"

using namespace std;


int main()
{
	int t;
	cin >> t;	
	Trail * trails = new Trail[t];
	Obrotnica obr;

	for (int i = 0; i < t; i++)
	{
		int w;
		cin >> w;
		for (int j = 0; j < w; j++)
		{
			int e;
			cin >> e;
			trails[i].push_bottom(e);
		}
	}
	int r, nrt;
	cin >> r;
	nrt = 0;
	for (int i = 0; i < r; i++)
	{
		char z;
		int l;
		cin >> z >> l;
		switch (z)
		{
		case 'z': move_right(t, &nrt, l);	break;
		case 'o': move_left(t, &nrt, l);	break;
		case 'w':			
			for (int i = 0; i < l; i++)
			{
				int tmpid = trails[nrt].getId();
				if (obr.push_front(tmpid))
					trails[nrt].pop();
			}		
			break;
		case 'j':			
			for (int i = 0; i < l; i++)
			{
				int tmpid = trails[nrt].getId();

				trails[nrt].push_front(obr.getId());
				obr.pop();
			}								
			break;
		}
	}

	obr.wypisz();
	for (int i = 0; i < t; i++)
	{
		trails[nrt].wypisz();
		move_right(t, &nrt, 1);
	}
	return 0;
}
