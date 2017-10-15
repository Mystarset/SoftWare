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
	��־Ը���ȣ����ƥ��ʱ��ķ�ʽ����ѧ������ƥ��
*/
void Matching::matchbyFdesireStime()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < stusum; j++) {
			
			if (stu[j].getdeslen() < i + 1) continue; //���ѧ����־Ը���ȵ�ǰ�ĵ�i+1־ԸС�����ж��¸�ѧ��
			string dno = stu[j].getdesire()[i];

			int no = mdno[dno];//ͨ�����ű�Ż�ȡ������ʵ�ʵĲ��������±�

			//��ȡѧ�������ŵ�ʱ������
			int *stubtime = stu[j].getbeginTime();
			int *stuetime = stu[j].getendTime();
			int *depbtime = dep[no].getbeginTime();
			int *depetime = dep[no].getendTime();
			int stutlen = stu[j].gettlen();
			
			//ƥ��ʱ���
			for (int ii = 0; ii < stutlen; ii++) {
				if (!stu[j].getisworktime(ii)) { //�����ѧ���ĵ�ǰʱ���δ��ռ��
					
					bool flag = false;
					int deptlen = dep[no].gettlen(); 
					for (int jj = 0; jj < deptlen; jj++) {
						//�жϲ��ŵ������Ƿ��������Լ��ж��Ƿ�ʱ��η���
						if (dep[no].getstulen() < dep[no].getmlimit() 
							&& stubtime[ii] <= depbtime[jj] && stuetime[ii] >= depetime[jj]) {
							
							stu[j].setisworktime(ii,true); //��ѧ���ĵ�ǰʱ��α��δ����ʱ��
							stu[j].setdep(dno);	//�Ѳ�����Ϣ����ѧ��������
							dep[no].setstu(stu[j].getsno()); //��ѧ����Ϣ���벿��������
							flag = true; 
							break;
						}
					}
					if (flag) break;
				}
			}
		}
	}

	matchOnlyBydesire();	//��־Ըƥ�䣬����ʱ��
	matchOnlyByadjust();	//������ԭ��ƥ��
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

