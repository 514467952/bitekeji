#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

typedef	struct student {
	char num[20];//学号 
	char name[20];
	int  chinese;
	int  math;
	int  English;
	int  sum;//总分 
	struct student *next;
} stud;

stud l[50];

int menu_select();//菜单选择函数 
int circulate();//循环选择函数 
stud* Creat();//录入模块 
int ShowStudent(stud *p);//显示模块 
int Search(stud *p);//查询模块 
int IndexOnNumber(stud *p);//查询模块 
stud* reorder(stud *p,int x);//排序函数 
char print(stud *d,int n);//输出函数 
void  Computer(stud *p);//统计模块 
void End();//结束函数 

int main()
{
	system("color F0");//改颜色 
    circulate();
    return 0; 
}

int menu_select() {//选择函数 
	int c;
	system("cls");
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	printf("\t\t\t %c   欢迎使用学生成绩管理系统    %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        1.输入学生信息         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        2.删除学生信息         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        3.增添学生信息         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        4.显示所有学生信息     %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        5.按查姓名查找学生信息 %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        6.计算总分和平均分     %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        7.学生成绩排名         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        8.按查学号查找学生信息 %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        9.退出系统             %c\n",4,4);
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	printf("\t\t\t (请输入数字1~9): ");
    
	scanf("%d",&c);
	return(c);
}