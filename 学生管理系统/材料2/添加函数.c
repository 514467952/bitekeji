int Add(stud *p)//��Ӻ��� 
{
	
	if(p==NULL || p->next==NULL)
	{ 
		printf("\t\t\t��������ѧ����Ϣ\n");
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
		printf("\t\t\t���������ѧ����Ϣ...:\n");
		if((head[++i]=(stud *)malloc(sizeof(stud)))==NULL) 
		{
			printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
			exit(0);
		}
		printf("\t\t\t��Ҫ���뵽��b������֮��(0<=b<=%d):",n);
		scanf("%d",&b);
		printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
		if(b<0 || b>n)
		{
			printf("\n\t\t�������\n");
			system("pause");
			break;
		}
		//���뵽��b������֮�� 
		for(n=1;n<=b;n++)
			q=q->next;
		head[i]->next=NULL;
		printf("\t\t��������ѧ��:");
		scanf("%s",head[i]->num);
		printf("\t\t������������:");
		scanf("%s",head[i]->name);
		printf("\t\t�����������ĳɼ�:");
		scanf("%d",&head[i]->chinese);
		printf("\t\t����������ѧ�ɼ�:");
		scanf("%d",&head[i]->math);
		printf("\t\t��������Ӣ��ɼ�:");
		scanf("%d",&head[i]->English);
		head[i]->sum=head[i]->chinese+head[i]->English+head[i]->math;
		head[i]->next=q->next;
		q->next=head[i];
		printf("\t\t\t����ɹ�\n");
		printf("\t\t\t�Ƿ��������(y or n):");
		scanf(" %c",&m);
		
	}
	return 1;
}