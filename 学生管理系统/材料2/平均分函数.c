void  Computer(stud *p)
{
	if(p==NULL || p->next==NULL)
	{ 
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
    }
    
    stud *q=p->next;
    int totalnumber=0;
    while(q)
    {
		totalnumber++;
		printf("\t\t\t��%d��ͬѧ���ܷ�Ϊ��%d\n",totalnumber,q->sum);
		printf("\t\t\t         ƽ����Ϊ��%.2f\n",(q->sum)/3.0);
		putchar(10);
		q=q->next;
	}
	
	system("pause");
}