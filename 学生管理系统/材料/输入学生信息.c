void in()          /*   ����ѧ���ɼ�    */
{
	int i,m=0;              /* m �Ǽ�¼������    */
	char ch[2];
	FILE *fp;                  /* �����ļ�ָ��           */
	if((fp=fopen("data.txt","a+"))==NULL)         /* ��ָ���ļ�      */
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
		 m++;                       /* ͳ�Ƶ�ǰ��¼����     */ 
	}
	fclose(fp);
	if(m==0)
	printf("NO record!\n");
	else
	{
		system("cls");
		show();                                 /*����show��������ʾԭ����Ϣ     */
	}
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("can not open\n");
		return;
		
	}
	for(i=0;i<m;i++)
	    fwrite(&stu[i],LEN,1,fp);             /*  ��ָ���Ĵ����ļ�д����Ϣ         */
	printf("please input (y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)     /*  �ж��Ƿ�Ҫ��������Ϣ     */
	{
		printf("number:");
		scanf("%d",&stu[m].num);             /* ����ѧ��ѧ��     */ 
		for(i=0;i<m;i++)
		if(stu[i].num==stu[m].num)
		{
			printf("the number is existing,press any to continue!");
			getch();
			fclose(fp);
			return;
			
		}
		printf("name:");
		scanf("%s",stu[m].name)         /* ����ѧ������ */
        printf("elective:");
		scanf("%lf",stu[m].elec);        /*����ѡ�޿γɼ�  */	
		printf("exeperiment:");
		scanf("%lf",stu[m].expe);       /* ����ʵ��γɼ� */
		printf("required course:");
		scanf("%lf",&stu[m].requ);      /* ������޿γɼ� */
		stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;    /*�����ܳɼ�    */
		if(fwrite(&stu[m],LEN,1,fp)!=1)            /* �����������Ϣд��ָ���Ĵ����ļ�*/
		{
			printf("can not save");
			getch();
			}	
		else
		{
			printf("%s saved!\n,stu[m].name");
			m++;
		
		}
		
		printf("continue?(y/n):");      /*  ѯ���Ƿ�Ҫ����            */
		scanf("%s",ch);
				
	}
	flcose(fp);
	printf("OK!\n");
}
