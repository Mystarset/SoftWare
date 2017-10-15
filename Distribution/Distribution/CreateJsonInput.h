#pragma once

#ifndef CREATEJSONINPUT_H
#define CREATEJSONINPUT_H

#include <cstdio>
#include <string>
using namespace std;

class CreateJsonInput
{
	public:
		CreateJsonInput(string filename);
		~CreateJsonInput();
		void createAll(int stusum,int depsum);
	private:
		void createSno();
		void createLabel();
		void createTime();
		void createDesire(int depsum);
		void createAdjust();
		void createDno();
		void createDemandnum();
		int dno;
		int sno;
		string filename;
		string label[20];
};

#endif