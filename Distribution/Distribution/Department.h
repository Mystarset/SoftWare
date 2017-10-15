#pragma once

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <cstdio>
#include <string>

using namespace std;
class Department
{
	public:
		Department();
		~Department();
		void setdno(string dno);
		string getdno();
		void setmlimit(int mlimit);
		int getmlimit();
		void setlalen(int lalen);
		int getlalen();
		void setlabel(string *label);
		string* getlabel();
		void settlen(int tlen);
		int gettlen();
		void setbeginTime(int *begintime);
		int* getbeginTime();
		void setendTime(int *endtime);
		int* getendTime();
		int getstulen();
		void setstu(string stu);
		string* getallstu();
		void setFormatTime();
	private:
		string dno;
		int mlimit;
		int lalen;
		string label[20];
		int tlen;
		string stime[10];
		int begintime[10];
		int endtime[10];
		int stulen;
		string allstu[20];
};

#endif 