#include <iostream>
#include <cstdio>
#include <cstring>
#include "generator.h"

using namespace std;

int n = 0;

bool check(string str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
		else
		{
			n = n * 10 + str[i] - '0';
		}
	}
	return true;
}
int main(int argc, char* argv[])
{

	string str1, str2;
	freopen("sudoku.txt", "w", stdout);
	if (argc == 1 || argc == 2 || argc > 3)
	{

		printf("Wrong Command\n");
	}
	else
	{
		str1 = argv[1];
		str2 = argv[2];

		if (str1 != "-c" || !check(str2))
		{
			printf("Wrong Command\n");
		}
		else
		{
			generator *gen = new generator(6);
			gen->getshudu(n);
		}
	}

	return 0;
}