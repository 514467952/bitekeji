
char print(stud *d,int n)//������� 
{
	char m='y';
	int i;
	for(i=0;i<n;i++)
	{ 
		printf("\n\t\t  ��%d:",i+1);
		printf("�ܷ�Ϊ%d:\n",d[i].sum);
		printf("\t\t\t����:%s\n",d[i].name);
		printf("\t\t\tѧ��:%s\n",d[i].num);
		printf("\t\t\t���ĳɼ�:%d\n",d[i].chinese);
		printf("\t\t\t��ѧ�ɼ�:%d\n",d[i].math);
		printf("\t\t\tӢ��ɼ�:%d\n",d[i].English);
    }
    printf("\t\t\t�Ƿ�����鿴(y or n):");
    scanf(" %c",&m);
    return m;
}

stud* reorder(stud *p,int x)//������ 
{                           //�����ӻ��ɽṹ�����飬������ 
	stud temp,*q=p->next;
	int n=0,i=0,j,k;
	
	switch(x)
	{
	case 1:  //�ܷ�����  
	       while(q)
		   {
			   n++;//�������� 
			   l[i++]=*q;//˳�򽫽ڵ㸳���ṹ������Ԫ�� 
			   q=q->next;
		   }
		   for(i=0;i<n-1;i++)
		   {
			   k=i;
			   for(j=i+1;j<n;j++)
			   {
				   if(l[k].sum<l[j].sum)
					   k=j;
				   if(i!=k)
				   {
					   temp=l[i];
					   l[i]=l[k];
					   l[k]=temp;
				   }
			   }
		   }
		   
		   break;
		   
	case 2: //�������� 
		while(q)
	       {
			n++; 
			l[i++]=*q;
			q=q->next;
	       }
	       for(i=0;i<n-1;i++)
		   {
			   k=i;
			   for(j=i+1;j<n;j++)
			   {
				   if(l[k].chinese<l[j].chinese)
					   k=j;
				   if(i!=k)
				   {
					   temp=l[i];
					   l[i]=l[k];
					   l[k]=temp;
				   }
			   }
		   }
		   
		   break;
		   
	case 3:    //��ѧ���� 
		while(q)
	       {
			n++;
			l[i++]=*q;
			q=q->next;
	       }
	       for(i=0;i<n-1;i++)
		   {
			   k=i;
			   for(j=i+1;j<n;j++)
			   {
				   if(l[k].math<l[j].math)
					   k=j;
				   if(i!=k)
				   {
					   temp=l[i];
					   l[i]=l[k];
					   l[k]=temp;
				   }
			   }
		   }
		   
		   break;
		   
	case 4://Ӣ������ 
		while(q)
	       {
			n++;
			l[i++]=*q;
			q=q->next;
	       }
	       for(i=0;i<n-1;i++)
		   {
			   k=i;
			   for(j=i+1;j<n;j++)
			   {
				   if(l[k].English<l[j].English)
					   k=j;
				   if(i!=k)
				   {
					   temp=l[i];
					   l[i]=l[k];
					   l[k]=temp;
				   }
			   }
		   }
		   
		   break;			   
	}
    return (l);
}
