#include "CreateJsonInput.h"

#include <cstdio>
#include <cstring>
#include <ctime>
#include <map>
using namespace std;

CreateJsonInput::CreateJsonInput(string filename)
{
	this->dno = 1000;
	this->sno = 10000000;
	this->filename = filename;
	for (int i = 0; i < 20; i++){
		char tmp[10];
		sprintf(tmp, "%d", i);
		this->label[i] = tmp;
	}
}


CreateJsonInput::~CreateJsonInput()
{
}

void CreateJsonInput::createAll(int stusum, int depsum)
{
	srand((unsigned)time(0));
	freopen(filename.data(), "w" ,stdout);
	printf("{\n");
	printf("\t\"departments\" :\n");
	printf("\t[\n");
	for (int i = 0; i < depsum; i++) {
		printf("\t\t{\n");
		printf("\t\t\t");
		createDno();
		printf("\t\t\t");
		createDemandnum();
		printf("\t\t\t");
		createLabel();
		printf("\t\t\t");
		createTime();
		printf("\n");
		if (i != depsum - 1) printf("\t\t},\n");
		else printf("\t\t}\n");
	}
	printf("\t],\n");
	printf("\t\"students\" :\n");
	printf("\t[\n");
	for (int i = 0; i < stusum; i++) {
		printf("\t\t{\n");
		printf("\t\t\t");
		createSno();
		printf("\t\t\t");
		createLabel();
		printf("\t\t\t");
		createTime();
		printf(",\n");
		printf("\t\t\t");
		createDesire(depsum);
		printf("\t\t\t");
		createAdjust();
		if (i != stusum - 1) printf("\t\t},\n");
		else printf("\t\t}\n");
	}
	printf("\t]\n");
	printf("}");
	fclose(stdout);
}

void CreateJsonInput::createSno()
{
	printf("\"student_no\" : \"%d\",\n", sno);
	sno = sno + 1;
}

void CreateJsonInput::createLabel()
{
	int ran = 1 + rand() % 5;
	printf("\"tags\" : [");
	map<string, int> ma;
	ma.clear();
	for (int i = 0; i < ran; i++) {
		string t = label[rand() % 20];
		while (ma[t]) {
			t = label[rand() % 20];
		}
		ma[t] = 1;
		if (i != ran - 1) printf("\"%s\", ", t.data());
		else printf("\"%s\"],\n", t.data());
	}
}

void CreateJsonInput::createTime()
{
	int ran = rand() % 5 + 1;
	struct {
		int begin, end;
	}t[10];
	printf("\"schedules\" : [");
	for (int i = 0; i < ran; i++) {
		t[i].begin = rand() % 2 + 8 + i * 3;
		t[i].end = t[i].begin + 2;
		if (i != ran - 1) printf("\"%02d:00-%02d:00\", ", t[i].begin,t[i].end);
		else printf("\"%02d:00-%02d:00\"]", t[i].begin,t[i].end);
	}
}

void CreateJsonInput::createDesire(int depsum)
{
	int mod = 5;
	if (depsum < 5) mod = depsum;
	int ran = 1 + rand() % mod;
	printf("\"desire\" : [");
	int base = 1000;
	int t;
	map<int, int>ma;
	ma.clear();
	for (int i = 0; i < ran; i++) {
		t = base + rand() % depsum;
		while (ma[t]) {
			t = base + rand() % depsum;
		}
		ma[t] = 1;
		if (i != ran - 1) printf("\"%d\", ", t);
		else printf("\"%d\"],\n", t);
		
	}
}

void CreateJsonInput::createAdjust()
{
	int t;
	t = rand() % 2;
	printf("\"adjust\" : %d\n",t);
}

void CreateJsonInput::createDno()
{
	printf("\"department_no\" : \"%d\",\n",dno);
	dno = dno + 1;
}

void CreateJsonInput::createDemandnum()
{
	int ran = 1 + rand() % 15;
	printf("\"member_limit\" : %d,\n", ran);
}
