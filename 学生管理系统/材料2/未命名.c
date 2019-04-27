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