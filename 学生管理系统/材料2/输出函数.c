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