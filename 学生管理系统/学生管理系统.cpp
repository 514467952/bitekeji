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
	printf("\n");
	printf("\t\t    欢迎使用学生成绩管理系统    \n");
	printf("\t\t                                \n");
	printf("\t\t         1.输入学生信息         \n");
	printf("\t\t                                \n");
	printf("\t\t         2.删除学生信息         \n");
	printf("\t\t                                \n");
	printf("\t\t         3.增添学生信息         \n");
	printf("\t\t                                \n");
	printf("\t\t         4.显示所有学生信息     \n");
	printf("\t\t                                \n");
	printf("\t\t         5.按查姓名查找学生信息 \n");
	printf("\t\t                                \n");
	printf("\t\t         6.计算总分和平均分     \n");
	printf("\t\t                                \n");
	printf("\t\t         7.学生成绩排名         \n");
	printf("\t\t                                \n");
	printf("\t\t         8.按查学号查找学生信息 \n");
	printf("\t\t                                \n");
	printf("\t\t         9.退出系统             \n");
	printf("\n");
	printf("\t\t   (请输入数字0~9): ");
    
	scanf("%d",&c);
	return(c);
}

stud* Creat() //创建函数 
{
	system("cls");
	printf("\t\t              HELLO，您正在输入学生信息...     \n\n");
	printf("\t\t              请根据提示输入学生信息:      \n\n");
	int i,j;
	stud *head,*p1,*p2;
	printf("\t\t\t  ◎请输入总数:");
	scanf("%d",&i);
	if(i<=0)
	{
	 printf("\t\t\t输入错误请重试\n"); 
	 system("pause");//暂停屏幕 
	 
   }
   
	if((head=(stud *)malloc(sizeof(stud)))==NULL)//创建头指针 
	{
		printf("\t\t\t空间不足建立失败\n");
		exit(0);
	}
	head->next=NULL;
	p1=head;
	
	for(j=0;j<i;j++)
	{
    	if((p2=(stud *)malloc(sizeof(stud)))==NULL)//创建新的节点 
	{	
		printf("\t\t\t空间不足建立失败\n");
		exit(0);
	}
	//输入学生信息 
   printf("\t\t您正在输入第%d个人的信息\n",j+1); 
   printf("\t\t ◎请输入学号:");
   scanf("%s",p2->num);
   printf("\t\t ◎请输入姓名:");
   scanf("%s",p2->name);
   printf("\t\t ◎请输入语文成绩:");
   scanf("%d",&p2->chinese);
   printf("\t\t ◎请输入数学成绩:");
   scanf("%d",&p2->math);
   printf("\t\t ◎请输入英语成绩:");
   scanf("%d",&p2->English);
   p2->sum=p2->chinese+p2->English+p2->math;
   //使上一个节点指向下一个节点 
   p1->next=p2;
   p2->next=NULL;//使最后节点next为空 
   p1=p2;
   
   if(i>=3 && (j+1)%2==0) system("cls"); 
   
	}
	printf("\t\t已成功输入学生信息\n");
	system("pause");
	return (head);//返回头指针 
}

