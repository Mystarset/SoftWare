#pragma once

#ifndef MATCHING_H
#define MATCHING_H

#include <cstdio>
#include <string>
#include <map>
#include "Student.h"
#include "Department.h"

using namespace std;
class Matching
{
	public:
		Matching(Student *stu,int stusum,Department *dep,int depsum);
		~Matching();
		void matchOnlyBydesire();
		void matchOnlyByadjust();
		void matchbyFdesireStime();
		void matchbyFdesireSlabel();
	private:
		Student *stu;
		Department *dep;
		int stusum;
		int depsum;
		map<string, int>mdno;
		
};

#endif