stud* Creat() //�������� 
{
	system("cls");
	printf("\t\t              HELLO������������ѧ����Ϣ...     \n\n");
	printf("\t\t              �������ʾ����ѧ����Ϣ:      \n\n");
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	int i,j;
	stud *head,*p1,*p2;
	printf("\t\t\t  ������������:");
	scanf("%d",&i);
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	if(i<=0)
	{
		printf("\t\t\t�������������\n"); 
		system("pause");//��ͣ��Ļ 
		
	}
	
	if((head=(stud *)malloc(sizeof(stud)))==NULL)//����ͷָ�� 
	{
		printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
		exit(0);
	}
	head->next=NULL;
	p1=head;
	
	for(j=0;j<i;j++)
	{
		if((p2=(stud *)malloc(sizeof(stud)))==NULL)//�����µĽڵ� 
		{	
			printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
			exit(0);
		}
		//����ѧ����Ϣ 
		printf("\t\t\t�����������%d���˵���Ϣ\n",j+1); 
		printf("\t\t\t\t ��������ѧ��:");
		scanf("%s",p2->num);
		printf("\t\t\t\t ������������:");
		scanf("%s",p2->name);
		printf("\t\t\t\t �����������ĳɼ�:");
		scanf("%d",&p2->chinese);
		printf("\t\t\t\t ����������ѧ�ɼ�:");
		scanf("%d",&p2->math);
		printf("\t\t\t\t ��������Ӣ��ɼ�:");
		scanf("%d",&p2->English);
		p2->sum=p2->chinese+p2->English+p2->math;
		//ʹ��һ���ڵ�ָ����һ���ڵ� 
		p1->next=p2;
		p2->next=NULL;//ʹ���ڵ�nextΪ�� 
		p1=p2;
		
		if(i>=3 && (j+1)%2==0) system("cls"); 
		
	}
	printf("\t\t\t�ѳɹ�����ѧ����Ϣ\n");
	system("pause");
	return (head);//����ͷָ�� 
}