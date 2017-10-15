#include "Matching.h"

#include <cstdio>
#include <string>
#include "Student.h"
#include "Department.h"

using namespace std;

Matching::Matching(Student *stu,int stusum,Department *dep,int depsum)
{
	this->stu = stu;
	this->dep = dep;
	this->stusum = stusum;
	this->depsum = depsum;

	for (int i = 0; i < depsum; i++) {
		mdno[this->dep[i].getdno()] = i;
	}
}


Matching::~Matching()
{
}

void Matching::matchOnlyBydesire() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < stusum; j++) {

			if (stu[j].getdeslen() < i + 1) continue;
			string dno = stu[j].getdesire()[i];
			int no = mdno[dno];
			if (stu[j].getbelongdep(dno)) continue;

			if (dep[no].getmlimit() > dep[no].getstulen()) {

				stu[j].setdep(dno);
				dep[no].setstu(stu[j].getsno());
			}
		}
	}
}

void Matching::matchOnlyByadjust() {

	for (int i = 0; i < stusum; i++) {

		if (stu[i].getadjust() == 0 || stu[i].getdeplen() != 0) continue;

		int maxneed = 0;
		int t = -1;
		for (int j = 0; j < depsum; j++) {

			if (dep[j].getstulen() == 0) {
				t = j;
				break;
			}
			int tmp = dep[j].getmlimit() - dep[j].getstulen();
			if (tmp <= 0) continue;

			if (tmp > maxneed) {
				t = j;
				maxneed = tmp;
			}
		}

		if (t == -1) break;
		stu[i].setdep(dep[t].getdno());
		dep[t].setstu(stu[i].getsno());
	}
}
/*
	按志愿优先，其次匹配时间的方式进行学生部门匹配
*/
void Matching::matchbyFdesireStime()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < stusum; j++) {
			
			if (stu[j].getdeslen() < i + 1) continue; //如果学生的志愿数比当前的第i+1志愿小，则判断下个学生
			string dno = stu[j].getdesire()[i];

			int no = mdno[dno];//通过部门编号获取代码中实际的部门数组下标

			//获取学生及部门的时间数据
			int *stubtime = stu[j].getbeginTime();
			int *stuetime = stu[j].getendTime();
			int *depbtime = dep[no].getbeginTime();
			int *depetime = dep[no].getendTime();
			int stutlen = stu[j].gettlen();
			
			//匹配时间段
			for (int ii = 0; ii < stutlen; ii++) {
				if (!stu[j].getisworktime(ii)) { //如果该学生的当前时间段未被占用
					
					bool flag = false;
					int deptlen = dep[no].gettlen(); 
					for (int jj = 0; jj < deptlen; jj++) {
						//判断部门的人数是否已满，以及判断是否时间段符合
						if (dep[no].getstulen() < dep[no].getmlimit() 
							&& stubtime[ii] <= depbtime[jj] && stuetime[ii] >= depetime[jj]) {
							
							stu[j].setisworktime(ii,true); //把学生的当前时间段标记未工作时间
							stu[j].setdep(dno);	//把部门信息传入学生数据中
							dep[no].setstu(stu[j].getsno()); //把学生信息传入部门数据中
							flag = true; 
							break;
						}
					}
					if (flag) break;
				}
			}
		}
	}

	matchOnlyBydesire();	//按志愿匹配，不管时间
	matchOnlyByadjust();	//按调剂原则匹配
}

void Matching::matchbyFdesireSlabel()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < stusum; j++) {

			if (stu[j].getdeslen() < i + 1) continue;
			string dno = stu[j].getdesire()[i];

			int no = mdno[dno];
			int stulalen = stu[j].getlalen();
			int deplalen = dep[no].getlalen();
			string *stulabel = stu[j].getlabel();
			string *deplabel = dep[no].getlabel();
			int stutlen = stu[j].gettlen();

			bool flag = false;
			for (int ii = 0; ii < stulalen; ii++) {
				for (int jj = 0; jj < deplalen; jj++) {
					if (dep[no].getstulen() < dep[no].getmlimit() && 
						stulabel[ii].compare(deplabel[jj]) == 0) {

						stu[j].setdep(dno);
						dep[no].setstu(stu[j].getsno());
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
	}

	matchOnlyBydesire();
	matchOnlyByadjust();
}