int Search(stud *p) //查询函数 
{ //传头指针过来 
	if(p==NULL || p->next==NULL)//防止无学生信息 
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 0;
    }
    stud *q=p->next,*a=p->next;
	char n[20],b[20];
	char m = 'y';
    while(m == 'y')//当m=‘y’时循环 
   {
	q=a;//每次循环重置指针q 
	system("cls");
    printf("\t\t\t请输入姓名:");
    scanf("%s",b);
    printf("\n");
    while(q)
   {
   	if(strcmp(q->name,b)==0)//比较节点中的姓名是否一致
	{ 
   	printf("\t\t\t姓名:%s\n",q->name);
   	printf("\t\t\t学号:%s\n",q->num);
    printf("\t\t\t语文成绩:%d\n",q->chinese);
    printf("\t\t\t数学成绩:%d\n",q->math);
    printf("\t\t\t英语成绩:%d\n",q->English);
    break;
    }
    else  q=q->next;
   }
   
    if(q)
    {
    printf("\t\t\t是否继续查询(y or n):");
    scanf(" %c",&m);
    }
    
   if (q==NULL)
   {
   	printf("\t\t\t无此学生\n");
   	system("pause");
   	break;
   }
   
 }
   
    return 3;
}
int IndexOnNumber(stud *p)
{
	if(p==NULL || p->next==NULL)//防止无学生信息 
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 0;
    }
	stud *q=p->next,*a=p->next;
	char n[20],b[20];
	char m = 'y';
	while(m=='y')
	{	
    printf("\t\t\t请输入学号:");
	scanf("%s",b);
    printf("\n");		   
   while(q)
   {
   	
   	if(strcmp(q->num,b)==0)//比较节点中的学号是否一致 
	{ //一致输出信息 
   	printf("\t\t\t姓名:%s\n",q->name);
   	printf("\t\t\t学号:%s\n",q->num);
    printf("\t\t\t语文成绩:%d\n",q->chinese);
    printf("\t\t\t数学成绩:%d\n",q->math);
    printf("\t\t\t英语成绩:%d\n",q->English);
    break;
    }
    
    q=q->next;// 不一致指向下一个节点 
    
    }
    
    if(q)//如果q！=NULL 
    {
    printf("\t\t\t是否继续查询(y or n):");
    scanf(" %c",&m);
    }
    
   if (q==NULL)
   {
   	printf("\t\t\t无此学生\n");
   	system("pause");
   	break;
   }
    
   }
   return 1;
 }
 
int ShowStudent(stud *p) //输出所有学生信息 
{
    if(p==NULL || p->next==NULL)//防止无学生信息 
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 0;
    }
    stud *q=p->next;
    
    while(q!=NULL)//当q！=NULL时输出学生信息 
   {
   	printf("\t\t\t姓名:%s\n",q->name);
   	printf("\t\t\t学号:%s\n",q->num);	
    printf("\t\t\t语文成绩:%d\n",q->chinese);
    printf("\t\t\t数学成绩:%d\n",q->math);
    printf("\t\t\t英语成绩:%d\n",q->English);
    printf("\t\t\t总成绩%d\n\n",q->sum);
    q=q->next;
    }
    
    system("pause");
    return 1;
} 

int Add(stud *p)//添加函数 
 {
 	
	if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 4;
    }
    
    stud *q=p,*a=p,*head[100];
    int i=-1,b,n=0;
    char m='y';
    while(q->next) 
    {
    	n++;
    	q=q->next;
	}
    while(m=='y')
    {
	system("cls");
	q=a;
      printf("\t\t\t您正在添加学生信息...:\n");
      if((head[++i]=(stud *)malloc(sizeof(stud)))==NULL) 
   {
    printf("\t\t\t空间不足建立失败\n");
    exit(0);
   }
     printf("\t\t\t需要插入到第b个数据之后(0<=b<=%d):",n);
	 scanf("%d",&b); 
	 if(b<0 || b>n)
	 {
	  printf("\n\t\t输入错误\n");
	  system("pause");
	  break;
     }
    //插入到第b个数据之后 
	 for(n=1;n<=b;n++)
	 q=q->next;
	 head[i]->next=NULL;
	 printf("\t\t◎请输入学号:");
     scanf("%s",head[i]->num);
     printf("\t\t◎请输入姓名:");
     scanf("%s",head[i]->name);
     printf("\t\t◎请输入语文成绩:");
     scanf("%d",&head[i]->chinese);
     printf("\t\t◎请输入数学成绩:");
     scanf("%d",&head[i]->math);
     printf("\t\t◎请输入英语成绩:");
     scanf("%d",&head[i]->English);
	 head[i]->sum=head[i]->chinese+head[i]->English+head[i]->math;
	 head[i]->next=q->next;
     q->next=head[i];
     printf("\t\t\t输入成功\n");
     printf("\t\t\t是否继续增添(y or n):");
     scanf(" %c",&m);
     
}
        return 1;
}

