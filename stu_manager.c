#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct student
{
	char name[10];
	int score;
	int number;
	int age;
};
struct LNode
{
	struct student data;
	struct LNode *next;
};
typedef struct LNode LinkList;


void meum();
void choice(int *stop,LinkList *L);
void creat_node(LinkList *L);
void show_student(LinkList *L);
void delete_student(LinkList *L);
void modify_student(LinkList *L);
void save(LinkList *L);
void refresh(LinkList *L);

void main()
{
	int i;
	LinkList *L=NULL;
	L=(LinkList *)malloc(sizeof(LinkList));
	if(L==NULL)
	{
		printf("分配头节点内存出错!");
		exit(1);
	}
	memset(L,0,sizeof(LinkList));
	L->next=NULL;
	
	int stop=1;
	while(1)
	{
		meum();
		choice(&stop,L);
		if(stop==0)
			break;
		printf("\n     下一步操作:");
		printf("\n     1.返回主界面");
		printf("\n     2.退出系统");
		printf("\n     请输入操作:");
		scanf("%d",&i);
		if(i==2)
			break;
	}
}



void meum()
{
	printf("\n   *****************************   \n");
	printf("         学生信息管理系统          \n");
	printf("   *****************************   \n");
	printf("           系统菜单功能            \n");
	printf("   *****************************   \n");
	printf("          1.查看学生信息           \n");
	printf("          2.添加学生信息           \n");
	printf("          3.删除学生信息           \n");
	printf("          4.修改学生信息           \n");
	printf("          5.保存学生信息           \n");
	printf("          6.刷新学生信息           \n");
	printf("          0.退出系统               \n");
}

void choice(int *stop,LinkList *L)
{
	int num;
	printf("\n\n          请输入菜单选项:");
	scanf("%d",&num);
	switch (num)
	{
		case 0: *stop=0; break;
		case 1: show_student(L); break;
		case 2: creat_node(L); break;
		case 3: delete_student(L); break;
		case 4: modify_student(L); break;
		case 5: save(L); break;
		case 6: refresh(L); break;
		default: printf("      请在0-6中间选择\n");
	}
}

void creat_node(LinkList *L)
{
  char name;
  LinkList *node=NULL;
  LinkList *temp=L->next;
  node=(LinkList *)malloc(sizeof(LinkList));
  if(node==NULL)
  {
    printf("分配普通节点内存出错!");
    exit(1);
  }
  memset(node,0,sizeof(LinkList));
  printf("\n请输入学生序号:");
  scanf("%d",&node->data.number);
  printf("\n请输入学生名:");
  scanf("%s",node->data.name);
  printf("\n请输入学生成绩:");
  scanf("%d",&node->data.score);
  printf("\n请输入学生年龄:");
  scanf("%d",&node->data.age);

  L->next=node;
  node->next=temp;
}

void show_student(LinkList *L)
{
	LinkList *p=L->next;
	int i=0;
	printf("\n    **************************      \n");
	printf("            学生信息                \n");
	printf("    **************************      \n");
	printf("   序号    姓名    成绩    年龄 \n");
	while(p)
	{
		printf("      %d      %s      %d      %d     \n",p->data.number,p->data.name,p->data.score,p->data.age);
		i++;
		p=p->next;
	}
}

void delete_student(LinkList *L)
{
	int x=0;
	int number;
	char name[10];
	LinkList *temp,*pre;
	temp=L->next;
	while(1)
	{
		printf("\n    请选择:");
  	printf("\n    1.按序号删除!");
  	printf("\n    2.按姓名删除!");
		printf("\n    请输入选择:");
	  scanf("%d",&x);
		if(x==1 || x==2)
			break;
		else 
			printf("\n   输入错误,请重新输入!");
	}
	if(x==1)
	{
		printf("\n    请输入要删除的学生序号:");
		scanf("%d",&number);
		while(temp->data.number!=number && temp->next!=NULL)
		{
			pre=temp;
			temp=temp->next;
		}
		if(temp->data.number==number)
		{
			pre->next=temp->next;
			free(temp);
		}
		else
		{
			printf("\n    没有所要删除的学生序号!");
		}
	}
	else if(x==2)
	{
		printf("\n     请输入要删除的学生名字:");
		scanf("%s",name);
		while(strcmp(temp->data.name,name)!=0 && temp->next!=NULL)
		{
			pre=temp;
			temp=temp->next;
		}
		if(strcmp(temp->data.name,name)==0)
		{
			pre->next=temp->next;
			free(temp);
		}
		else
		{
			printf("\n     没有要删除的学生姓名!");
		}
	}
}

