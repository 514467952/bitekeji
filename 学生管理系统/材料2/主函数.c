#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

typedef	struct student {
	char num[20];//ѧ�� 
	char name[20];
	int  chinese;
	int  math;
	int  English;
	int  sum;//�ܷ� 
	struct student *next;
} stud;

stud l[50];

int menu_select();//�˵�ѡ���� 
int circulate();//ѭ��ѡ���� 
stud* Creat();//¼��ģ�� 
int ShowStudent(stud *p);//��ʾģ�� 
int Search(stud *p);//��ѯģ�� 
int IndexOnNumber(stud *p);//��ѯģ�� 
stud* reorder(stud *p,int x);//������ 
char print(stud *d,int n);//������� 
void  Computer(stud *p);//ͳ��ģ�� 
void End();//�������� 

int main()
{
	system("color F0");//����ɫ 
    circulate();
    return 0; 
}

int menu_select() {//ѡ���� 
	int c;
	system("cls");
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	printf("\t\t\t %c   ��ӭʹ��ѧ���ɼ�����ϵͳ    %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        1.����ѧ����Ϣ         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        2.ɾ��ѧ����Ϣ         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        3.����ѧ����Ϣ         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        4.��ʾ����ѧ����Ϣ     %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        5.������������ѧ����Ϣ %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        6.�����ֺܷ�ƽ����     %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        7.ѧ���ɼ�����         %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        8.����ѧ�Ų���ѧ����Ϣ %c\n",4,4);
	printf("\t\t\t %c                               %c\n",4,4);
	printf("\t\t\t %c        9.�˳�ϵͳ             %c\n",4,4);
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	printf("\t\t\t (����������1~9): ");
    
	scanf("%d",&c);
	return(c);
}