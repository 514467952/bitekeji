int Del(stud *p)  //删除函数 
{
    if(p==NULL || p->next==NULL)
	{ 
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return 0;
    }
    stud *q=p->next,*a=p->next,*h=p;//h为q的前一个节点
    
    char m='y',b[20],n[20];
    int j;
	
    while(m=='y')
    {
		if(p==NULL)
		{ 
			printf("\t\t\t请先输入学生信息\n");
			system("pause");
			return 0;
		}	
		system("cls");
		q=a;
		h=p;
		
		 printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
   printf("\t\t %c           您正在删除学生信息        %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             请选择删除方式          %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             1.按学号删除            %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             2.按姓名删除            %c\n",4,4);
   printf("\t\t %c                                     %c\n",4,4);
   printf("\t\t %c             0.退出                  %c\n",4,4); 
   printf("\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
		printf("\t\t             %c 请输入您的选择:",3);
		scanf("%d",&j);
		printf("\n");
		switch(j) 
		{
			
		case 1: 
			printf("\t\t\t请输入学号:");
			scanf("%s",b);
			
			while(q)
			{
				
				if(strcmp(q->num,b)==0)
				{ 
					
					h->next=q->next;//使前一个节点指向后一个 
					free(q);
					printf("\t\t\t删除成功\n");
					system("pause"); 
					break;
				}
				
				h=q;//h为q的前一个节点 
				q=q->next;
				
			}
			
			if (q==NULL)
			{
				printf("\t\t\t无此学生\n");
				system("pause");
				break;
			}
			
			if(q)
			{
                printf("\t\t\t是否继续删除(y or n):");
                scanf(" %c",&m);
			}
			break;
			
		case 2:	
	           printf("\t\t\t请输入姓名:");
			   scanf("%s",n);
			   
			   while(q)
			   {
				   if(strcmp(q->name,n)==0)
				   { 
					   h->next=q->next;//使前一个节点指向后一个 
					   free(q);
					   printf("\t\t\t删除成功\n");
					   break;
				   }
				   h=q;
				   q=q->next;
			   }
			   
			   if (q==NULL)
			   {
				   printf("\t\t\t无此学生\n");
				   system("pause");
				   break;
			   }
			   
			   if(q)
			   {
				   printf("\t\t\t是否继续删除(y or n):");
				   scanf(" %c",&m);
			   }
			   
			   break;
			   
		case 0:
			m='n';   
			break;
			
		default:
			printf("\t\t\t输入错误\n");
			system("pause");
			break;
			
		}
}
return 1;
}