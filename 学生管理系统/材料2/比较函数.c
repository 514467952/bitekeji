
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
		
	 printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
   printf("\t\t %c           您正在查看学生排名        %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             请选择查看方式          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             1.查询总分排序          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             2.查询语文排序          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             3.查询数学排序          %c\n",4,4); 
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             4.查询英语排序          %c\n",4,4); 
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             0.退出                  %c\n",4,4);
   printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
   
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
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c  感谢您使用学生成绩管理系统 %c\n",4,4);
	printf("\t\t\t %c            再见！           %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
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