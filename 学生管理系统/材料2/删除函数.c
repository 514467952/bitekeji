int Del(stud *p)  //ɾ������ 
{
    if(p==NULL || p->next==NULL)
	{ 
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return 0;
    }
    stud *q=p->next,*a=p->next,*h=p;//hΪq��ǰһ���ڵ�
    
    char m='y',b[20],n[20];
    int j;
	
    while(m=='y')
    {
		if(p==NULL)
		{ 
			printf("\t\t\t��������ѧ����Ϣ\n");
			system("pause");
			return 0;
		}	
		system("cls");
		q=a;
		h=p;
		
		 printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
   printf("\t\t %c           ������ɾ��ѧ����Ϣ        %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             ��ѡ��ɾ����ʽ          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             1.��ѧ��ɾ��            %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             2.������ɾ��            %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             0.�˳�                  %c\n",4,4); 
   printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
		printf("\t\t             %c ����������ѡ��:",3);
		scanf("%d",&j);
		printf("\n");
		switch(j) 
		{
			
		case 1: 
			printf("\t\t\t������ѧ��:");
			scanf("%s",b);
			
			while(q)
			{
				
				if(strcmp(q->num,b)==0)
				{ 
					
					h->next=q->next;//ʹǰһ���ڵ�ָ���һ�� 
					free(q);
					printf("\t\t\tɾ���ɹ�\n");
					system("pause"); 
					break;
				}
				
				h=q;//hΪq��ǰһ���ڵ� 
				q=q->next;
				
			}
			
			if (q==NULL)
			{
				printf("\t\t\t�޴�ѧ��\n");
				system("pause");
				break;
			}
			
			if(q)
			{
                printf("\t\t\t�Ƿ����ɾ��(y or n):");
                scanf(" %c",&m);
			}
			break;
			
		case 2:	
	           printf("\t\t\t����������:");
			   scanf("%s",n);
			   
			   while(q)
			   {
				   if(strcmp(q->name,n)==0)
				   { 
					   h->next=q->next;//ʹǰһ���ڵ�ָ���һ�� 
					   free(q);
					   printf("\t\t\tɾ���ɹ�\n");
					   break;
				   }
				   h=q;
				   q=q->next;
			   }
			   
			   if (q==NULL)
			   {
				   printf("\t\t\t�޴�ѧ��\n");
				   system("pause");
				   break;
			   }
			   
			   if(q)
			   {
				   printf("\t\t\t�Ƿ����ɾ��(y or n):");
				   scanf(" %c",&m);
			   }
			   
			   break;
			   
		case 0:
			m='n';   
			break;
			
		default:
			printf("\t\t\t�������\n");
			system("pause");
			break;
			
		}
}
return 1;
}