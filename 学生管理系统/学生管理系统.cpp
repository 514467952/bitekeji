#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

typedef	struct student {
	char num[20];//ѧ�� 
	char name[20];
	int  chinese;
	int  math;
	int  English;
	int  sum;//�ܷ� 
	struct student *next;
} stud;

stud l[50];

int menu_select();//�˵�ѡ���� 
int circulate();//ѭ��ѡ���� 
stud* Creat();//¼��ģ�� 
int ShowStudent(stud *p);//��ʾģ�� 
int Search(stud *p);//��ѯģ�� 
int IndexOnNumber(stud *p);//��ѯģ�� 
stud* reorder(stud *p,int x);//������ 
char print(stud *d,int n);//������� 
void  Computer(stud *p);//ͳ��ģ�� 
void End();//�������� 

int main()
{
	system("color F0");//����ɫ 
    circulate();
    return 0; 
}

int menu_select() {//ѡ���� 
	int c;
	system("cls");
	printf("\n");
	printf("\t\t    ��ӭʹ��ѧ���ɼ�����ϵͳ    \n");
	printf("\t\t                                \n");
	printf("\t\t         1.����ѧ����Ϣ         \n");
	printf("\t\t                                \n");
	printf("\t\t         2.ɾ��ѧ����Ϣ         \n");
	printf("\t\t                                \n");
	printf("\t\t         3.����ѧ����Ϣ         \n");
	printf("\t\t                                \n");
	printf("\t\t         4.��ʾ����ѧ����Ϣ     \n");
	printf("\t\t                                \n");
	printf("\t\t         5.������������ѧ����Ϣ \n");
	printf("\t\t                                \n");
	printf("\t\t         6.�����ֺܷ�ƽ����     \n");
	printf("\t\t                                \n");
	printf("\t\t         7.ѧ���ɼ�����         \n");
	printf("\t\t                                \n");
	printf("\t\t         8.����ѧ�Ų���ѧ����Ϣ \n");
	printf("\t\t                                \n");
	printf("\t\t         9.�˳�ϵͳ             \n");
	printf("\n");
	printf("\t\t   (����������0~9): ");
    
	scanf("%d",&c);
	return(c);
}

stud* Creat() //�������� 
{
	system("cls");
	printf("\t\t              HELLO������������ѧ����Ϣ...     \n\n");
	printf("\t\t              �������ʾ����ѧ����Ϣ:      \n\n");
	int i,j;
	stud *head,*p1,*p2;
	printf("\t\t\t  ������������:");
	scanf("%d",&i);
	if(i<=0)
	{
	 printf("\t\t\t�������������\n"); 
	 system("pause");//��ͣ��Ļ 
	 
   }
   
	if((head=(stud *)malloc(sizeof(stud)))==NULL)//����ͷָ�� 
	{
		printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
		exit(0);
	}
	head->next=NULL;
	p1=head;
	
	for(j=0;j<i;j++)
	{
    	if((p2=(stud *)malloc(sizeof(stud)))==NULL)//�����µĽڵ� 
	{	
		printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
		exit(0);
	}
	//����ѧ����Ϣ 
   printf("\t\t�����������%d���˵���Ϣ\n",j+1); 
   printf("\t\t ��������ѧ��:");
   scanf("%s",p2->num);
   printf("\t\t ������������:");
   scanf("%s",p2->name);
   printf("\t\t �����������ĳɼ�:");
   scanf("%d",&p2->chinese);
   printf("\t\t ����������ѧ�ɼ�:");
   scanf("%d",&p2->math);
   printf("\t\t ��������Ӣ��ɼ�:");
   scanf("%d",&p2->English);
   p2->sum=p2->chinese+p2->English+p2->math;
   //ʹ��һ���ڵ�ָ����һ���ڵ� 
   p1->next=p2;
   p2->next=NULL;//ʹ���ڵ�nextΪ�� 
   p1=p2;
   
   if(i>=3 && (j+1)%2==0) system("cls"); 
   
	}
	printf("\t\t�ѳɹ�����ѧ����Ϣ\n");
	system("pause");
	return (head);//����ͷָ�� 
}

