
int Compare(stud *p) //�ȽϺ��� 
{
	
	if(p==NULL || p->next==NULL)
	{ 
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return 0;
    }
    
    stud *q=p->next,*a=p->next,*d=NULL;
    char m='y';
    int n=0,f,x;
    while(q)
	{
		n++;//�������� 
		q=q->next;
	}
	while(m=='y')
	{
		system("cls");
		
	 printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
   printf("\t\t %c           �����ڲ鿴ѧ������        %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             ��ѡ��鿴��ʽ          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             1.��ѯ�ܷ�����          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             2.��ѯ��������          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             3.��ѯ��ѧ����          %c\n",4,4); 
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             4.��ѯӢ������          %c\n",4,4); 
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             0.�˳�                  %c\n",4,4);
   printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
   
		printf("\t\t                ����������ѡ��:");
		scanf("%d",&f);
		
		switch(f)
		{	
		case 1:	
			d=reorder(p,x=1) ;//��Ӧ��x��ֵ��Ӧ��Ӧ������ 
			m=print(d,n);
			break;	   
		case 2:
			d=reorder(p,x=2) ;
			m=print(d,n);
			break;	  
		case 3:
			d=reorder(p,x=3) ;
			m=print(d,n);
			break;
		case 4:
			d=reorder(p,x=4) ;
			m=print(d,n);
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
void End()
{
	system("cls"); 
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c  ��л��ʹ��ѧ���ɼ�����ϵͳ %c\n",4,4);
	printf("\t\t\t %c            �ټ���           %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c                             %c\n",4,4);
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	system("pause");
}
int circulate()
{
	stud *p=NULL;
	while(1) {
		switch(menu_select()) { 
		case 1:
			p=Creat();
			break;
		case 2:
			Del(p);
			break;	
		case 3:
			Add(p);
			break;		
		case 4:
			ShowStudent(p);
			break;
		case 5:
			Search(p);
			break;	
		case 6:
			Computer(p);
			break;
		case 7:
			Compare(p);
			break;
		case 8:
			IndexOnNumber(p);
			break;		
		case 9:
			End();
			return 0;		
		default :
			printf("\t\t\t�����������������\n");
			printf("\n");
			system("pause");
			break;
		}
	}
}