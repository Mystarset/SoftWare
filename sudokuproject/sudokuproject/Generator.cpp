#include "generator.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sum = 0;
int total = 0;
char ch[200];

void generator::print()
{
	int cnt = 0;
	for (int i = 1; i <= 9; i++)
	{

		for (int j = 1; j <= 9; j++)
		{
			ch[cnt++] = shudu[i][j];
			ch[cnt++] = ' ';
		}
		ch[cnt++] = '\n';

	}
	puts(ch);
}
void generator::get(int x, int y)
{
	if (sum >= total)
	{
		return;
	}
	if (y > 9)
	{
		if (x == 9)
		{
			sum++;
			print();
		}
		y = 1;
		x = x + 1;
	}
	if (x > 9)
	{
		return;
	}
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

	for (int i = 1; i <= 9; i++)
	{
		if (!c[x][i] && !r[y][i] && !b[box][i])
		{
			c[x][i] = true; r[y][i] = true; b[box][i] = true;
			shudu[x][y] = i + 48;
			get(x, y + 1);
			c[x][i] = false; r[y][i] = false; b[box][i] = false;
		}
	}
}

generator::generator(int n)
{
	num = n;
	memset(shudu, 0, sizeof(shudu));
	memset(c, false, sizeof(c));
	memset(r, false, sizeof(r));
	memset(b, false, sizeof(b));
}

void generator::getshudu(int n)
{



	shudu[1][1] = num + 48;
	c[1][num] = true; r[1][num] = true; b[1][num] = true;
	total = n;
	get(1, 2);
}

