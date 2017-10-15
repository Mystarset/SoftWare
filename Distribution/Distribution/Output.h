#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

#include "Student.h"
#include "Department.h"
#include "jsoncpp/include/json.h"

class Output
{
	public:
		Output();
		~Output();
		void outputjson(Student *stu,int stusum, Department *dep,int depsum,FILE *file);
};

#endif // !OUTPUT_H