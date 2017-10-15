#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>
using namespace std;

class Student
{
	public:
		Student();
		~Student();
		void setsno(string sno);
		string getsno();
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
		void setdeslen(int deslen);
		int getdeslen();
		void setdesire(string *desire);
		string* getdesire();
		void setadjust(int adjust);
		int getadjust();
		int getdeplen();
		void setdep(string dep);
		string* getalldep();
		void setFormatTime();
		void setisworktime(int i,bool value);
		bool getisworktime(int i);
		bool getbelongdep(string dno);
	private:
		string sno;
		int lalen;
		string label[10];
		int tlen;
		int begintime[10];
		int endtime[10];
		int deslen;
		string desire[10];
		int adjust;
		int deplen;
		string alldep[10];
		bool isworktime[10];
		map<string, bool> belongdep;
};

#endif