int Search(stud *p) //��ѯ���� 
{ //��ͷָ����� 
	if(p==NULL || p->next==NULL)//��ֹ��ѧ����Ϣ 
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return 0;
    }
    stud *q=p->next,*a=p->next;
	char n[20],b[20];
	char m = 'y';
    while(m == 'y')//��m=��y��ʱѭ�� 
   {
	q=a;//ÿ��ѭ������ָ��q 
	system("cls");
    printf("\t\t\t����������:");
    scanf("%s",b);
    printf("\n");
    while(q)
   {
   	if(strcmp(q->name,b)==0)//�ȽϽڵ��е������Ƿ�һ��
	{ 
   	printf("\t\t\t����:%s\n",q->name);
   	printf("\t\t\tѧ��:%s\n",q->num);
    printf("\t\t\t���ĳɼ�:%d\n",q->chinese);
    printf("\t\t\t��ѧ�ɼ�:%d\n",q->math);
    printf("\t\t\tӢ��ɼ�:%d\n",q->English);
    break;
    }
    else  q=q->next;
   }
   
    if(q)
    {
    printf("\t\t\t�Ƿ������ѯ(y or n):");
    scanf(" %c",&m);
    }
    
   if (q==NULL)
   {
   	printf("\t\t\t�޴�ѧ��\n");
   	system("pause");
   	break;
   }
   
 }
   
    return 3;
}
int IndexOnNumber(stud *p)
{
	if(p==NULL || p->next==NULL)//��ֹ��ѧ����Ϣ 
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return 0;
    }
	stud *q=p->next,*a=p->next;
	char n[20],b[20];
	char m = 'y';
	while(m=='y')
	{	
    printf("\t\t\t������ѧ��:");
	scanf("%s",b);
    printf("\n");		   
   while(q)
   {
   	
   	if(strcmp(q->num,b)==0)//�ȽϽڵ��е�ѧ���Ƿ�һ�� 
	{ //һ�������Ϣ 
   	printf("\t\t\t����:%s\n",q->name);
   	printf("\t\t\tѧ��:%s\n",q->num);
    printf("\t\t\t���ĳɼ�:%d\n",q->chinese);
    printf("\t\t\t��ѧ�ɼ�:%d\n",q->math);
    printf("\t\t\tӢ��ɼ�:%d\n",q->English);
    break;
    }
    
    q=q->next;// ��һ��ָ����һ���ڵ� 
    
    }
    
    if(q)//���q��=NULL 
    {
    printf("\t\t\t�Ƿ������ѯ(y or n):");
    scanf(" %c",&m);
    }
    
   if (q==NULL)
   {
   	printf("\t\t\t�޴�ѧ��\n");
   	system("pause");
   	break;
   }
    
   }
   return 1;
 }
 
int ShowStudent(stud *p) //�������ѧ����Ϣ 
{
    if(p==NULL || p->next==NULL)//��ֹ��ѧ����Ϣ 
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return 0;
    }
    stud *q=p->next;
    
    while(q!=NULL)//��q��=NULLʱ���ѧ����Ϣ 
   {
   	printf("\t\t\t����:%s\n",q->name);
   	printf("\t\t\tѧ��:%s\n",q->num);	
    printf("\t\t\t���ĳɼ�:%d\n",q->chinese);
    printf("\t\t\t��ѧ�ɼ�:%d\n",q->math);
    printf("\t\t\tӢ��ɼ�:%d\n",q->English);
    printf("\t\t\t�ܳɼ�%d\n\n",q->sum);
    q=q->next;
    }
    
    system("pause");
    return 1;
} 

int Add(stud *p)//��Ӻ��� 
 {
 	
	if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return 4;
    }
    
    stud *q=p,*a=p,*head[100];
    int i=-1,b,n=0;
    char m='y';
    while(q->next) 
    {
    	n++;
    	q=q->next;
	}
    while(m=='y')
    {
	system("cls");
	q=a;
      printf("\t\t\t���������ѧ����Ϣ...:\n");
      if((head[++i]=(stud *)malloc(sizeof(stud)))==NULL) 
   {
    printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
    exit(0);
   }
     printf("\t\t\t��Ҫ���뵽��b������֮��(0<=b<=%d):",n);
	 scanf("%d",&b); 
	 if(b<0 || b>n)
	 {
	  printf("\n\t\t�������\n");
	  system("pause");
	  break;
     }
    //���뵽��b������֮�� 
	 for(n=1;n<=b;n++)
	 q=q->next;
	 head[i]->next=NULL;
	 printf("\t\t��������ѧ��:");
     scanf("%s",head[i]->num);
     printf("\t\t������������:");
     scanf("%s",head[i]->name);
     printf("\t\t�����������ĳɼ�:");
     scanf("%d",&head[i]->chinese);
     printf("\t\t����������ѧ�ɼ�:");
     scanf("%d",&head[i]->math);
     printf("\t\t��������Ӣ��ɼ�:");
     scanf("%d",&head[i]->English);
	 head[i]->sum=head[i]->chinese+head[i]->English+head[i]->math;
	 head[i]->next=q->next;
     q->next=head[i];
     printf("\t\t\t����ɹ�\n");
     printf("\t\t\t�Ƿ��������(y or n):");
     scanf(" %c",&m);
     
}
        return 1;
}

