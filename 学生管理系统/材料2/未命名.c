int IndexOnNumber(stud *p)
{
	if(p==NULL || p->next==NULL)//��ֹ��ѧ����Ϣ 
	{ 
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return 0;
    }
	stud *q=p->next,*a=p->next;
	char n[20],b[20];
	char m = 'y';
	while(m=='y')
	{	
		printf("\t\t\t������ѧ��:");
		scanf("%s",b);
		printf("\n");		   
		while(q)
		{
			
			if(strcmp(q->num,b)==0)//�ȽϽڵ��е�ѧ���Ƿ�һ�� 
			{ //һ�������Ϣ 
				printf("\t\t\t����:%s\n",q->name);
				printf("\t\t\tѧ��:%s\n",q->num);
				printf("\t\t\t���ĳɼ�:%d\n",q->chinese);
				printf("\t\t\t��ѧ�ɼ�:%d\n",q->math);
				printf("\t\t\tӢ��ɼ�:%d\n",q->English);
				break;
			}
			
			q=q->next;// ��һ��ָ����һ���ڵ� 
			
		}
		
		if(q)//���q��=NULL 
		{
			printf("\t\t\t�Ƿ������ѯ(y or n):");
			scanf(" %c",&m);
		}
		
		if (q==NULL)
		{
			printf("\t\t\t�޴�ѧ��\n");
			system("pause");
			break;
		}
		
	}
	return 1;
}