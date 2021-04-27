#include <algorithm>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <set>
#include<time.h>
#include <cstdio>
#define FR(i,n) for(int i=0;i<n;i++)
#define MAX 2005
#define MAXTIME 28800
#define mkp pair <int,int>
using namespace std;
typedef long long ll;
const int inf = 100000000;
void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}
using namespace std;
const int maxn = 1e3 + 5;
typedef struct pnode {
	pnode *next;
	char idc[maxn];
	char sname[maxn];
	char cno[maxn];
	int grade;
}*ptrval;
ptrval phead1 = new pnode;
//	ptrval phead2 = new pnode;
ptrval ptemp = new pnode;
ptrval ptrval1 = new pnode;
//	ptrval ptrval2 = new pnode;
struct inof {
	char idc[maxn];
	char sname[maxn];
	char cno[maxn];
	int grade;
}p[maxn];
struct grade {
	int a, b, c;
	char sname[maxn];
	double ans;
}ave[maxn];
map <string, int > mp;
char temp1[maxn], temp2[maxn];
void cop(char *a, char *b) {
	int l1 = strlen(a), l2 = strlen(b);
	for (int i = 0; i < l2; i++)a[i] = b[i];
	a[l2] = 0;
}
bool check(char *a, char *b) {
	int l1 = strlen(a), l2 = strlen(b);
	if (l1 != l2)return 0;
	for (int i = 0; i < l1; i++)if (a[i] != b[i])return 0;
	return 1;
}
int top;
FILE *fp;
bool cmp(inof a, inof b) {
	if (!check(a.cno, b.cno))return strcmp(a.cno, b.cno) > 0;
	return a.grade > b.grade;
}
int tot;
char temp3[maxn];
void init() {
	//	cout<<1;
	phead1 = ptrval1;
	//	phead2 = ptrval2;
	phead1->next = NULL;
	ptrval1->next = NULL;
	for (int i = 0; i < maxn; i++)ave[i].a = ave[i].b = ave[i].c = 0;
	//	   cout<<1;
	fp = fopen("init.txt", "r+");///���ļ��� 
	while (!feof(fp)) {
		fscanf(fp, "%s", temp3);///���� 
		fscanf(fp, "%s", temp1);///���� 
		fscanf(fp, "%s", temp2);///���� 
		string sh = "";
		int l1 = strlen(temp1);
		for (int i = 0; i < l1; i++)sh += temp1[i];
		if (!mp[sh])mp[sh] = ++tot;
		int id = mp[sh];
		//	cout<<temp2<<endl;
		int grade;
		fscanf(fp, "%d", &grade);///���� 
		if (temp2[0] == 'e')ave[id].a = grade;
		else if (temp2[0] == 'm')ave[id].b = grade;
		else ave[id].c = grade;
		struct inof tmp;
		cop(tmp.idc, temp3);
		cop(ave[id].sname, temp1);
		cop(tmp.sname, temp1);
		cop(tmp.cno, temp2);
		tmp.grade = grade;
		p[top++] = tmp;
	}
	printf("¼����Ϣ�ɹ�\n");
	for (int i = 0; i < top; i++) {
		cout << p[i].idc << ' ' << p[i].sname << ' ' << p[i].cno << ' ' << p[i].grade << endl;
	}
	sort(p, p + top, cmp);
	fclose(fp);
	for (int i = 0; i < top; i++) {
		ptrval ptemp = new pnode;
		ptemp->next = ptrval1;
		cop(ptemp->cno, p[i].cno);
		cop(ptemp->idc, p[i].idc);
		cop(ptemp->sname, p[i].sname);
		ptemp->grade = p[i].grade;
		///   ptemp->val = val;
		ptrval1 = ptemp;
	}
	// cout<<1;
	ptemp = ptrval1;
	//	ptemp=ptemp->next;
	while (ptemp->next) {
		//	cout<<1;
		//	if(check(ptemp->cno,"math")){
		//	cout<<ptemp->idc<<' '<<ptemp->sname<<' '<<ptemp->cno<<' '<<ptemp->grade<<endl;
			//	fprintf(fp,"%s %d\n",ptemp->sname,ptemp->grade);
		//	}
		ptemp = ptemp->next;
	}
}
char s1[maxn] = "english.txt", s2[maxn] = "math.txt", s3[maxn] = "chinese.txt";
void solvea() {
	fp = fopen(s1, "w+");///���ļ���
	//ptrval ptemp;
	ptemp = ptrval1;
	for (int i = 0; i < top; i++) {
		if (check(p[i].cno, "english")) {
			fprintf(fp, "%s %d\n", p[i].sname, p[i].grade);
		}
	}
	fclose(fp);
	fp = fopen(s2, "w+");///���ļ���
	ptemp = ptrval1;
	while (ptemp->next != 0) {
		//cout<<1<<endl;
		if (check(ptemp->cno, "math")) {//cout<<1;
		   // cout<<ptemp->sname<<endl;
			fprintf(fp, "%s %d\n", ptemp->sname, ptemp->grade);
		}
		ptemp = ptemp->next;
	}
	fclose(fp);
	fp = fopen(s3, "w+");///���ļ��� 
	ptemp = ptrval1;
	while (ptemp->next != 0) {
		if (check(ptemp->cno, "chinese")) {
			fprintf(fp, "%s %d\n", ptemp->sname, ptemp->grade);
		}
		ptemp = ptemp->next;
	}
	fclose(fp);
}
bool cmp1(grade a, grade b) {
	return a.ans > b.ans;
}
void solveb() {
	for (int i = 1; i <= tot; i++)ave[i].ans = (ave[i].a + ave[i].b + ave[i].c) / 3.0;
	sort(ave + 1, ave + tot + 1, cmp1);
	fp = fopen("ave.txt", "w+");///���ļ��� 
	for (int i = 1; i <= tot; i++) {
		//	if(check(p[i].cno,"math")){
		fprintf(fp, "%s %lf\n", ave[i].sname, ave[i].ans);
	}
	fclose(fp);
}
void solvec() {
	int a = 0, b = 0, c = 0, maxx = -1;
	for (int i = 0; i < top; i++) {
		if (check(p[i].cno, "math")) {
			if (p[i].grade >= 90)a++;
			else if (p[i].grade >= 60)b++;
			else c++;
			maxx = max(maxx, p[i].grade);
		}
	}
	printf("math��߷�Ϊ%d ����������Ϊ %d , С��60����Ϊ %d ,60-90֮������Ϊ %d �� ����90����Ϊ %d\n", maxx, c, c, b, a);
	a = 0, b = 0, c = 0, maxx = -1;
	for (int i = 0; i < top; i++) {
		if (check(p[i].cno, "chinese")) {
			if (p[i].grade >= 90)a++;
			else if (p[i].grade >= 60)b++;
			else c++;
			maxx = max(maxx, p[i].grade);
		}
	}
	printf("chinese��߷�Ϊ%d ����������Ϊ %d , С��60����Ϊ %d ,60-90֮������Ϊ %d �� ����90����Ϊ %d\n", maxx, c, c, b, a);
	a = 0, b = 0, c = 0, maxx = -1;
	for (int i = 0; i < top; i++) {
		if (check(p[i].cno, "english")) {
			if (p[i].grade >= 90)a++;
			else if (p[i].grade >= 60)b++;
			else c++;
			maxx = max(maxx, p[i].grade);
		}
	}
	printf("english��߷�Ϊ%d ����������Ϊ %d , С��60����Ϊ %d ,60-90֮������Ϊ %d �� ����90����Ϊ %d\n", maxx, c, c, b, a);
}
void solved() {
	printf("���������ѧ�Ż���������ѯ�ɼ�\n");
	string sh;
	cin >> sh;
	if (sh == "ѧ��") {
		char tmp[maxn];
		printf("������ѧ��"); cin >> tmp;
		for (int i = 0; i < top; i++) {
			if (check(p[i].idc, tmp)) {
				cout << p[i].idc << ' ' << p[i].sname << ' ' << p[i].cno << ' ' << p[i].grade << endl;
			}
		}
	}
	else {
		char tmp[maxn];
		printf("����������"); cin >> tmp;
		for (int i = 0; i < top; i++) {
			if (check(p[i].sname, tmp)) {
				cout << p[i].idc << ' ' << p[i].sname << ' ' << p[i].cno << ' ' << p[i].grade << endl;
			}
		}
	}
}
int choice;
void show() {
	printf("����4��ѡ��");
	printf("1�����ſγ̳������򣬲������ļ�\n");
	printf("2����ÿ���˵�ƽ���ɼ������ճ������������ļ�\n");
	printf("3ͳ��ÿ�ſγ̵���߳ɼ������������������ֶ�����\n");
	printf("4����ѧ�Ż���������ѯ���Ƴɼ�\n");
	cin >> choice;
}
int main() {
	//	cout<<1;
	init();
	while (1) {
		show();
		if (choice == 1)solvea();
		else if (choice == 2)solveb();
		else if (choice == 3)solvec();
		else solved();
	}
}