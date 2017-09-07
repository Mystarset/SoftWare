#pragma once

#ifndef DIG_H
#define DIG_H


class Dig
{
	private:
		int sum;
		int total;
		int shudu[10][10];
		bool c[10][10], r[10][10], b[10][10];
		bool c1[10][10], r1[10][10], b1[10][10];

	public:
		Dig();
		~Dig();
		void get(int n);
		void check(int x,int y);
		void suiji();
		void print();
		int getbox(int x,int y);
};

#endif