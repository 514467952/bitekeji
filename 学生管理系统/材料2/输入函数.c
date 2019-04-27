stud* Creat() //创建函数 
{
	system("cls");
	printf("\t\t              HELLO，您正在输入学生信息...     \n\n");
	printf("\t\t              请根据提示输入学生信息:      \n\n");
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	int i,j;
	stud *head,*p1,*p2;
	printf("\t\t\t  ◎请输入总数:");
	scanf("%d",&i);
	printf("\t\t\t %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
	if(i<=0)
	{
		printf("\t\t\t输入错误请重试\n"); 
		system("pause");//暂停屏幕 
		
	}
	
	if((head=(stud *)malloc(sizeof(stud)))==NULL)//创建头指针 
	{
		printf("\t\t\t空间不足建立失败\n");
		exit(0);
	}
	head->next=NULL;
	p1=head;
	
	for(j=0;j<i;j++)
	{
		if((p2=(stud *)malloc(sizeof(stud)))==NULL)//创建新的节点 
		{	
			printf("\t\t\t空间不足建立失败\n");
			exit(0);
		}
		//输入学生信息 
		printf("\t\t\t您正在输入第%d个人的信息\n",j+1); 
		printf("\t\t\t\t ◎请输入学号:");
		scanf("%s",p2->num);
		printf("\t\t\t\t ◎请输入姓名:");
		scanf("%s",p2->name);
		printf("\t\t\t\t ◎请输入语文成绩:");
		scanf("%d",&p2->chinese);
		printf("\t\t\t\t ◎请输入数学成绩:");
		scanf("%d",&p2->math);
		printf("\t\t\t\t ◎请输入英语成绩:");
		scanf("%d",&p2->English);
		p2->sum=p2->chinese+p2->English+p2->math;
		//使上一个节点指向下一个节点 
		p1->next=p2;
		p2->next=NULL;//使最后节点next为空 
		p1=p2;
		
		if(i>=3 && (j+1)%2==0) system("cls"); 
		
	}
	printf("\t\t\t已成功输入学生信息\n");
	system("pause");
	return (head);//返回头指针 
}