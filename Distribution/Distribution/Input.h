#pragma once

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "Student.h"
#include "Department.h"
using namespace std;

class Input
{
	public:
		Input();
		~Input();
		string readInputTestFile(const char *path);
		void init(Student *stu, Department *dep, string text);
};

#endif 
