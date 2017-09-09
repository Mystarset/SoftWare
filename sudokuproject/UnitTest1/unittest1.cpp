#include "stdafx.h"
#include "CppUnitTest.h"
#include "E:/软件工程/sudokuproject/sudokuproject/sudokuproject/Generator.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int res[10][10];
int c[10][10], r[10][10], b[10][10];

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		int getbox(int x, int y)
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
		bool check()
		{
			memset(c, 0, sizeof(c));
			memset(r, 0, sizeof(r));
			memset(b, 0, sizeof(b));
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 9; j++)
				{
					c[i][res[i][j]]++;
					r[j][res[i][j]]++;
					b[getbox(i, j)][res[i][j]]++;
				}
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 9; j++)
				{
					if (c[i][j] != 1) return false;
					if (r[i][j] != 1) return false;
					if (b[i][j] != 1) return false;
				}
			return true;
		}
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			freopen("input.txt", "w", stdout);
			generator gen(6);
			int n = 10000;
			gen.getshudu(n);

			fclose(stdout);
			freopen("input.txt", "r", stdin);


			bool pd = true;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					for (int k = 1; k <= 9; k++)
					{
						scanf("%d", &res[j][k]);
					}
				}
				if (!check()) pd = false;
			}

			Assert::IsTrue(pd);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			freopen("input.txt", "w", stdout);
			generator gen(6);
			int n = 1000;
			gen.getshudu(n);

			fclose(stdout);
			freopen("input.txt", "r", stdin);


			bool pd = true;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					for (int k = 1; k <= 9; k++)
					{
						scanf("%d", &res[j][k]);
					}
				}
				if (!check()) pd = false;
			}

			Assert::IsTrue(pd);
		}

	};
}