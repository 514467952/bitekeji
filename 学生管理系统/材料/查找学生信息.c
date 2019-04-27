void search()                                        /*自定义查找函数          */
{
	FILE *fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen("data.txt","rb"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1) m++;
		   fclose(fp);
		if(m==0)
		{
			printf("no record!\n");
			return;
		}
		printf("please input the number:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)                 /*  查找输入的学号是否在记录中            */
			{
				printf("find the student,show?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"y")==0||strcmp(ch,"y")==0)
				{
					printf("number name elective exeperiment required sum\t\n");
					printf(FORMAT,DATA);           /* 讲查找的结果按指定格式输出            */
					break;
				}
			}
			if(i=m)
				printf("can not find the student!\n");       /* 未找到要查找信息           */


}