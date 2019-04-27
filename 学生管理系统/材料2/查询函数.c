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