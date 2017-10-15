#include "Department.h"



Department::Department()
{
	this->stulen = 0;
}


Department::~Department()
{
}

void Department::setdno(string dno)
{
	this->dno = dno;
}

string Department::getdno()
{
	return dno;
}

void Department::setmlimit(int mlimit)
{
	this->mlimit = mlimit;
}

int Department::getmlimit()
{
	return mlimit;
}

void Department::setlalen(int lalen)
{
	this->lalen = lalen;
}

int Department::getlalen()
{
	return lalen;
}

void Department::setlabel(string * label)
{
	for (int i = 0; i < lalen; i++) {
		this->label[i] = label[i];
	}
}

string * Department::getlabel()
{
	return label;
}

void Department::settlen(int tlen)
{
	this->tlen = tlen;
}

int Department::gettlen()
{
	return tlen;
}

void Department::setbeginTime(int * begintime)
{
	for (int i = 0; i < tlen; i++) {
		this->begintime[i] = begintime[i];
	}
}

int * Department::getbeginTime()
{
	return begintime;
}

void Department::setendTime(int * endtime)
{
	for (int i = 0; i < tlen; i++) {
		this->endtime[i] = endtime[i];
	}
}

int * Department::getendTime()
{
	return endtime;
}

int Department::getstulen()
{
	return stulen;
}

void Department::setstu(string stu)
{
	this->allstu[stulen] = stu;
	stulen++;
}

string * Department::getallstu()
{
	return allstu;
}


void Department::setFormatTime()
{
	int i = 0;
	while (i < this->tlen - 1) {
		if (endtime[i] >= begintime[i + 1]) {
			endtime[i] = endtime[i + 1];
			for (int j = i + 1; j < tlen; j++) {
				begintime[j] = begintime[j + 1];
				endtime[j] = endtime[j + 1];
			}
			this->tlen = this->tlen - 1;
		}
		else {
			i = i + 1;
		}
	}
}



