#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.11f%-12.11f%-12.11f%-12.11f\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum
struct student
{
	int num;
	char name[15];
	double elec;
	double expe;
	double requ;
	double sum;
};
struct student stu[50];
void in();
void show();
void order();
void del();
void modify();
void menu();
void insert();
void total();
void search();
