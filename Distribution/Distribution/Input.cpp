#include <cstdio>
#include <string>

#include "Input.h"
#include "Department.h"
#include "Student.h"
#include "jsoncpp/include/json.h"
using namespace std;

Input::Input()
{
}


Input::~Input()
{
}

string Input::readInputTestFile(const char *path)
{
	FILE *file = fopen(path, "rb");
	if (!file)
		return std::string("");
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	std::string text;
	char *buffer = new char[size + 1];
	buffer[size] = 0;
	if (fread(buffer, 1, size, file) == (unsigned long)size)
		text = buffer;
	fclose(file);
	delete[] buffer;
	return text;
}

void Input::init(Student *stu, Department *dep, string text) {
	Json::Reader reader;
	Json::Value value;

	if (reader.parse(text, value)) {
		const Json::Value arrstu = value["students"];
		int stulen = arrstu.size();
		for (unsigned int i = 0; i < stulen; i++) {
			string sno = arrstu[i]["student_no"].asString();
			stu[i].setsno(sno);

			const Json::Value arrtag = arrstu[i]["tags"];
			int lalen = arrtag.size();
			stu[i].setlalen(arrtag.size());

			string label[10];
			for (unsigned int j = 0; j < lalen; j++) {
				label[j] = arrtag[j].asString();
			}
			stu[i].setlabel(label);

			const Json::Value arrsch = arrstu[i]["schedules"];
			int schlen = arrsch.size();
			stu[i].settlen(schlen);

			int begintime[10];
			int endtime[10];
			for (unsigned int j = 0; j < schlen; j++) {
				string tmp = arrsch[j].asString();
				sscanf(tmp.data(), "%d:00-%d:00", &begintime[j], &endtime[j]);
			}
			stu[i].setbeginTime(begintime);
			stu[i].setendTime(endtime);

			const Json::Value arrdes = arrstu[i]["desire"];
			int deslen = arrdes.size();
			stu[i].setdeslen(deslen);

			string desire[10];
			for (unsigned int j = 0; j < deslen; j++) {
				desire[j] = arrdes[j].asString();
			}
			stu[i].setdesire(desire);

			int adjust = arrstu[i]["adjust"].asInt();
			stu[i].setadjust(adjust);
			stu[i].setFormatTime();
		}


		const Json::Value arrdep = value["departments"];
		int deplen = arrdep.size();
		for (unsigned int i = 0; i < deplen; i++) {

			string dno = arrdep[i]["department_no"].asString();
			dep[i].setdno(dno);

			int mlimit = arrdep[i]["member_limit"].asInt();
			dep[i].setmlimit(mlimit);

			const Json::Value arrtag = arrdep[i]["tags"];
			int lalen = arrtag.size();
			dep[i].setlalen(lalen);

			string tags[20];
			for (unsigned int j = 0; j < lalen; j++) {
				tags[j] = arrtag[j].asString();
			}
			dep[i].setlabel(tags);

			const Json::Value arrsch = arrdep[i]["schedules"];
			int schlen = arrsch.size();
			dep[i].settlen(schlen);

			int begintime[10];
			int endtime[10];
			for (unsigned int j = 0; j < schlen; j++) {
				string tmp = arrsch[j].asString();
				sscanf(tmp.data(), "%d:00-%d:00", &begintime[j], &endtime[j]);
			}
			dep[i].setbeginTime(begintime);
			dep[i].setendTime(endtime);
			dep[i].setFormatTime();
		}
	}
}