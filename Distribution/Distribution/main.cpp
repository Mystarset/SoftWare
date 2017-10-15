#include <cstdio>
#include <cstring>
#include <iostream>
#include "Student.h"
#include "Department.h"
#include "Matching.h"
#include "Input.h"
#include "Output.h"
#include "CreateJsonInput.h"
#include "jsoncpp/include/json.h"
using namespace std;

int StringtoInt(char *c) {
	int t = 0;
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		if (c[i] < '0' || c[i] > '9') return 0;
		t = t * 10 + (c[i] - '0');
	}
	return t;
}
int main(int argc,char *argv[])
{
	int stusum;
	int depsum;

	string inputfilename = "";
	string outputfilename = "";
	char tmp1[10], tmp2[10];

	if (argc != 4) {
		printf("Wrong Command!");
	}
	else if (strcmp(argv[1],"-c") != 0 && strcmp(argv[1], "-mdt") != 0 && strcmp(argv[1], "-mdl") != 0 ){
		printf("Wrong Command!");
	}
	else {
		int a = StringtoInt(argv[2]);
		int b = StringtoInt(argv[3]);

		stusum = a;
		depsum = b;

		sprintf(tmp1, "%d", stusum);
		sprintf(tmp2, "%d", depsum);
		inputfilename = inputfilename + "s" + tmp1 + "-" + "d" + tmp2 + "-in.json";
		outputfilename = outputfilename + "s" + tmp1 + "-" + "d" + tmp2 + "-out.json";
		if (a == 0 || b == 0) printf("Wrong Command!");
		else {
			if (strcmp(argv[1],"-c") == 0) {

				CreateJsonInput *cji = new CreateJsonInput(inputfilename);
				cji->createAll(stusum,depsum);
				delete cji;
			}
			else {

				Student *stu = new Student[stusum];
				Department *dep = new Department[depsum];

				Input *in = new Input();
				string text = in->readInputTestFile(inputfilename.data());
				in->init(stu, dep, text);
				delete in;

				Matching *mat = new Matching(stu, stusum, dep, depsum);
				if (strcmp(argv[1],"-mdt") == 0) mat->matchbyFdesireStime();
				else mat->matchbyFdesireSlabel();
				delete mat;

				FILE *file = fopen(outputfilename.data(), "w");
				Output *out = new Output();
				out->outputjson(stu, stusum, dep, depsum, file);
				delete out;
				fclose(file);

				delete[] stu;
				delete[] dep;
			}
		}
	}

	return 0;
}


