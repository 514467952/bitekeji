void in()          /*   输入学生成绩    */
{
	int i,m=0;              /* m 是记录的条数    */
	char ch[2];
	FILE *fp;                  /* 定义文件指针           */
	if((fp=fopen("data.txt","a+"))==NULL)         /* 打开指定文件      */
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
		 m++;                       /* 统计当前记录条数     */ 
	}
	fclose(fp);
	if(m==0)
	printf("NO record!\n");
	else
	{
		system("cls");
		show();                                 /*调用show函数，显示原有信息     */
	}
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("can not open\n");
		return;
		
	}
	for(i=0;i<m;i++)
	    fwrite(&stu[i],LEN,1,fp);             /*  向指定的磁盘文件写入信息         */
	printf("please input (y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)     /*  判断是否要输入新信息     */
	{
		printf("number:");
		scanf("%d",&stu[m].num);             /* 输入学生学号     */ 
		for(i=0;i<m;i++)
		if(stu[i].num==stu[m].num)
		{
			printf("the number is existing,press any to continue!");
			getch();
			fclose(fp);
			return;
			
		}
		printf("name:");
		scanf("%s",stu[m].name)         /* 输入学生姓名 */
        printf("elective:");
		scanf("%lf",stu[m].elec);        /*输入选修课成绩  */	
		printf("exeperiment:");
		scanf("%lf",stu[m].expe);       /* 输入实验课成绩 */
		printf("required course:");
		scanf("%lf",&stu[m].requ);      /* 输入必修课成绩 */
		stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;    /*计算总成绩    */
		if(fwrite(&stu[m],LEN,1,fp)!=1)            /* 讲新输入的信息写入指定的磁盘文件*/
		{
			printf("can not save");
			getch();
			}	
		else
		{
			printf("%s saved!\n,stu[m].name");
			m++;
		
		}
		
		printf("continue?(y/n):");      /*  询问是否要继续            */
		scanf("%s",ch);
				
	}
	flcose(fp);
	printf("OK!\n");
}
