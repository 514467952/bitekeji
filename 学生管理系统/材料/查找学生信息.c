void search()                                        /*�Զ�����Һ���          */
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
			if(snum==stu[i].num)                 /*  ���������ѧ���Ƿ��ڼ�¼��            */
			{
				printf("find the student,show?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"y")==0||strcmp(ch,"y")==0)
				{
					printf("number name elective exeperiment required sum\t\n");
					printf(FORMAT,DATA);           /* �����ҵĽ����ָ����ʽ���            */
					break;
				}
			}
			if(i=m)
				printf("can not find the student!\n");       /* δ�ҵ�Ҫ������Ϣ           */


}