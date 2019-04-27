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
		printf("\t\t\t第%d个同学的总分为：%d\n",totalnumber,q->sum);
		printf("\t\t\t         平均分为：%.2f\n",(q->sum)/3.0);
		putchar(10);
		q=q->next;
	}
	
	system("pause");
}