int Del(stud *p)  //删除函数 
 {
    if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 0;
    }
    stud *q=p->next,*a=p->next,*h=p;//h为q的前一个节点
    
    char m='y',b[20],n[20];
    int j;
	 
    while(m=='y')
    {
    if(p==NULL)
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 0;
    }	
	system("cls");
	q=a;
	h=p;
	
   printf("\t\t 		  您正在删除学生信息 ...  \n");
   printf("\t\t                                      \n");
   printf("\t\t              请选择删除方式          \n");
   printf("\t\t                                      \n");
   printf("\t\t              1.按学号删除            \n");
   printf("\t\t                                      \n");
   printf("\t\t              2.按姓名删除            \n");
   printf("\t\t                                      \n");
   printf("\t\t              0.退出                  \n"); 
   printf("\n");
   printf("\t\t                请输入您的选择:");
   scanf("%d",&j);
	switch(j) 
	{
		
		case 1: 
		       printf("\t\t\t请输入学号:");
			   scanf("%s",b);
			   
			   while(q)
			   {
			   	
			   	if(strcmp(q->num,b)==0)
				{ 
				
                h->next=q->next;//使前一个节点指向后一个 
                free(q);
                printf("\t\t\t删除成功\n");
                system("pause"); 
                break;
			    }
			    
			    h=q;//h为q的前一个节点 
			    q=q->next;
			    
			    }
			    
			    if (q==NULL)
			   {
			   	printf("\t\t\t无此学生\n");
			   	system("pause");
			   	break;
			   }
			   
	            if(q)
		        {
                printf("\t\t\t是否继续删除(y or n):");
                scanf(" %c",&m);
                }
			   break;
			   
	    case 2:	
	           printf("\t\t\t请输入姓名:");
			   scanf("%s",n);
			   
			   while(q)
			 {
			   	if(strcmp(q->name,n)==0)
				{ 
                h->next=q->next;//使前一个节点指向后一个 
                free(q);
                printf("\t\t\t删除成功\n");
                break;
			    }
			    h=q;
			    q=q->next;
			 }
			 
			    if (q==NULL)
			   {
			   	printf("\t\t\t无此学生\n");
			   	system("pause");
			   	break;
			   }
			   
	            if(q)
		        {
                printf("\t\t\t是否继续删除(y or n):");
                scanf(" %c",&m);
                }
                
			   break;
			   
	    case 0:
				m='n';   
	            break;
				 
		default:
				printf("\t\t\t输入错误\n");
				system("pause");
				break;
				
	}
}
    return 1;
}

void  Computer(stud *p)
{
	if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return;
    }
    
    stud *q=p->next;
    int totalnumber=0;
    while(q)
    {
    	totalnumber++;
    	printf("\t\t\t第%d个同学总分为：%d\n",totalnumber,q->sum);
    	printf("\t\t\t          均分为:%.2f\n",(q->sum)/3.0);
    	putchar(10);
    	q=q->next;
	}

	system("pause");
}

char print(stud *d,int n)//输出函数 
{
   char m='y';
   int i;
   for(i=0;i<n;i++)
   { 
    printf("\n\t\t  第%d:",i+1);
    printf("总分为%d:\n",d[i].sum);
    printf("\t\t\t姓名:%s\n",d[i].name);
   	printf("\t\t\t学号:%s\n",d[i].num);
    printf("\t\t\t语文成绩:%d\n",d[i].chinese);
    printf("\t\t\t数学成绩:%d\n",d[i].math);
    printf("\t\t\t英语成绩:%d\n",d[i].English);
    }
    printf("\t\t\t是否继续查看(y or n):");
    scanf(" %c",&m);
    return m;
}

