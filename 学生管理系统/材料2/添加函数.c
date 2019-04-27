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
		printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
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