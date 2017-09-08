#pragma once

#ifndef DIG_H
#define DIG_H


class Dig
{
	private:
		int sum;
		int total;
		int shudu[10][10];
		int res[10][10];
		bool c[10][10], r[10][10], b[10][10];
		bool c1[10][10], r1[10][10], b1[10][10];
		bool vis[10][10];


	public:
		Dig();
		~Dig();
		void get(int n);
		void checksingle(int x,int y);
		bool checkrule();
		void suiji();
		void print();
		int getbox(int x,int y);
		void dfs(int x, int y,int n);
};

#endif