stud* reorder(stud *p,int x)//排序函数 
{                           //将链接换成结构体数组，再排序。 
	  stud temp,*q=p->next;
	  int n=0,i=0,j,k;
	  
	switch(x)
   {
case 1:  //总分排序  
	       while(q)
	       {
	   	   n++;//计算总数 
	  	   l[i++]=*q;//顺序将节点赋给结构体数组元素 
	  	    q=q->next;
	       }
	       for(i=0;i<n-1;i++)
	      {
	       k=i;
	       for(j=i+1;j<n;j++)
	      {
	  	    if(l[k].sum<l[j].sum)
	  	    k=j;
	   	    if(i!=k)
	  	    {
	  	  	temp=l[i];
	  		l[i]=l[k];
	  		l[k]=temp;
		    }
	      }
          }
        
        break;
        
case 2: //语文排序 
              while(q)
	       {
	   	   n++; 
	  	   l[i++]=*q;
	  	    q=q->next;
	       }
	       for(i=0;i<n-1;i++)
	  {
	       k=i;
	       for(j=i+1;j<n;j++)
	    {
	  	    if(l[k].chinese<l[j].chinese)
	  	    k=j;
	   	    if(i!=k)
	  	    {
	  	  	temp=l[i];
	  		l[i]=l[k];
	  		l[k]=temp;
		   }
	    }
      }
       
        break;
        
 case 3:    //数学排序 
          while(q)
	       {
	   	   n++;
	  	   l[i++]=*q;
	  	    q=q->next;
	       }
	       for(i=0;i<n-1;i++)
	 {
	       k=i;
	       for(j=i+1;j<n;j++)
	     {
	  	    if(l[k].math<l[j].math)
	  	    k=j;
	   	    if(i!=k)
	  	    {
	  	  	temp=l[i];
	  		l[i]=l[k];
	  		l[k]=temp;
		   }
	     }
      }
       
        break;
        
case 4://英语排序 
          while(q)
	       {
	   	   n++;
	  	   l[i++]=*q;
	  	    q=q->next;
	       }
	       for(i=0;i<n-1;i++)
	  {
	       k=i;
	       for(j=i+1;j<n;j++)
	    {
	  	    if(l[k].English<l[j].English)
	  	    k=j;
	   	    if(i!=k)
	  	    {
	  	  	temp=l[i];
	  		l[i]=l[k];
	  		l[k]=temp;
		   }
	    }
      }
       
        break;			   
   }
    return (l);
}


int Compare(stud *p) //比较函数 
{
	
	if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t请先输入学生信息\n");
	system("pause");
	return 0;
    }
    
    stud *q=p->next,*a=p->next,*d=NULL;
    char m='y';
    int n=0,f,x;
    while(q)
   {
   n++;//计算总数 
   q=q->next;
   }
  while(m=='y')
  {
  	system("cls");
  
   printf("\t\t 您正在查看学生排名\n");
   printf("\t\t 请选择查看方式\n");
   printf("\t\t 1.查询总分排序\n");
   printf("\t\t 2.查询语文排序\n");
   printf("\t\t 3.查询数学排序\n");
   printf("\t\t 4.查询英语排序\n");
   printf("\t\t 0.退出"); 
   printf("\t\t ********************************************\n");
   
   printf("\t\t                请输入您的选择:");
   scanf("%d",&f);
			   
		switch(f)
		{	
		case 1:	
		      d=reorder(p,x=1) ;//相应的x的值对应相应的排序 
		      m=print(d,n);
			  break;	   
		case 2:
		      d=reorder(p,x=2) ;
		       m=print(d,n);
			  break;	  
		case 3:
		      d=reorder(p,x=3) ;
		       m=print(d,n);
			  break;
		case 4:
		       d=reorder(p,x=4) ;
		       m=print(d,n);
			  break;	  
		case 0:
		      m='n';
			  break;	  
		default:
		       printf("\t\t\t输入错误\n");
			   system("pause");
			   break;
		} 
 }
    return 1;
}
void End()
{
	system("cls"); 
	printf("感谢使用学生管理系统,再见！\n");
	printf("\n");
	system("pause");
}
int circulate()
{
	stud *p=NULL;
	while(1) {
		switch(menu_select()) { 
			case 1:
				p=Creat();
				break;
			case 2:
				Del(p);
				break;	
			case 3:
				Add(p);
				break;		
			case 4:
				ShowStudent(p);
				break;
			case 5:
				Search(p);
				break;	
			case 6:
				Computer(p);
				break;
			case 7:
				Compare(p);
			    break;
			case 8:
				IndexOnNumber(p);
			    break;		
			case 9:
				End();
				return 0;		
			default :
				printf("\t\t\t输入错误请重新输入\n");
				printf("\n");
		        system("pause");
		        break;
		    }
		}
}