void modify_student(LinkList *L)
{
	int x=0;
  int number;
  char name[10];
  LinkList *temp;
  temp=L->next;
  while(1)
  {
    printf("\n    请选择:");
    printf("\n    1.知道要修改学生的序号!");
    printf("\n    2.知道要修改学生的名字!");
    printf("\n    请输入选择:");
    scanf("%d",&x);
    if(x==1 || x==2)
      break;
    else 
      printf("\n   输入错误,请重新输入!");
  }
	if(x==1)
  {
    printf("\n    请输入要修改学生的序号:");
    scanf("%d",&number);
    while(temp->data.number!=number && temp->next!=NULL)
    {
      temp=temp->next;
    }
    if(temp->data.number==number)
    {
			printf("\n     已经找到要修改学生的信息!");
    }
    else
    {
      printf("\n    没有要修改学生的序号!");
    }
  }
	else if(x==2)
  {
    printf("\n     请输入要修改学生的名字:");
    scanf("%s",name);
    while(strcmp(temp->data.name,name)!=0 && temp->next!=NULL)
    {
      temp=temp->next;
    }
    if(strcmp(temp->data.name,name)==0)
    {
			printf("\n     已经找到要修改学生的信息!");
    }
    else
    {
      printf("\n     没有要修改学生的姓名!");
    }
  }
	printf("\n     ************************");
	printf("\n   姓名:%s  序号:%d  成绩:%d  年龄:%d",temp->data.name,temp->data.number,temp->data.score,temp->data.age);
	do{
		printf("\n     请选择:");
		printf("\n     1.修改序号!");
		printf("\n     2.修改名字!");
		printf("\n     3.修改成绩!");
		printf("\n     4.修改年龄!");
		printf("\n     请输入选择:");
		scanf("%d",&x);
	}while(x<1 || x>4);
	if(x==1)
	{
		printf("\n     请输入修改后的序号:");
		scanf("%d",&temp->data.number);
	}
	if(x==2)
	{
		printf("\n     请输入修改后的名字:");
		scanf("%s",temp->data.name);
	}
	if(x==3)
	{
		printf("\n     请输入修改后的成绩:");
		scanf("%d",&temp->data.score);
	}
	if(x==4)
	{
		printf("\n     请输入修改后的年龄:");
		scanf("%d",&temp->data.age);
	}

}

void save(LinkList *L)
{
	FILE *fp;
	int i=0;
	LinkList *temp;
	temp=L->next;
	if((fp=fopen("student.txt","a"))==NULL)
	{
		printf("\n     无法打开文件!");
		exit(1);
	}	
	while(temp!=NULL)
	{
		i++;
		fprintf(fp,"%d %s %d %d \n",temp->data.number,temp->data.name,temp->data.score,temp->data.age);
		printf("\n     第%d个已经保存!",i);
		temp=temp->next;
	}
	fclose(fp);
}

void refresh(LinkList *L)
{
	FILE *fp;
	LinkList *node=NULL;                                                          
  LinkList *temp=L->next;
  node=(LinkList *)malloc(sizeof(LinkList));
  if(node==NULL)
  {
    printf("分配普通节点内存出错!");
    exit(1);
  }
  memset(node,0,sizeof(LinkList));	
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("\n     无法打开文件!");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %d %d",&node->data.number,node->data.name,&node->data.score,&node->data.age);
		L->next=node;
		node->next=temp;
		temp=node;
		node=(LinkList *)malloc(sizeof(LinkList));
  	if(node==NULL)
  	{
    	printf("分配普通节点内存出错!");
    	exit(1);
  	}
  	memset(node,0,sizeof(LinkList));
	}
	printf("\n     已经成功刷新学生信息!");
}



