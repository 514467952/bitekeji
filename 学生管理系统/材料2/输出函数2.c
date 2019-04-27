
char print(stud *d,int n)//输出函数 
{
	char m='y';
	int i;
	for(i=0;i<n;i++)
	{ 
		printf("\n\t\t  第%d:",i+1);
		printf("总分为%d:\n",d[i].sum);
		printf("\t\t\t姓名:%s\n",d[i].name);
		printf("\t\t\t学号:%s\n",d[i].num);
		printf("\t\t\t语文成绩:%d\n",d[i].chinese);
		printf("\t\t\t数学成绩:%d\n",d[i].math);
		printf("\t\t\t英语成绩:%d\n",d[i].English);
    }
    printf("\t\t\t是否继续查看(y or n):");
    scanf(" %c",&m);
    return m;
}

stud* reorder(stud *p,int x)//排序函数 
{                           //将链接换成结构体数组，再排序。 
	stud temp,*q=p->next;
	int n=0,i=0,j,k;
	
	switch(x)
	{
	case 1:  //总分排序  
	       while(q)
		   {
			   n++;//计算总数 
			   l[i++]=*q;//顺序将节点赋给结构体数组元素 
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
		   
	case 2: //语文排序 
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
		   
	case 3:    //数学排序 
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
		   
	case 4://英语排序 
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
