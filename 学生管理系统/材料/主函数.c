int  main(void){                /*主菜单*/
	int n;
	menu();
	scanf("%d",&n);              /*输入选择功能编号        */
	while(n)
	{
		switch(n)
		{
		case 1:in();break;
		case 2:search();break;
		case 3:del();break;
		case 4:modify();break;
		case 5:insert();break;
		case 6:order();break;
		case 7:total():break;
		case 8:show():break;
		default: break;
		}
		getch();
		menu();                    /*执行完功能再次显示菜单页面           */
		scanf("%d",&n);
	}

}
