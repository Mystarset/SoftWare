#include "stdafx.h"
#include "Dig.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>


char ch[200];
int single;
bool pd;
Dig::Dig()
{
	sum = 0;
	memset(shudu, 0, sizeof(shudu));

}


Dig::~Dig()
{
}
void Dig::print()
{
	
	int cnt = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			ch[cnt++] = shudu[i][j] + 48;
			ch[cnt++] = ' ';
		}
		ch[cnt++] = '\n';
	}
	puts(ch);
}
void Dig::check(int x,int y)
{
	if (x == 9 && y > 9)
	{
		single++;
		return;
	}
	if (single > 1)
	{
		pd = false;
		return;
	}
	if (y > 9)
	{
		x = x + 1;
		y = 1;
	}
	if (shudu[x][y] != 0)
	{
		check(x, y + 1);
	}
	else
	{
		int box;
		box = getbox(x, y);
		for (int i = 1; i <= 9; i++)
		{
			if (!c1[x][i] && !r1[y][i] && !b1[box][i])
			{
				c1[x][i] = true;
				r1[y][i] = true;
				b1[box][i] = true;
				check(x, y + 1);
				c1[x][i] = false;
				r1[y][i] = false;
				b1[box][i] = false;
			}
		}
	}
}
void Dig::suiji()
{
	srand(time(NULL));
	int x = 1, y = 1;

	int n;
	for (int i = 1; i <= 9; i++)
	{
		n = 0;
		while (n < 3)
		{
			int dx = rand() % 3;
			int dy = rand() % 3;
			if (shudu[x + dx][y + dy] != 0)
			{
				n++;
				int box;
				box = getbox(x+dx, y+dy);
				c[x+dx][shudu[x+dx][y+dy]] = false;
				r[y+dy][shudu[x+dx][y+dy]] = false;
				b[box][shudu[x+dx][y+dy]] = false;

				shudu[x + dx][y + dy] = 0;
			}
		}
		y = y + 3;
		if (y > 9)
		{
			y = 1; 
			x = x + 3;
		}
	}

	for (int i = 1; i <= 8; i++)
	{
		n = 0;
		x = 1; y = 1;
		while (n < 1)
		{
			int dx = rand() % 9;
			int dy = rand() % 9;
			if (shudu[x + dx][y + dy] != 0)
			{
				n++;
				int box;
				box = getbox(x + dx, y + dy);
				c[x + dx][shudu[x + dx][y + dy]] = false;
				r[y + dy][shudu[x + dx][y + dy]] = false;
				b[box][shudu[x + dx][y + dy]] = false;
				shudu[x + dx][y + dy] = 0;
			}
		}
		single = 0;
		for (int j = 1;j <= 9; j++)
			for (int k = 1; k <= 9; k++)
			{
				c1[j][k] = c[j][k];
				r1[j][k] = r[j][k];
				b1[j][k] = b[j][k];
			}
		pd = true;
		if (i > 3 && pd)
		{
			sum++;
			print();
			if (sum >= total) return;
		}
	}
}
int Dig::getbox(int x, int y)
{
	int box;
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3) box = 1;
	if (x >= 1 && x <= 3 && y >= 4 && y <= 6) box = 2;
	if (x >= 1 && x <= 3 && y >= 7 && y <= 9) box = 3;
	if (x >= 4 && x <= 6 && y >= 1 && y <= 3) box = 4;
	if (x >= 4 && x <= 6 && y >= 4 && y <= 6) box = 5;
	if (x >= 4 && x <= 6 && y >= 7 && y <= 9) box = 6;
	if (x >= 7 && x <= 9 && y >= 1 && y <= 3) box = 7;
	if (x >= 7 && x <= 9 && y >= 4 && y <= 6) box = 8;
	if (x >= 7 && x <= 9 && y >= 7 && y <= 9) box = 9;
	return box;
}
void Dig::get(int n)
{
	total = n;
	while (sum <= total)
	{
		int box;
		memset(c, true, sizeof(c));
		memset(r, true, sizeof(r));
		memset(b, true, sizeof(b));
		for (int x = 1;x <= 9 ;x++)
			for (int y = 1; y <= 9; y++)
			{
				scanf("%d", &shudu[x][y]);
	
			}
		suiji();
	}
}