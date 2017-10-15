#include "Student.h"
#include <map>

using namespace std;

Student::Student()
{
	for (int i = 0; i < 10; i++) {
		this->isworktime[i] = false;
	}
	belongdep.clear();
	this->deplen = 0;
}


Student::~Student()
{
}

void Student::setsno(string sno)
{
	this->sno = sno;
}

string Student::getsno()
{
	return sno;
}

void Student::setlalen(int lalen)
{
	this->lalen = lalen;
}

int Student::getlalen()
{
	return lalen;
}

void Student::setlabel(string * label)
{
	for (int i = 0; i < lalen; i++) {
		this->label[i] = label[i];
	}
}

string * Student::getlabel()
{
	return label;
}

void Student::settlen(int tlen)
{
	this->tlen = tlen;
}

int Student::gettlen()
{
	return tlen;
}

void Student::setbeginTime(int * begintime)
{
	for (int i = 0; i < tlen; i++) {
		this->begintime[i] = begintime[i];
	}
}

int * Student::getbeginTime()
{
	return begintime;
}

void Student::setendTime(int * endtime)
{
	for (int i = 0; i < tlen; i++) {
		this->endtime[i] = endtime[i];
	}
}

int * Student::getendTime()
{
	return endtime;
}

void Student::setdeslen(int deslen)
{
	this->deslen = deslen;
}

int Student::getdeslen()
{
	return deslen;
}

void Student::setdesire(string * desire)
{
	for (int i = 0; i < deslen; i++) {
		this->desire[i] = desire[i];
	}
}

string * Student::getdesire()
{
	return desire;
}

void Student::setadjust(int adjust)
{
	this->adjust = adjust;
}

int Student::getadjust()
{
	return adjust;
}

int Student::getdeplen()
{
	return deplen;
}

void Student::setdep(string dep)
{
	this->alldep[deplen] = dep;
	belongdep[dep] = true;
	deplen++;
}

string * Student::getalldep()
{
	return alldep;
}

void Student::setFormatTime()
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

void Student::setisworktime(int i, bool value)
{
	this->isworktime[i] = value;
}

bool Student::getisworktime(int i)
{
	return this->isworktime[i];
}

bool Student::getbelongdep(string dno)
{
	return belongdep[dno];
}

