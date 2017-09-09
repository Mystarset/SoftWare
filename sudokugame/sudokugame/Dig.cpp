#include "Dig.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

char ch[200];
int single;
bool pd;


Dig::Dig()
{
	sum = 0;
	memset(shudu, 0, sizeof(shudu));
	res[1][1] = 6; res[1][2] = 1; res[1][3] = 2; res[1][4] = 3; res[1][5] = 4; res[1][6] = 5; res[1][7] = 7; res[1][8] = 8; res[1][9] = 9;
	res[2][1] = 3; res[2][2] = 4; res[2][3] = 5; res[2][4] = 7; res[2][5] = 8; res[2][6] = 9; res[2][7] = 1; res[2][8] = 2; res[2][9] = 6;
	res[3][1] = 7; res[3][2] = 8; res[3][3] = 9; res[3][4] = 1; res[3][5] = 2; res[3][6] = 6; res[3][7] = 3; res[3][8] = 4; res[3][9] = 5;
	res[4][1] = 1; res[4][2] = 2; res[4][3] = 3; res[4][4] = 4; res[4][5] = 5; res[4][6] = 7; res[4][7] = 6; res[4][8] = 9; res[4][9] = 8;
	res[5][1] = 4; res[5][2] = 5; res[5][3] = 6; res[5][4] = 8; res[5][5] = 9; res[5][6] = 1; res[5][7] = 2; res[5][8] = 3; res[5][9] = 7;
	res[6][1] = 8; res[6][2] = 9; res[6][3] = 7; res[6][4] = 2; res[6][5] = 6; res[6][6] = 3; res[6][7] = 4; res[6][8] = 5; res[6][9] = 1;
	res[7][1] = 2; res[7][2] = 3; res[7][3] = 1; res[7][4] = 5; res[7][5] = 7; res[7][6] = 8; res[7][7] = 9; res[7][8] = 6; res[7][9] = 4;
	res[8][1] = 5; res[8][2] = 6; res[8][3] = 4; res[8][4] = 9; res[8][5] = 1; res[8][6] = 2; res[8][7] = 8; res[8][8] = 7; res[8][9] = 3;
	res[9][1] = 9; res[9][2] = 7; res[9][3] = 8; res[9][4] = 6; res[9][5] = 3; res[9][6] = 4; res[9][7] = 5; res[9][8] = 1; res[9][9] = 2;

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
			if (shudu[i][j] == 0 && vis[i][j] == true) ch[cnt++] = res[i][j] + 48;
			else
			{
				ch[cnt++] = shudu[i][j] + 48;
			}
			ch[cnt++] = ' ';
		}
		ch[cnt++] = '\n';
	}
	puts(ch);
}
void Dig::checksingle(int x, int y)
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
		checksingle(x, y + 1);
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
				checksingle(x, y + 1);
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
				box = getbox(x + dx, y + dy);
				c[x + dx][shudu[x + dx][y + dy]] = false;
				r[y + dy][shudu[x + dx][y + dy]] = false;
				b[box][shudu[x + dx][y + dy]] = false;

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

	for (int i = 1; i <= 13; i++)
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
		pd = true;
		for (int j = 1; j <= 9; j++)
			for (int k = 1; k <= 9; k++)
			{
				c1[j][k] = c[j][k];
				r1[j][k] = r[j][k];
				b1[j][k] = b[j][k];
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
bool Dig::checkrule()
{
	int a[10];
	memset(a, 0, sizeof(a));
	int box;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			box = getbox(i, j);
			if (shudu[i][j] == 0 && vis[i][j] == false) a[box]++;
		}
	}
	for (int i = 1; i <= 9; i++)
		if (a[i] < 2) return false;

	return true;
}
void Dig::dfs(int x, int y, int n)
{
	if (sum >= total) return;
	if (n == 7 && checkrule())
	{
		print();
		sum++;
		return;
	}
	if (n == 7) return;
	if (x == 9 && y > 9) return;
	if (y > 9)
	{
		x = x + 1;
		y = 1;
	}
	if (shudu[x][y] != 0) dfs(x, y + 1, n);
	else
	{
		for (int i = 0; i <= 1; i++)
		{
			if (i == 0)
			{
				vis[x][y] = true;
				dfs(x, y + 1, n + 1);
				vis[x][y] = false;

			}
			else
			{
				dfs(x, y + 1, n);
			}
		}
	}
}
void Dig::get(int n)
{
	total = n;

	while (true)
	{
		memset(c, true, sizeof(c));
		memset(r, true, sizeof(r));
		memset(b, true, sizeof(b));
		for (int x = 1; x <= 9; x++)
			for (int y = 1; y <= 9; y++)
			{
				shudu[x][y] = res[x][y];
			}
		suiji();
		checksingle(1, 1);
		if (pd) break;
	}
	memset(vis, false, sizeof(vis));
	dfs(1, 1, 0);
}