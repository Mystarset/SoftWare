#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

#include "Output.h"
#include "Department.h"
#include "Student.h"
#include "jsoncpp/include/json.h"
using namespace std;

Output::Output()
{
}


Output::~Output()
{
}

void Output::outputjson(Student * stu,int stusum, Department * dep,int depsum,FILE *file)
{
	fputs("{\n",file);
	fputs("\t\"matched_department_view\" :\n",file);
	fputs("\t{\n",file);
	for (int i = 0; i < depsum; i++) {
		fprintf(file,"\t\t\"%s\" : [",dep[i].getdno().data());
		int stulen = dep[i].getstulen();
		string *allstu = dep[i].getallstu();
		for (int j = 0; j < stulen; j++) {
			if (j == stulen - 1) fprintf(file, "\"%s\"", allstu[j].data());
			else fprintf(file,"\"%s\", ",allstu[j].data());
		}
		if (i == depsum - 1) fprintf(file,"]\n");
		else fprintf(file, "],\n");
	}
	fputs("\t},\n", file);
	fputs("\t\"matched_student_view\" :\n", file);
	fputs("\t{\n", file);
	for (int i = 0; i < stusum; i++) {
		fprintf(file, "\t\t\"%s\" : [", stu[i].getsno().data());
		int deplen = stu[i].getdeplen();
		string *alldep = stu[i].getalldep();
		for (int j = 0; j < deplen; j++) {
			if (j == deplen - 1) fprintf(file, "\"%s\"", alldep[j].data());
			else fprintf(file, "\"%s\", ", alldep[j].data());
		}
		if (i == stusum - 1) fputs("]\n",file);
		else fputs("],\n",file);
	}
	fputs("\t},\n",file);
	fputs("\t\"standalone_departments\" : \n", file);
	fputs("\t[\n",file);
	bool flag = false;
	for (int i = 0; i < depsum; i++) {
		if (dep[i].getstulen() == 0) {
			if (!flag) {
				fprintf(file, "\t\t\"%s\"",dep[i].getdno().data());
				flag = true;
			}
			else {
				fprintf(file, ",\n\t\t\"%s\"", dep[i].getdno().data());
			}
		}
	}
	fputs("\t],\n", file);
	fputs("\t\"standalone_students\" : \n", file);
	fputs("\t[\n", file);
	flag = false;
	for (int i = 0; i < stusum; i++) {
		if (stu[i].getdeplen() == 0) {
			if (!flag) {
				fprintf(file, "\t\t\"%s\"", stu[i].getsno().data());
				flag = true;
			}
			else {
				fprintf(file, ",\n\t\t\"%s\"", stu[i].getsno().data());
			}
		}
	}
	fputs("\n\t]\n", file);
	fputs("}",file);
}

