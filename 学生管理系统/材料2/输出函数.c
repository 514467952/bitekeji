int ShowStudent(stud *p) //�������ѧ����Ϣ 
{
    if(p==NULL || p->next==NULL)//��ֹ��ѧ����Ϣ 
	{ 
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return 0;
    }
    stud *q=p->next;
    
    while(q!=NULL)//��q��=NULLʱ���ѧ����Ϣ 
	{
		printf("\t\t\t����:%s\n",q->name);
		printf("\t\t\tѧ��:%s\n",q->num);	
		printf("\t\t\t���ĳɼ�:%d\n",q->chinese);
		printf("\t\t\t��ѧ�ɼ�:%d\n",q->math);
		printf("\t\t\tӢ��ɼ�:%d\n",q->English);
		printf("\t\t\t�ܳɼ�%d\n\n",q->sum);
		q=q->next;
    }
    
    system("pause");
    return 1;
} 