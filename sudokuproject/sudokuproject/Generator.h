#pragma once

#ifndef GENERATOR_H
#define GENERATOR_H

class generator
{
private:
	int num;
	char shudu[10][10];
	bool c[10][10], r[10][10], b[10][10];


public:
	generator(int n);
	void getshudu(int n);
	void get(int x, int y);
	void print();

};

#endif