int Del(stud *p)  //ɾ������ 
 {
    if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return 0;
    }
    stud *q=p->next,*a=p->next,*h=p;//hΪq��ǰһ���ڵ�
    
    char m='y',b[20],n[20];
    int j;
	 
    while(m=='y')
    {
    if(p==NULL)
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return 0;
    }	
	system("cls");
	q=a;
	h=p;
	
   printf("\t\t 		  ������ɾ��ѧ����Ϣ ...  \n");
   printf("\t\t                                      \n");
   printf("\t\t              ��ѡ��ɾ����ʽ          \n");
   printf("\t\t                                      \n");
   printf("\t\t              1.��ѧ��ɾ��            \n");
   printf("\t\t                                      \n");
   printf("\t\t              2.������ɾ��            \n");
   printf("\t\t                                      \n");
   printf("\t\t              0.�˳�                  \n"); 
   printf("\n");
   printf("\t\t                ����������ѡ��:");
   scanf("%d",&j);
	switch(j) 
	{
		
		case 1: 
		       printf("\t\t\t������ѧ��:");
			   scanf("%s",b);
			   
			   while(q)
			   {
			   	
			   	if(strcmp(q->num,b)==0)
				{ 
				
                h->next=q->next;//ʹǰһ���ڵ�ָ���һ�� 
                free(q);
                printf("\t\t\tɾ���ɹ�\n");
                system("pause"); 
                break;
			    }
			    
			    h=q;//hΪq��ǰһ���ڵ� 
			    q=q->next;
			    
			    }
			    
			    if (q==NULL)
			   {
			   	printf("\t\t\t�޴�ѧ��\n");
			   	system("pause");
			   	break;
			   }
			   
	            if(q)
		        {
                printf("\t\t\t�Ƿ����ɾ��(y or n):");
                scanf(" %c",&m);
                }
			   break;
			   
	    case 2:	
	           printf("\t\t\t����������:");
			   scanf("%s",n);
			   
			   while(q)
			 {
			   	if(strcmp(q->name,n)==0)
				{ 
                h->next=q->next;//ʹǰһ���ڵ�ָ���һ�� 
                free(q);
                printf("\t\t\tɾ���ɹ�\n");
                break;
			    }
			    h=q;
			    q=q->next;
			 }
			 
			    if (q==NULL)
			   {
			   	printf("\t\t\t�޴�ѧ��\n");
			   	system("pause");
			   	break;
			   }
			   
	            if(q)
		        {
                printf("\t\t\t�Ƿ����ɾ��(y or n):");
                scanf(" %c",&m);
                }
                
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

void  Computer(stud *p)
{
	if(p==NULL || p->next==NULL)
	{ 
    printf("\t\t\t��������ѧ����Ϣ\n");
	system("pause");
	return;
    }
    
    stud *q=p->next;
    int totalnumber=0;
    while(q)
    {
    	totalnumber++;
    	printf("\t\t\t��%d��ͬѧ�ܷ�Ϊ��%d\n",totalnumber,q->sum);
    	printf("\t\t\t          ����Ϊ:%.2f\n",(q->sum)/3.0);
    	putchar(10);
    	q=q->next;
	}

	system("pause");
}

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
  
   printf("\t\t �����ڲ鿴ѧ������\n");
   printf("\t\t ��ѡ��鿴��ʽ\n");
   printf("\t\t 1.��ѯ�ܷ�����\n");
   printf("\t\t 2.��ѯ��������\n");
   printf("\t\t 3.��ѯ��ѧ����\n");
   printf("\t\t 4.��ѯӢ������\n");
   printf("\t\t 0.�˳�"); 
   printf("\t\t ********************************************\n");
   
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
	printf("��лʹ��ѧ������ϵͳ,�ټ���\n");
	printf("\n");
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

